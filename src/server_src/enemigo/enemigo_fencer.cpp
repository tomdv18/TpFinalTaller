#include "enemigo_fencer.h"

#define CONFIG Configuracion::config()

Fencer::Fencer(uint32_t id_enemigo, uint32_t x, uint32_t y): Enemigo(id_enemigo,x,y) {
    std::cout << "FENCER CREADO" << std::endl;
    vida = CONFIG.obtenerVidaFencer();
    puntos = CONFIG.obtenerPuntosFencer();
    danio = CONFIG.obtenerDanioFencer();
    ancho = CONFIG.obtenerAnchoFencer();
    alto = CONFIG.obtenerAltoFencer();
}

uint8_t Fencer::obtener_personaje() {
    return FENCER;
}
void Fencer::revivir() { 
    vida = CONFIG.obtenerVidaFencer();
    vivo = true; }

void Fencer::mover_derecha() { Enemigo::mover_derecha(); }

void Fencer::mover_izquierda() { Enemigo::mover_izquierda(); }

void Fencer::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*>& map_objetos_solidos) {
    if(tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion){
        vida = CONFIG.obtenerVidaFencer();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido, map_objetos_solidos);
}
