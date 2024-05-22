#ifndef SERVER_JUGADOR_H_
#define SERVER_JUGADOR_H_

#include "../common_src/socket.h"
#include "../common_src/thread.h"
#include "RecibidorJugador.h"
#include "EnviadorJugador.h"

class MonitorPartidas;

class Jugador{
private:
    uint32_t id;

    ProtocoloServidor protocolo_servidor;

    Queue<Accion> queue_jugador;

    RecibidorJugador recibidor_jugador;

    //EnviadorJugador enviador_jugador;

    std::atomic<bool> esta_jugando;

public:
    Jugador(uint32_t id, Socket skt, MonitorPartidas &monitor_partidas);

    bool esta_vivo();

    void join();

    void stop();

    ~Jugador();
};




#endif