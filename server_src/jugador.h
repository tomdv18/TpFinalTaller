#ifndef SERVER_JUGADOR_H_
#define SERVER_JUGADOR_H_

#include <string>
#include <iostream>
#include <atomic>
#include "thread.h"
#include "../common_src/socket.h"
#include "jugadorReceiver.h"
#include "jugadorSender.h"

class Jugador: public Thread{
private:
    std::atomic<bool> sigue_jugando;
    //Personaje personaje;
    int id_jugador;
    Protocolo protocolo;
    JugadorReceiver receiver;
    JugadorSender sender;

    
public:
    explicit Jugador(Socket skt, int id);
    bool esta_vivo();
    void run() override;
    void stop();

    Jugador(const Jugador&) = delete;
    Jugador& operator = (const Jugador&) = delete;
    Jugador(Jugador&&) = default;
    Jugador& operator=(Jugador&&) = default;

};


#endif