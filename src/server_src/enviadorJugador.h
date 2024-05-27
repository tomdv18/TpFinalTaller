#ifndef SERVER_ENVIADOR_JUGADOR_H_
#define SERVER_ENVIADOR_JUGADOR_H_


#include "protocoloServidor.h"
#include "../common_src/queue.h"
#include "../common_src/thread.h"

class EnviadorJugador : public Thread{
private:
    ProtocoloServidor *protocolo_servidor;

    Queue<Evento> *queue_jugador;

    uint32_t id;
    
public:
    EnviadorJugador(ProtocoloServidor *protocolo_servidor, Queue<Evento> *queue_jugador,uint32_t id);

    void run() override;

    ~EnviadorJugador() override;
};




#endif