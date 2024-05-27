#include "lobbyProtocolo.h"
#include <sys/socket.h>


LobbyProtocolo::LobbyProtocolo(const std::string &hostname, const std::string &servname) 
                : skt(hostname.c_str(),servname.c_str()){

}

void LobbyProtocolo::enviar_accion(uint8_t accion, bool& was_closed){
    skt.sendall(&accion,sizeof(accion),&was_closed);

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

    /*
        La idea es recibir la cantidad de personajes q hay
        Y hago recvall de eventos de personaje por esa cantidad

        Repetir lo mismo para los demas eventos e ir llenando el struct evento

        Separar todo eso en diferentes funciones
    
    */
    
    return evento;
}

void LobbyProtocolo::close(){
    skt.shutdown(SHUT_RDWR);
    skt.close();
}

LobbyProtocolo::~LobbyProtocolo(){
    
}
