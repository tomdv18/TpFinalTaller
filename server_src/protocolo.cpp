#include "protocolo.h"
#define CREAR_PARTIDA 
#define UNIRSE_PARTIDA 


Protocolo::Protocolo(Socket socket) : 
    skt(std::move(socket))
{}


//Tal vez no deberia ser void
void Protocolo::handshake(){
    uint8_t tipo_partida;
    bool was_closed = false;
    skt.recvall(&tipo_partida, sizeof(uint8_t), &was_closed);
    if (was_closed) {
        //ERROR
        return;
    }
    if (tipo_partida == CREAR_PARTIDA){
        /*
            Crear una partida y devolver el codigo de la misma al cliente
        */

        
    } else if (tipo_partida == UNIRSE_PARTIDA){
        
        /*
        Buscar la partida dentro del juego,
        si esta intentar joinear
        SI no esta o no se pudo joinear devolver error, sino devolver exito
        
        */
        
    }
}

void Protocolo::enviar(){

}

void Protocolo::recibir(){

}
void Protocolo::cerrar(){
    skt.shutdown(2);
    skt.close();
}
