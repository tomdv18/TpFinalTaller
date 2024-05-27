#ifndef COMMON_ACCION_H_
#define COMMON_ACCION_H_

#include <iostream>


// Acciones posibles del jugador
enum CodigoAccion : uint8_t{
    CREAR = 'C',    // Crear una partida
    UNIRSE = 'U',   // Unirse a una partida
    SALIR = 'Q',    // Salir del lobby, cerrar juego
    DISPARAR = 'K',   // Jugador dispara
    SALTAR = 'W',     // Jugador salta
    DERECHA = 'D',    // Jugador se mueve a derecha
    IZQUIERDA = 'A',  // Jugador se mueve a izquierda
    RECARGAR = 'R',   // Jugador Recarga el arma
    CORRER = 'J',     // JUgador corre
    CORRER_RAPIDO = 'L',  // Jugador corre rapido
    ESPECIAL = 'I',    // Jugador usa habilidad especial
    LOBBY = 'T',    // Volver al lobby


    JAZZ = '1', 
    SPAZ = '2',
    LORI = '3',


    LIST_P = 'P'   // Posible lista de partidas
};



// Struct tipo de acciones del jugador
struct __attribute__((packed)) Accion{
    uint8_t codigo;
    uint32_t id_jugador;
};


// Struct para obtener info de la partida
struct __attribute__((packed)) InfoPartida{
    char codigo = LIST_P;
    uint32_t id_partida;
    uint8_t jugadores;
    uint8_t max_jugadores;
};


#endif