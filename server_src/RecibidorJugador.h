#ifndef SERVER_RECIBIDOR_JUGADOR_H_
#define SERVER_RECIBIDOR_JUGADOR_H_


#include "../common_src/thread.h"
#include "../common_src/socket.h"
#include "../common_src/queue.h"
#include "../common_src/Accion.h"
#include "../common_src/Evento.h"
#include "ProtocoloServidor.h"
#include "MonitorPartidas.h"
#include "EnviadorJugador.h"
#include <memory>

class MonitorPartidas;

class RecibidorJugador : public Thread{
private:
    ProtocoloServidor *protocolo_servidor;

    MonitorPartidas *monitor_partidas;

    Queue<Accion> *queue_acciones;

    Queue<Evento> *queue_jugador;

    EnviadorJugador enviador_jugador;

    uint32_t id;

public:

    RecibidorJugador(ProtocoloServidor *protocolo_servidor, MonitorPartidas *monitor_partidas, Queue<Evento> *queue_jugador,int id);

    void run() override;

    void leer_lobby(bool &partida_encontrada, bool &was_closed);

    void join_enviador();

    ~RecibidorJugador() override;

};







#endif