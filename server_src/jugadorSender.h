#ifndef SERVER_JUGADOR_SENDER_H_
#define SERVER_JUGADOR_SENDER_H_

#include <atomic>
#include "thread.h"
#include "queue.h"
#include "../common_src/socket.h"

struct Evento{ 
//CREADO COMO EJEMPLO DEBERIA ESTAR DEFINIDO EN OTRO LADO
};

class JugadorSender: public Thread{
private:
    //Protocolo & protocolo;
    Queue<Evento> queue_evento;
    std::atomic<bool> & sigue_jugando;
    
public:
    explicit JugadorSender(/*Protocolo & protocolo,*/  std::atomic<bool> & sigue_jugando);
    void run() override;
    void stop();

    JugadorSender(const JugadorSender&) = delete;
    JugadorSender& operator = (const JugadorSender&) = delete;
    JugadorSender(JugadorSender&&) = default;
    JugadorSender& operator=(JugadorSender&&) = default;

};


#endif