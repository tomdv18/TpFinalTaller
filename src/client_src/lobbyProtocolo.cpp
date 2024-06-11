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
    codigo_partida = htonl(codigo_partida);
    skt->sendall(&accion,sizeof(accion),&was_closed);
    skt->sendall(&codigo_partida,sizeof(codigo_partida),&was_closed);
    skt->recvall(&confirmacion,sizeof(confirmacion), &was_closed);
    
    return confirmacion;
}

void LobbyProtocolo::serializar_personaje(uint8_t personaje){
    bool was_closed = false;
    skt->sendall(&personaje,sizeof(personaje),&was_closed);
}

std::vector<InfoPartida> LobbyProtocolo::obtener_partidas(){
    bool was_closed = false;
    uint8_t accion = LIST_P;
    std::vector<InfoPartida> info_partidas;
    InfoPartida info_partida;

    skt->sendall(&accion,sizeof(accion),&was_closed);
    uint32_t cantidad_partidas;
    skt->recvall(&cantidad_partidas, sizeof(uint32_t), &was_closed); // Recibir tamaño de partidas
    cantidad_partidas = ntohl(cantidad_partidas); // Convertir a host byte order
    
    
    for(int i = 0; i < cantidad_partidas; i++){

        skt->recvall(&info_partida, sizeof(info_partida), &was_closed);
        info_partida.id_partida = ntohl(info_partida.id_partida);
        info_partida.id_creador = ntohl(info_partida.id_creador);
        std::cout << "ID PARTIDA " << info_partida.id_partida << std::endl;
        std::cout << "ID CREADOR " << info_partida.id_creador << std::endl;
        std::cout << "JUGADORES " << (int) info_partida.jugadores << std::endl;
        std::cout << "MAX JUGADORES " << (int) info_partida.max_jugadores << std::endl;
        info_partidas.emplace_back(info_partida);
    }
    

    return info_partidas;
}

LobbyProtocolo::~LobbyProtocolo(){
    
}

