#include "lobby.h"


Lobby::Lobby(const std::string &hostname, const std::string &servname) :
                    lobby_protocolo(hostname,servname)
                    , recibidor_lobby(&lobby_protocolo){}


void Lobby::procesar_lobby(bool &was_closed, bool &jugando){
    
        std::string input;
        std::getline(std::cin,input);
        std::istringstream iss(input);
        std::string accion_string;
        iss >> accion_string;

        if(accion_string == "CREAR"){
            int jugadores;
            if (iss >> jugadores) {
                lobby_protocolo.enviar_accion(CREAR, was_closed);
                lobby_protocolo.enviar_jugadores((uint8_t) jugadores, was_closed);
                jugando = true;
            } else{
                std::cout << "Error, CREAR <cantidad jugadores>" << std::endl;
            }

        } else if(accion_string == "UNIRSE"){
            int id_partida;
            if (iss >> id_partida) {
                lobby_protocolo.enviar_accion(UNIRSE, was_closed);
                lobby_protocolo.enviar_id_partida((uint32_t) id_partida, was_closed);
                jugando = true;
            } else{
                std::cout << "Error, UNIRSE <id partida>" << std::endl;
            }
        } else if(accion_string == "PARTIDAS"){
            //lobby_protocolo.enviar_accion(LIST_P, was_closed);
        } else if(accion_string == "SALIR"){
            lobby_protocolo.enviar_accion(SALIR, was_closed);
            throw std::runtime_error("");
        }
    


    
}

void Lobby::main(){

    bool was_closed = false;
    bool jugando = false;
    char codigo;
    recibidor_lobby.start();
    while(true){
        try{
            procesar_lobby(was_closed, jugando);
            
            while(jugando){
                codigo = getc(stdin);
                getc(stdin);
                lobby_protocolo.enviar_accion(codigo, was_closed);
               
               if(codigo == LOBBY){
                    jugando = false;
                    break;
               }
            }

        } catch(std::runtime_error &e){
            break;
        }

    }

    lobby_protocolo.close();
    recibidor_lobby.join();

}
