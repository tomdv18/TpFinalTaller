#ifndef SERVER_PERSONAJE_H_
#define SERVER_PERSONAJE_H_

#include <iostream>
#include <cmath>


class Personaje{
private:
    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    uint8_t esta_quieto;

    int velocidad_x;
    int velocidad_y;

    bool corriendo;

public:
    Personaje(uint32_t id_jugador);

    //Acciones

    void mover_derecha();

    void mover_izquierda();

    void mover_arriba();

    void mover_abajo();

    void quedarse_quieto();

    void correr_rapido();

    void correr();

    //Acciones

    // Getters Snapshot
    uint32_t obtener_posicionX();

    uint32_t obtener_posicionY();

    uint8_t obtener_vida();

    uint8_t obtener_movimiento();

    uint8_t obtener_corriendo();

    // Getters Snapshot

    void actualizar_posicion(double tiempo);

    ~Personaje();
};

#endif