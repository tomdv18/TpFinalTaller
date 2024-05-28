#include "lobbyProtocolo.h"
#include <sys/socket.h>


LobbyProtocolo::LobbyProtocolo(Socket *skt) 
                : skt(skt){

}

uint8_t LobbyProtocolo::serializar_creacion_partida(uint8_t max_jugadores){
    bool was_closed = false;
    uint8_t accion = CREAR;
    uint8_t confirmacion;
    skt->sendall(&accion,sizeof(accion),&was_closed);
    skt->sendall(&max_jugadores,sizeof(max_jugadores),&was_closed);
    skt->recvall(&confirmacion,sizeof(confirmacion), &was_closed);
    
    return confirmacion;
}


uint8_t LobbyProtocolo::serializar_unirse_partida(uint32_t codigo_partida){
    bool was_closed = false;
    uint8_t accion = UNIRSE;
    uint8_t confirmacion;
    skt->sendall(&accion,sizeof(accion),&was_closed);
    skt->sendall(&codigo_partida,sizeof(codigo_partida),&was_closed);
    skt->recvall(&confirmacion,sizeof(confirmacion), &was_closed);
    
    return confirmacion;
}

void LobbyProtocolo::serializar_personaje(uint8_t personaje){
    bool was_closed = false;
    skt->sendall(&personaje,sizeof(personaje),&was_closed);
}


/*
void LobbyProtocolo::enviar_accion(uint8_t accion, bool& was_closed){
    skt.sendall(&accion,sizeof(accion),&was_closed);
    std::cout << "ENVIANDO " << (int) accion << std::endl;
    if(was_closed){
        throw std::runtime_error("Error, se cerro la conexion con el servidor");
    }

}

void LobbyProtocolo::enviar_jugadores(uint8_t jugadores, bool &was_closed){
    skt.sendall(&jugadores,sizeof(jugadores),&was_closed);
}

void LobbyProtocolo::enviar_id_partida(uint32_t id_partida, bool &was_closed){
    uint32_t id = htonl(id_partida);
    skt.sendall(&id,sizeof(id),&was_closed);
}


Evento LobbyProtocolo::recibir_evento(bool &was_closed){
    Evento evento;
    EventoPersonaje ev;

    //skt.recvall(&evento,sizeof(evento), &was_closed);
    uint8_t cant_personajes;
    skt.recvall(&cant_personajes,sizeof(cant_personajes),&was_closed);

    if(was_closed){
        throw std::runtime_error("Error, se cerro la conexion con el servidor");
    }

    std::vector<EventoPersonaje> eventos_personajes;
    for(int i = 0; i < cant_personajes; i++){
        skt.recvall(&ev,sizeof(ev), &was_closed);
        if(was_closed){
            throw std::runtime_error("Error, se cerro la conexion con el servidor");
        }
        eventos_personajes.emplace_back(ev);
    }
    
    evento.eventos_personaje = eventos_personajes;

    
        La idea es recibir la cantidad de personajes q hay
        Y hago recvall de eventos de personaje por esa cantidad

        Repetir lo mismo para los demas eventos e ir llenando el struct evento

        Separar todo eso en diferentes funciones
    
    
    
    return evento;
}

void LobbyProtocolo::close(){
    skt.shutdown(SHUT_RDWR);
    skt.close();
}

*/

LobbyProtocolo::~LobbyProtocolo(){
    
}

