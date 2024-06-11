#include "recibidorLobby.h"

RecibidorLobby::RecibidorLobby(LobbyProtocolo *lobby_protocolo) : lobby_protocolo(lobby_protocolo){}




void RecibidorLobby::run(){
    /*
    bool was_closed = false;
    while(_keep_running){
        Evento evento;
        try{
            evento = lobby_protocolo->recibir_evento(was_closed);    
        }catch(std::runtime_error &err){
            break;
        }
        //std::cout << "\nEl jugador " << (int) accion.id_jugador << " realizo la accion " << accion.codigo << std::endl;
        
        for(EventoPersonaje p: evento.eventos_personaje){
            std::cout << "PERSONAJE DE " << p.id_jugador << std::endl;
            std::cout << "VIDA " << p.vida << std::endl;
            std::cout << "EN LA POSICION " << "(" << p.posicion_x << "," << p.posicion_y << ")" << std::endl;
        }
        
    }
    */
}


RecibidorLobby::~RecibidorLobby(){

}