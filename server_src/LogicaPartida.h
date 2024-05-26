#ifndef SERVER_LOGICA_PARTIDA_H_
#define SERVER_LOGICA_PARTIDA_H_


#include "../common_src/Accion.h"
#include "../common_src/Evento.h"
#include "Personaje.h"
#include <iostream>
#include <map>

class LogicaPartida{
private:

    std::map<uint32_t, Personaje*> map_personajes;


public:
    LogicaPartida();

    void ejecutar(Accion accion);

    void mover_derecha(uint32_t id_jugador);

    void mover_izquierda(uint32_t id_jugador);

    void agregar_personaje(Accion accion);

    void actualizar_partida();

    Evento obtener_snapshot();

    ~LogicaPartida();
};










#endif