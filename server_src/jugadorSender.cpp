#include "jugadorSender.h"
#define TAM_MAX_COLA 250


JugadorSender::JugadorSender(Protocolo & proto, std::atomic<bool> & sigue_jugando) : 
protocolo(proto),
sigue_jugando(sigue_jugando),
queue_evento(TAM_MAX_COLA)
{}



void JugadorSender::run(){
    while(sigue_jugando){
        try{
            /*
            evento evento = queue_evento.pop();
            protocolo.enviar(evento);
            ...*/
        } catch (const ClosedQueue& e) {
            break;
        }
        
    }
    sigue_jugando = false;
    
}
