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

/*
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
    bool jugando = true;
    char codigo;
    recibidor_lobby.start();
    while(true){
        try{
            //procesar_lobby(was_closed, jugando);
            
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
*/
