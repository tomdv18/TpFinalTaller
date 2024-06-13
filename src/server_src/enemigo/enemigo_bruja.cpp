#include "enemigo_bruja.h"

#define CONFIG Configuracion::config()

Bruja::Bruja(uint32_t id_enemigo, uint32_t x, uint32_t y): Enemigo(id_enemigo,x,y) {
    vida = CONFIG.obtenerVidaFencer();
    puntos = CONFIG.obtenerPuntosFencer();
    danio = CONFIG.obtenerDanioFencer();
    ancho = CONFIG.obtenerAnchoFencer();
    alto = CONFIG.obtenerAltoFencer();
    volador = true;
    velocidad_x = 10;
}

uint8_t Bruja::obtener_personaje() {
    return BRUJA;
}
void Bruja::revivir() { 
    vida = CONFIG.obtenerVidaFencer();
    vivo = true; }

void Bruja::mover_derecha() { Enemigo::mover_derecha(); }

void Bruja::mover_izquierda() { Enemigo::mover_izquierda(); }

void Bruja::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*>& map_objetos_solidos) {
    if(tiempo_transcurrido.count() - tiempo_muerte >= tiempo_reaparicion){
        vida = CONFIG.obtenerVidaFencer();
        vivo = true;
    }
    Enemigo::actualizar_posicion(tiempo_transcurrido, map_objetos_solidos);
}
