#ifndef COMMON_ACCION_H_
#define COMMON_ACCION_H_

#include <iostream>

enum CodigoAccion : char{
    CREAR = 'C',    // 0
    UNIRSE = 'U',   // 1
    SALIR = 'S',    // 2
    ATACAR = 'A',   // 3
    LOBBY = 'L',
    LIST_P = 'P'
};

struct __attribute__((packed)) Accion{
    char codigo;
    uint32_t id_jugador;
};


struct __attribute__((packed)) InfoPartida{
    char codigo = LIST_P;
    uint32_t id_partida;
    uint8_t jugadores;
    uint8_t max_jugadores;
};


#endif