<<<<<<< HEAD:src/common_src/evento.h
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












=======
#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include "accion_juego.h"

// Representa el evento producido en el servidor
struct Evento{
    // Tendria que tener una estructura del tipo
    // ID: 1, pos = 3, etc... (como lo vimos en la reunion)

    // Ver cuando unimos con el servidor, por ahora, es la accion del juego que
    // envio el cliente.
    AccionJuego accion_juego;
};


>>>>>>> main:common_src/evento.h
#endif