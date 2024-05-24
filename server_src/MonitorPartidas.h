#ifndef SERVER_MONITOR_PARTIDAS_H_
#define SERVER_MONITOR_PARTIDAS_H_

#include <map>
#include "../common_src/Accion.h"
#include "../common_src/queue.h"
#include "Partida.h"

class Partida;

class MonitorPartidas{
private:
    
    std::map<uint32_t, Partida*> partidas;

public:
    MonitorPartidas();

    Queue<Accion>* crear_partida(uint32_t id_creador,uint8_t cant_jugadores, Queue<Accion> *queue_jugador);

    Queue<Accion>* unir_jugador(uint32_t id_jugador, uint32_t id_partida, Queue<Accion> *queue_jugador);

    void listar_partidas();

    void borrar_jugador(uint32_t id_jugador);


    std::map<uint32_t, Partida*> obtener_partidas();

    // borrar_partida
    // borrar_jugador
    // borrar_partidas

    ~MonitorPartidas();
};





#endif
