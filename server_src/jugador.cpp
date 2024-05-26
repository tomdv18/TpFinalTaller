#include "jugador.h"
#include "RecibidorJugador.h"

Jugador::Jugador(uint32_t id, Socket skt, MonitorPartidas &monitor_partidas) : 
                    id(id),
                    protocolo_servidor(std::move(skt)),
                    queue_jugador(1000),
                    recibidor_jugador(&protocolo_servidor, &monitor_partidas, &queue_jugador, id),
                    esta_jugando(true){

    


    /*
        Antes de iniciar los hilos, espero el mensaje de crear o unirse
        En base a eso, obtengo una queue donde van a ir cargandose las acciones en el recibidor
        también, debo enviarle a la partida la cola donde mandar sus respuestas al jugador
        para luego hacer broadcast
    
    */
    recibidor_jugador.start();
}

bool Jugador::esta_vivo(){
    return recibidor_jugador.is_alive();
}


void Jugador::join(){
    recibidor_jugador.join();
    //enviador_jugador.join();
}

void Jugador::stop(){
    recibidor_jugador.stop();
    //enviador_jugador.stop();
}


Jugador::~Jugador(){
    
}