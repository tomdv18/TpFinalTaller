#ifndef SERVER_PERSONAJE_H_
#define SERVER_PERSONAJE_H_

#include <iostream>

class Personaje{
private:
    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    uint8_t esta_quieto;

public:
    Personaje(uint32_t id_jugador);

    void mover_derecha();

    void mover_izquierda();

    void mover_arriba();

    void mover_abajo();

    void quedarse_quieto();

    uint32_t obtener_posicionX();

    uint32_t obtener_posicionY();

    uint8_t obtener_vida();

    uint8_t obtener_movimiento();

    ~Personaje();
};

#endif