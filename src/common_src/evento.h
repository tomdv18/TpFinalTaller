#ifndef COMMON_EVENTO_H_
#define COMMON_EVENTO_H_

#include <iostream>
#include <vector>
struct __attribute__((packed)) EventoPersonaje{

    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    uint8_t id_personaje;
    uint8_t esta_quieto;
    uint8_t esta_corriendo;
    uint8_t usando_habilidad;
    uint8_t esta_saltando;

};

struct Evento{
    uint16_t tiempo_restante;
    std::vector<EventoPersonaje> eventos_personaje;
};

#endif