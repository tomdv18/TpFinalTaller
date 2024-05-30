#include "protocolo_cliente.h"

#include <vector>

#include <netinet/in.h>

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

    std::vector<EventoPersonaje> eventos_personajes;
    for(int i = 0; i < cant_personajes; i++){
        skt.recvall(&event_personaje, sizeof(event_personaje), &was_closed);
        if(was_closed){
            return !was_closed;
        }
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

