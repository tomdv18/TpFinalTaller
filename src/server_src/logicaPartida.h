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

    void ejecutar(Accion accion, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo);

    void mover_derecha(uint32_t id_jugador);

    void mover_izquierda(uint32_t id_jugador);

    void mover_arriba(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo);

    void mover_abajo(uint32_t id_jugador);

    void mover_quieto(uint32_t id_jugador);

    void mover_correr_rapido(uint32_t id_jugador);

    void mover_correr(uint32_t id_jugador);

    void abandonar_partida(uint32_t id_jugador);

    void agregar_personaje(Accion accion);

    void actualizar_partida(std::chrono::time_point<std::chrono::high_resolution_clock> tiempo);

    Evento obtener_snapshot(std::chrono::time_point<std::chrono::high_resolution_clock> start);

    ~LogicaPartida();
};










#endif