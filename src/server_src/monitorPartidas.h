#ifndef SERVER_MONITOR_PARTIDAS_H_
#define SERVER_MONITOR_PARTIDAS_H_

#include <map>
#include "../common_src/accion.h"
#include "../common_src/queue.h"
#include "partida.h"

class Partida;

class MonitorPartidas{
private:
    
    std::map<uint32_t, Partida*> partidas;

    uint32_t contador_partidas;

public:
    MonitorPartidas();

    Queue<Accion>* crear_partida(uint32_t id_creador,uint8_t cant_jugadores, Queue<Evento> *queue_jugador);

    Queue<Accion>* unir_jugador(uint32_t id_jugador, uint32_t id_partida, Queue<Evento> *queue_jugador);

    void listar_partidas();

    void borrar_jugador(uint32_t id_jugador);

    std::map<uint32_t, Partida*> obtener_partidas();

    void borrar_partidas();

    // borrar_partida
    // borrar_partidas

    ~MonitorPartidas();
};





#endif
