#ifndef ARMA_H
#define ARMA_H

#include <string>
#include "proyectil.h"

class Arma {

    protected:

    std::string nombre;
    int cantidad_municion;
    int velocidad_disparo;
    Proyectil proyectil;

    public:

    explicit Arma(std::string nombre, int danio, int velocidad_disparo, int velocidad_proyectil, int cantidad_municion);

    std::string get_nombre_arma();

    int get_velocidad_disparo();

    Proyectil get_proyectil();

    void aumentar_cantidad_municion(int &cantidad_municion);
};

#endif
