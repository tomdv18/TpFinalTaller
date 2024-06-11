#include "estado.h"


Estado::Estado(uint8_t codigo_estado): codigo_estado(codigo_estado), personaje(nullptr) {}


void Estado::asignarPersonaje(Personaje* personaje) { this->personaje = personaje; }


uint8_t Estado::obtener_estado() { return codigo_estado; }
