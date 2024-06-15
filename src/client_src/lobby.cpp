#include "lobby.h"


Lobby::Lobby(const std::string &hostname, const std::string &servname) :
                    skt(hostname.c_str(),servname.c_str()),
                    lobby_protocolo(&skt),
                    recibidor_lobby(&lobby_protocolo){
                        
}

bool Lobby::crear_partida(uint8_t max_jugadores){
    return (lobby_protocolo.serializar_creacion_partida(max_jugadores) == EXITO);
}

bool Lobby::unirse_partida(uint32_t codigo_partida){
    return (lobby_protocolo.serializar_unirse_partida(codigo_partida) == EXITO);
}

void Lobby::elegir_personaje(uint8_t personaje){
    lobby_protocolo.serializar_personaje(personaje);
}

Socket& Lobby::obtener_socket(){
    return skt;
}

void Lobby::close(){
    skt.shutdown(SHUT_RDWR);
    skt.close();
}

std::vector<InfoPartida> Lobby::obtener_partidas(){
    
    return lobby_protocolo.obtener_partidas();
}