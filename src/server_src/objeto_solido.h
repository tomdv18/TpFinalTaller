#ifndef SERVER_OBJETO_SOLIDO_H_
#define SERVER_OBJETO_SOLIDO_H_

#include <iostream>
#include <cmath>
#include <chrono>
#include "../common_src/accion.h"
#include "objeto.h"

class Solido : public Objeto{


public:
    Solido(uint32_t id_objeto, uint32_t posicion_x, uint32_t posicion_y, double tiempo_reaparicion, uint32_t ancho, uint32_t alto);

    virtual uint8_t obtener_objeto() override;

    virtual void interactuar_personaje(Personaje *personaje, std::chrono::duration<double> tiempo_transcurrido) override;


};


#endif