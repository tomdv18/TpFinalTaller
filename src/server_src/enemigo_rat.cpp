#include "enemigo_rat.h"
#define VIDA_RAT 50;


Rat::Rat(uint32_t id_enemigo): Enemigo(id_enemigo) {
    std::cout << "RAT CREADO" << std::endl;
    vida = VIDA_RAT;
}

uint8_t Rat::obtener_personaje() {
    return 0X02;  // CODIGO EJEMPLO
}


void Rat::mover_derecha() { Enemigo::mover_derecha(); }

void Rat::mover_izquierda() { Enemigo::mover_izquierda(); }

void Rat::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
