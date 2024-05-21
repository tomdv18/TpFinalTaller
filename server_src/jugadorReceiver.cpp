#include "jugadorReceiver.h"
#define TAM_MAX_COLA 250


JugadorReceiver::JugadorReceiver(/*Protocolo & proto,*/ std::atomic<bool> & sigue_jugando) : 
//protocolo(proto),
sigue_jugando(sigue_jugando),
queue_accion(TAM_MAX_COLA)
{}



void JugadorReceiver::run(){
    while(sigue_jugando){
        try{
            /*protocolo.recibir();
            ...*/
        } catch (const ClosedQueue& e) {
            break;
        }
        
    }
    
}


void JugadorReceiver::stop(){
    sigue_jugando = false;
}