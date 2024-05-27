#include "personaje.h"

Personaje::Personaje() : coordenada_x(0), coordenada_y(0) {}

int Personaje::get_coordenada_x() {
    return coordenada_x;
}

int Personaje::get_coordenada_y() {
    return coordenada_y;
}

void Personaje::set_coordenada_x(int coordenada_x) {
    this->coordenada_x = coordenada_x;
}

void Personaje::set_coordenada_y(int coordenada_y) {
    this->coordenada_y = coordenada_y;
}