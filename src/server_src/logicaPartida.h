#ifndef SERVER_LOGICA_PARTIDA_H_
#define SERVER_LOGICA_PARTIDA_H_


#include "../common_src/accion.h"
#include "../common_src/evento.h"
#include "personaje.h"
#include <iostream>
#include <map>
#include <chrono>

class LogicaPartida{
private:

    std::map<uint32_t, Personaje*> map_personajes;


public:
    LogicaPartida();

    void ejecutar(Accion accion);

    void mover_derecha(uint32_t id_jugador);

    void mover_izquierda(uint32_t id_jugador);

    void mover_arriba(uint32_t id_jugador);

    void mover_abajo(uint32_t id_jugador);

    void abandonar_partida(uint32_t id_jugador);

    void agregar_personaje(Accion accion);

    void actualizar_partida();

    Evento obtener_snapshot(std::chrono::time_point<std::chrono::high_resolution_clock> start);

    ~LogicaPartida();
};










#endif