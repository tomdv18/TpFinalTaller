#ifndef SERVER_PERSONAJE_H_
#define SERVER_PERSONAJE_H_

#include <iostream>
#include <cmath>
#include <chrono>


class Personaje{
private:
    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    bool esta_quieto;

    double velocidad_x;
    double velocidad_y;

    bool corriendo;

    bool saltando;
    double tiempo_salto;

public:
    Personaje(uint32_t id_jugador);

    //Acciones

    void mover_derecha();

    void mover_izquierda();

    void mover_arriba(std::chrono::duration<double> tiempo_transcurrido);

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

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido);

    ~Personaje();
};

#endif