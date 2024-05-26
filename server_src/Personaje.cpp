#include "Personaje.h"


Personaje::Personaje(uint32_t id_jugador) : id_jugador(id_jugador), posicion_x(0),posicion_y(0), vida(100){

}

void Personaje::mover_derecha(){
    posicion_x += 1;
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_izquierda(){
    posicion_x -= 1;
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

uint32_t Personaje::obtener_posicionX(){
    return posicion_x;
}

uint32_t Personaje::obtener_posicionY(){
    return posicion_y;
}

uint8_t Personaje::obtener_vida(){
    return vida;
}


Personaje::~Personaje(){
    
}