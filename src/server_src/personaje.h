#ifndef SERVER_PERSONAJE_H_
#define SERVER_PERSONAJE_H_

#include <iostream>
#include <cmath>
#include <chrono>
#include "../common_src/accion.h"


#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50
#define VELOCIDAD 5
#define VELOCIDAD_SALTO 25
#define GRAVEDAD 3
#define ENFRIAMIENTO_JAZZ 5
#define ENFRIAMIENTO_LORI 5
#define ENFRIAMIENTO_SPAZ 5

class Personaje{
protected:
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

    bool usando_especial;
    double tiempo_especial;

    uint8_t direccion_mirando;

public:
    Personaje(uint32_t id_jugador);

    //Acciones

    virtual void mover_derecha();

    virtual void mover_izquierda();

    virtual void mover_arriba(std::chrono::duration<double> tiempo_transcurrido);

    virtual void mover_abajo();

    virtual void quedarse_quieto();

    virtual void correr_rapido();

    virtual void correr();

    //Acciones

    // Getters Snapshot
    virtual uint32_t obtener_posicionX();

    virtual uint32_t obtener_posicionY();

    virtual uint8_t obtener_vida();

    virtual uint8_t obtener_movimiento();

    virtual uint8_t obtener_corriendo();

    virtual uint8_t obtener_habilidad();

    virtual uint8_t obtener_saltando();

    // Getters Snapshot

    virtual void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido);

    virtual ~Personaje();

    // Metodos virtuales para los diferentes personajes

    virtual uint8_t obtener_personaje() = 0;

    virtual void usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) = 0;
};

#endif