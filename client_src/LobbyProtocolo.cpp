#include "LobbyProtocolo.h"
#include "../common_src/Accion.h"
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


Accion LobbyProtocolo::recibir_accion(bool &was_closed){
    Accion accion;
    skt.recvall(&accion,sizeof(accion), &was_closed);

    if(was_closed){
        throw std::runtime_error("Error, se cerro la conexion con el servidor");
    }
    
    return accion;
}

void LobbyProtocolo::close(){
    skt.shutdown(SHUT_RDWR);
    skt.close();
}

LobbyProtocolo::~LobbyProtocolo(){
    
}
