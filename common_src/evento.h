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


#endif