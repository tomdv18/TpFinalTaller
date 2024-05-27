#include "proyectil.h"

Proyectil::Proyectil(int danio, int velocidad_proyectil) : danio(danio), velocidad_proyectil(velocidad_proyectil){}

Coordenadas Proyectil::get_coordenadas() {
    return this->coordenadas;
}

int Proyectil::get_danio() {
    return this->danio;
}

int Proyectil::get_velocidad_proyectil() {
    return this->velocidad_proyectil;
}