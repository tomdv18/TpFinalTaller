#ifndef SERVER_PARTIDA_H_
#define SERVER_PARTIDA_H_

#include "../common_src/queue.h"
#include "../common_src/Accion.h"
#include "../common_src/thread.h"
#include <iostream>
#include <map>
#include <list>

class Partida : public Thread{
private:
    uint32_t id;

    uint32_t id_creador;

    uint8_t max_jugadores;

    Queue<Accion> queue_acciones;

    std::map<uint32_t, Queue<Accion>*> map_jugadores;

    std::mutex m;

public:
    Partida(uint32_t id_creador, uint8_t max_jugadores, uint32_t id, Queue<Accion> *queue_jugador);

    Queue<Accion>* obtener_queue();

    void listar_jugadores();

    Queue<Accion>* unir_jugador(uint32_t id_jugador, Queue<Accion> *queue_jugador);

    bool borrar_jugador(uint32_t id_jugador);

    void run() override;

    ~Partida() override;
};








#endif