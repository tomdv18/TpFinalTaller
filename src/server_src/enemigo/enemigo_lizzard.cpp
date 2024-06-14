#include "enemigo_lizzard.h"
#define CONFIG Configuracion::config()

Lizzard::Lizzard(uint32_t id_enemigo, uint32_t x, uint32_t y): Enemigo(id_enemigo,x,y) {
    std::cout << "LIZZARD CREADO" << std::endl;
    vida = CONFIG.obtenerVidaLizzard();
    puntos = CONFIG.obtenerPuntosLizzard();
    danio = CONFIG.obtenerDanioLizzard();
    ancho = CONFIG.obtenerAnchoLizzard();
    alto = CONFIG.obtenerAltoLizzard();
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

void Lizzard::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*>& map_objetos_solidos) {
    if(tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion){
        vida = CONFIG.obtenerVidaLizzard();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido, map_objetos_solidos);
}
