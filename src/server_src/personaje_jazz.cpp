#include "personaje_jazz.h"


Jazz::Jazz(uint32_t id_jugador) : Personaje(id_jugador){
    tiempo_especial = -ENFRIAMIENTO_JAZZ;
}

uint8_t Jazz::obtener_personaje(){
    return JAZZ;
}

void Jazz::usar_habilidad(std::chrono::duration<double> tiempo_transcurrido){
    if(posicion_y > 0 && !saltando && !usando_especial && (tiempo_transcurrido.count() - tiempo_especial) >= ENFRIAMIENTO_JAZZ) {
        velocidad_y = -VELOCIDAD_SALTO-15;
        velocidad_x = 0;
        esta_quieto = false;
        saltando = true;
        usando_especial = true;
        tiempo_salto = tiempo_transcurrido.count();
        tiempo_especial = tiempo_transcurrido.count();
    }
}

void Jazz::mover_derecha(){
    if(!usando_especial){
        Personaje::mover_derecha();
    }
}

void Jazz::mover_izquierda(){
    if(!usando_especial){
        Personaje::mover_izquierda();
    }
}

void Jazz::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido){
    Personaje::actualizar_posicion(tiempo_transcurrido);
    if(!saltando){
        usando_especial = false;
    }
}
