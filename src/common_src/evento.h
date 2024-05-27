#ifndef COMMON_EVENTO_H_
#define COMMON_EVENTO_H_

#include <iostream>
#include <vector>
struct __attribute__((packed)) EventoPersonaje{

    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;

};

struct Evento{
    std::vector<EventoPersonaje> eventos_personaje;
};

#endif