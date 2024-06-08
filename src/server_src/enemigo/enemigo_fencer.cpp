#include "enemigo_fencer.h"
#define VIDA_FENCER 120

Fencer::Fencer(uint32_t id_enemigo): Enemigo(id_enemigo) {
    std::cout << "FENCER CREADO" << std::endl;
    vida = VIDA_FENCER;
}

uint8_t Fencer::obtener_personaje() {
    return FENCER;
}

void Fencer::revivir() { 
    vida = VIDA_FENCER;
    vivo = true; }

void Fencer::mover_derecha() { Enemigo::mover_derecha(); }

void Fencer::mover_izquierda() { Enemigo::mover_izquierda(); }

void Fencer::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
