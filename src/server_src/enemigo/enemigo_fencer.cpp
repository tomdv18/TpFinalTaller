#include "enemigo_fencer.h"

#define CONFIG Configuracion::config()

Fencer::Fencer(uint32_t id_enemigo): Enemigo(id_enemigo) {
    std::cout << "FENCER CREADO" << std::endl;
    vida = CONFIG.obtenerVidaFencer();
}

uint8_t Fencer::obtener_personaje() { return FENCER; }
void Fencer::revivir() {
    vida = CONFIG.obtenerVidaFencer();
    vivo = true;
}

void Fencer::mover_derecha() { Enemigo::mover_derecha(); }

void Fencer::mover_izquierda() { Enemigo::mover_izquierda(); }

void Fencer::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {
    if (tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion) {
        vida = CONFIG.obtenerVidaFencer();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
