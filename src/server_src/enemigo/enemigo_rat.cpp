#include "enemigo_rat.h"
#define CONFIG Configuracion::config()


Rat::Rat(uint32_t id_enemigo): Enemigo(id_enemigo) {
    std::cout << "RAT CREADO" << std::endl;
    vida = CONFIG.obtenerVidaRat();
}

uint8_t Rat::obtener_personaje() {
    return RAT;
}


void Rat::mover_derecha() { Enemigo::mover_derecha(); }

void Rat::mover_izquierda() { Enemigo::mover_izquierda(); }

void Rat::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {
    if(tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion){
        vida = CONFIG.obtenerVidaRat();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
