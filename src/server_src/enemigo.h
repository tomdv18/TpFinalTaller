#ifndef SERVER_ENEMIGO_H_
#define SERVER_ENEMIGO_H_

#include <iostream>
#include <cmath>
#include <chrono>
#include "../common_src/accion.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50
#define VELOCIDAD 5

class Enemigo{
protected:
    uint32_t id_enemigo;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    bool esta_quieto;


    double velocidad_x;
    uint8_t direccion_mirando;
    bool esta_vivo;
    int iteraciones_para_revivir;
    
    int pasos_patrullando;

    virtual void mover_derecha();

    virtual void mover_izquierda(); 

    virtual void patrullar();

public:
    Enemigo(uint32_t id_enemigo);

    //Acciones
    virtual void quedarse_quieto();

    virtual void moverse();

    //Acciones

    // Getters Snapshot
    virtual uint32_t obtener_posicionX();

    virtual uint32_t obtener_posicionY();

    virtual uint8_t obtener_vida();

    virtual uint8_t obtener_movimiento();


    // Getters Snapshot

    virtual void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido);

    virtual ~Enemigo();

    // Metodos virtuales para los diferentes personajes enemigos

    virtual uint8_t obtener_personaje() = 0;

};

#endif