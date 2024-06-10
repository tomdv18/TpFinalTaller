#include "enemigo_lizzard.h"
#define CONFIG Configuracion::config()

Lizzard::Lizzard(uint32_t id_enemigo): Enemigo(id_enemigo) {
    std::cout << "LIZZARD CREADO" << std::endl;
    vida = CONFIG.obtenerVidaLizzard();
    puntos = CONFIG.obtenerPuntosLizzard();
    danio = CONFIG.obtenerDanioLizzard();
}

uint8_t Lizzard::obtener_personaje() {
    return LIZZARD;
}


void Lizzard::mover_derecha() { Enemigo::mover_derecha(); }

void Lizzard::mover_izquierda() { Enemigo::mover_izquierda(); }

void Lizzard::revivir(){
    vida = CONFIG.obtenerVidaLizzard();
    vivo = true;
}

void Lizzard::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {
    if(tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion){
        vida = CONFIG.obtenerVidaLizzard();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
