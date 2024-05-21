#ifndef SERVER_JUGADOR_RECEIVER_H_
#define SERVER_JUGADOR_RECEIVER_H_

#include <iostream>
#include <atomic>
#include "thread.h"
#include "queue.h"
#include "../common_src/socket.h"
#include "protocolo.h"

struct Accion{ 
//CREADO COMO EJEMPLO DEBERIA ESTAR DEFINIDO EN OTRO LADO
};

class JugadorReceiver: public Thread{
private:
    Protocolo & protocolo;
    Queue<Accion> queue_accion;
    std::atomic<bool> & sigue_jugando;
    
public:
    explicit JugadorReceiver(Protocolo & protocolo,  std::atomic<bool> & sigue_jugando);
    void run() override;
    void stop();

    JugadorReceiver(const JugadorReceiver&) = delete;
    JugadorReceiver& operator = (const JugadorReceiver&) = delete;
    JugadorReceiver(JugadorReceiver&&) = default;
    JugadorReceiver& operator=(JugadorReceiver&&) = default;

};


#endif