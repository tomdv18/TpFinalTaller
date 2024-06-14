#include "enemigo_rat.h"
#define CONFIG Configuracion::config()


Rat::Rat(uint32_t id_enemigo, uint32_t x, uint32_t y): Enemigo(id_enemigo,x,y) {
    std::cout << "RAT CREADO" << std::endl;
    vida = CONFIG.obtenerVidaRat();
    puntos = CONFIG.obtenerPuntosRat();
    danio = CONFIG.obtenerDanioRat();
    ancho = CONFIG.obtenerAnchoRat();
    alto = CONFIG.obtenerAltoRat();
}

uint8_t Rat::obtener_personaje() {
    return RAT;
}
void Rat::revivir(){
    vida = CONFIG.obtenerVidaRat();
    vivo = true;
}

void Rat::mover_derecha() { Enemigo::mover_derecha(); }

void Rat::mover_izquierda() { Enemigo::mover_izquierda(); }

void Rat::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*>& map_objetos_solidos) {
    if(tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion){
        vida = CONFIG.obtenerVidaRat();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido, map_objetos_solidos);
}
