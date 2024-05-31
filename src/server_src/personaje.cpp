#include "personaje.h"
#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50
#define VELOCIDAD 5


Personaje::Personaje(uint32_t id_jugador) : id_jugador(id_jugador), posicion_x(0),posicion_y(0), vida(100){

}

void Personaje::mover_derecha(){
    if(posicion_x  + PERSONAJE_WIDTH < WIDTH) {
        posicion_x += VELOCIDAD;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_izquierda(){
    if(posicion_x > 0) {
        posicion_x -= VELOCIDAD;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_arriba() {
    if(posicion_y > 0) {
        posicion_y -= VELOCIDAD;
    }
     std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
   
}

void Personaje::mover_abajo() {
    if(posicion_y  + PERSONAJE_HEIGHT < HEIGHT) {
        posicion_y += VELOCIDAD;
    }
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