#include "EnviadorJugador.h"


EnviadorJugador::EnviadorJugador(ProtocoloServidor *protocolo_servidor, Queue<Evento> *queue_jugador,uint32_t id) :
            protocolo_servidor(protocolo_servidor),
            queue_jugador(queue_jugador),
            id(id){

}


void EnviadorJugador::run(){
   
    bool was_closed = false;
    while(_keep_running){
        try{
            try{
                Evento evento = queue_jugador->pop();
                protocolo_servidor->enviar_evento(was_closed,evento);
            } catch(const ClosedQueue &err){
                //Se cerro la queue del jugador, salio de la partida
                //Se cerro el socket, se perdio la conexion
                break;
            }
        }catch(std::runtime_error &err){
            break;
        }
    }

}


EnviadorJugador::~EnviadorJugador(){
    
}