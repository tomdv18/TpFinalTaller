#ifndef SERVER_ACEPTADOR_H_
#define SERVER_ACEPTADOR_H_

#include <string>
#include <iostream>
#include <atomic>
#include "../common_src/socket.h"
#include "thread.h"

class Aceptador: public Thread{
private:
    Socket skt_accepter;    
    std::atomic<bool>& server_cerrado;
    std::atomic<bool> aceptando;

    void actualizar_jugadores();
    void detener_jugadores();

public:
    explicit Aceptador(const std::string &puerto, std::atomic<bool>& server_cerrado);

    void run() override;

    void stop();

    /*Move Semantics*/
    Aceptador(const Aceptador&) = delete;
    Aceptador& operator = (const Aceptador&) = delete;

    Aceptador(Aceptador&&) = default;
    Aceptador& operator=(Aceptador&&) = default;

};


#endif