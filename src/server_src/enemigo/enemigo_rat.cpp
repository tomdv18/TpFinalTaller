#include "enemigo_rat.h"
#define VIDA_RAT 50;


Rat::Rat(uint32_t id_enemigo): Enemigo(id_enemigo) {
    std::cout << "RAT CREADO" << std::endl;
    vida = VIDA_RAT;
}

uint8_t Rat::obtener_personaje() {
    return RAT;
}

void Rat::revivir(){
    vida = VIDA_RAT;
    vivo = true;
}

void Rat::mover_derecha() { Enemigo::mover_derecha(); }

void Rat::mover_izquierda() { Enemigo::mover_izquierda(); }

void Rat::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
