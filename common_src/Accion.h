#ifndef COMMON_ACCION_H_
#define COMMON_ACCION_H_

#include <iostream>

enum CodigoAccion : char{
    CREAR = 'C',    // 0
    UNIRSE = 'U',   // 1
    SALIR = 'S',    // 2
    ATACAR = 'A',   // 3
    LOBBY = 'L'
};

struct __attribute__((packed)) Accion{
    char codigo;
    uint32_t id_jugador;
};


#endif