#ifndef SERVER_OBJETO_H_
#define SERVER_OBJETO_H_

#include <chrono>
#include <cmath>
#include <iostream>

#include "../common_src/accion.h"

#include "personaje.h"

enum CodigoObjeto : uint8_t { ZANAHORIA, SOLIDO };

class Personaje;

class Objeto {
protected:
    uint32_t id_objeto;

    uint32_t posicion_x;

    uint32_t posicion_y;

    uint32_t ancho;
    uint32_t alto;

    double tiempo_reaparicion;

    double tiempo_interaccion;

    bool mostrar;

public:
    Objeto(uint32_t id_objeto, uint32_t posicion_x, uint32_t posicion_y, double tiempo_reaparicion,
           uint32_t ancho, uint32_t alto);

    // Getters Snapshot

    virtual uint32_t obtener_id();

    virtual uint32_t obtener_posicionX();

    virtual uint32_t obtener_posicionY();

    virtual uint32_t obtener_ancho();

    virtual uint32_t obtener_alto();

    virtual bool obtener_mostrar();

    virtual void reaparecer(std::chrono::duration<double> tiempo_transcurrido);

    virtual ~Objeto();

    // Metodos virtuales para los diferentes objetos

    virtual uint8_t obtener_objeto() = 0;

    virtual void interactuar_personaje(Personaje* personaje,
                                       std::chrono::duration<double> tiempo_transcurrido) = 0;
};


#endif