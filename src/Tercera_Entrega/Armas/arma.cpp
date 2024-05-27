#include "arma.h"

Arma::Arma(std::string nombre, int danio, int velocidad_disparo, 
int velocidad_proyectil, int cantidad_municion) : nombre(nombre), velocidad_disparo(velocidad_disparo),
cantidad_municion(cantidad_municion), proyectil(danio, velocidad_proyectil) {}

std::string Arma::get_nombre_arma() {
    return this->nombre;
}

int Arma::get_velocidad_disparo() {
    return this->velocidad_disparo;
}

Proyectil Arma::get_proyectil() {
    return this->proyectil;
}

void Arma::aumentar_cantidad_municion(int &cantidad_municion) {
    this->cantidad_municion += cantidad_municion;
}
