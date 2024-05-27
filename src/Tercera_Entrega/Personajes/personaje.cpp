#include "personaje.h"

Personaje::Personaje(int cantidad_vida, std::map<std::string, Accion> acciones, 
std::map<std::string, Estado> estados,std::map<std::string, Arma> armas,
Ataque_especial ataque_especial) : cantidad_vida(cantidad_vida), acciones(acciones), estados(estados),
armas(armas), cantidad_puntos(0) {}

void Personaje::aumentar_vida(int cantidad_vida) {
    this->cantidad_vida += cantidad_vida;
}

void Personaje::aumenatar_puntos(int cantidad_puntos) {
    this->cantidad_puntos += cantidad_puntos;
}

void Personaje::disminuir_vida(int cantidad_vida) {
    this->cantidad_vida -= cantidad_vida;
}

void Personaje::agregar_estado(Estado estado) {
    this->estados.insert({estado.get_nombre_estado(), estado});
}

void Personaje::eliminar_estado(Estado estado) {
    this->estados.erase(estado.get_nombre_estado());
}

void Personaje::agregar_arma(Arma arma) {
    this->armas.insert({arma.get_nombre_arma(), arma});
}

void Personaje::eliminar_arma(Arma arma) {
    this->armas.erase(arma.get_nombre_arma());
}

void Personaje::realizar_ataque_especial() {
    this->ataque_especial.realizar();
}

void Personaje::realizar_accion(Accion accion) {
    this->acciones[accion.get_nombre_accion()].realizar();
}

void Personaje::modificar_coordenadas(Coordenadas coordenadas) {
    this->coordenadas = coordenadas;
}

Arma Personaje::get_arma(std::string nombre_arma) {
    return this->armas[nombre_arma];
}