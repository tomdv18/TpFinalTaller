#include "objeto_solido.h"
 
Solido::Solido(uint32_t id_objeto, uint32_t posicion_x, uint32_t posicion_y, double tiempo_reaparicion, uint32_t ancho, uint32_t alto) :
        Objeto(id_objeto, posicion_x, posicion_y, tiempo_reaparicion, ancho, alto){}

uint8_t Solido::obtener_objeto(){
    return SOLIDO;
}

void Solido::interactuar_personaje(Personaje *personaje, std::chrono::duration<double> tiempo_transcurrido){
    // No hace nada
}
