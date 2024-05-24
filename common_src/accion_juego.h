#ifndef ACCION_JUEGO_H
#define ACCION_JUEGO_H

// Representacion de las acciones que tendra el cliente una vez jugando.
enum AccionJuego: uint8_t {
    NULO,
    IZQUIERDA,    // 0
    DERECHA,
    ARRIBA,
    ABAJO,
    SALTAR,
    ATACAR,
    SUPERPODER,
    CAMBIAR_ARMA,
    CORRER,
    DISPARAR,
    SALIR,
    NINGUNA // Temporal...
    //etc
};

#endif