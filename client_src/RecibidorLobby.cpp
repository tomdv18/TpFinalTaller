#include "RecibidorLobby.h"

RecibidorLobby::RecibidorLobby(LobbyProtocolo *lobby_protocolo) : lobby_protocolo(lobby_protocolo){}




void RecibidorLobby::run(){
    bool was_closed = false;
    while(_keep_running){
        Accion accion;
        try{
            accion = lobby_protocolo->recibir_accion(was_closed);    
        }catch(std::runtime_error &err){
            break;
        }
        std::cout << "\nEl jugador " << (int) accion.id_jugador << " realizo la accion " << accion.codigo << std::endl;

    }
}


RecibidorLobby::~RecibidorLobby(){

}