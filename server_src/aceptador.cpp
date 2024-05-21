#include "aceptador.h"


Aceptador::Aceptador(const std::string &puerto, std::atomic<bool>& server_cerrado) : 
skt_accepter(puerto.c_str()),
aceptando(true),
server_cerrado(server_cerrado){}


void Aceptador::actualizar_jugadores(){

}

void Aceptador::detener_jugadores(){
    
}


void Aceptador::run(){
    while(aceptando){
        /*Esperando mensaje de salida*/
    }
    if (!aceptando){
        detener_jugadores();
    }
    
}

void Aceptador::stop() {
    aceptando = false;
    skt_accepter.shutdown(2);
    skt_accepter.close();
}