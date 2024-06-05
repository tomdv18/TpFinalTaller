#include "protocolo_cliente.h"

#include <vector>

#include <netinet/in.h>
#include <arpa/inet.h>
ProtocoloCliente::ProtocoloCliente(Socket &skt):
skt(skt)
{}

/*
static uint8_t serializar(AccionJuego& accion_juego) {
    return static_cast<uint8_t>(accion_juego);
}
*/

bool ProtocoloCliente::enviar_accion_juego(uint8_t accion_juego) {
    bool was_closed = false;
    skt.sendall(&accion_juego, sizeof(accion_juego), &was_closed);

    return !was_closed;
}

MapaEntidades ProtocoloCliente::recibir_mapa() {
    uint32_t cantidad_piezas;
    bool was_closed;
    skt.recvall(&cantidad_piezas, sizeof(cantidad_piezas), &was_closed);
    cantidad_piezas = ntohl(cantidad_piezas);

    MapaEntidades map;
    recibir_entidad(cantidad_piezas, map);
    return map;
}

void ProtocoloCliente::recibir_entidad(uint32_t cantidad_piezas, MapaEntidades& map) {
    bool was_closed;
    for (size_t i = 0; i < cantidad_piezas; i++) {
        uint8_t tipo;
        skt.recvall(&tipo, sizeof(tipo), &was_closed);

        uint32_t cantidad_tipo;
        skt.recvall(&cantidad_tipo, sizeof(cantidad_tipo), &was_closed);
        cantidad_tipo = ntohl(cantidad_tipo);

        std::vector<Position> posiciones(cantidad_tipo);
        recibir_posiciones(cantidad_tipo, posiciones, was_closed);

        std::string clave = determinar_tipo(tipo);
        map[clave] = posiciones;
    }
}

void ProtocoloCliente::recibir_posiciones(uint32_t cantidad_tipo, std::vector<Position>& posiciones, bool& was_closed) {
    for (size_t i = 0; i < cantidad_tipo; i++) {
        Position posicion;
        skt.recvall(&posicion, sizeof(posicion), &was_closed);
        posiciones[i] = posicion;
    }
}

std::string ProtocoloCliente::determinar_tipo(uint8_t tipo) {
    if (tipo == PISO) {
        return "piso";
    } else if (tipo == PARED) {
        return "pared";
    } 
    return "unknown";
}


// Ver como recibir el evento final

bool ProtocoloCliente::recibir_evento(Evento &evento) {
    bool was_closed = false;
    EventoPersonaje event_personaje;

    //skt.recvall(&evento,sizeof(evento), &was_closed);
    uint8_t cant_personajes;
    skt.recvall(&cant_personajes,sizeof(cant_personajes),&was_closed);
    if(was_closed){
        return !was_closed;
    }

    uint16_t tiempo_restante;
    skt.recvall(&tiempo_restante,sizeof(uint16_t),&was_closed);
    if(was_closed){
        return !was_closed;
    }
    uint16_t tiempo_nativo = ntohs(tiempo_restante);
    evento.tiempo_restante = tiempo_nativo;

    std::vector<EventoPersonaje> eventos_personajes;
    for(int i = 0; i < cant_personajes; i++){
        skt.recvall(&event_personaje, sizeof(event_personaje), &was_closed);
        if(was_closed){
            return !was_closed;
        }
        event_personaje.id_jugador = ntohl(event_personaje.id_jugador);
        event_personaje.posicion_x = ntohl(event_personaje.posicion_x);
        event_personaje.posicion_y = ntohl(event_personaje.posicion_y);
        eventos_personajes.emplace_back(event_personaje);
    }
    
    evento.eventos_personaje = eventos_personajes;

    /*
        La idea es recibir la cantidad de personajes q hay
        Y hago recvall de eventos de personaje por esa cantidad

        Repetir lo mismo para los demas eventos e ir llenando el struct evento

        Separar todo eso en diferentes funciones
    
    */

    return !was_closed;
}

