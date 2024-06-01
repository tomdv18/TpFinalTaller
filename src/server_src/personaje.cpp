#include "personaje.h"
#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50
#define VELOCIDAD 5
#define VELOCIDAD_SALTO 20


Personaje::Personaje(uint32_t id_jugador) : id_jugador(id_jugador), posicion_x(0),posicion_y(0), vida(100), esta_quieto(0){

}

void Personaje::mover_derecha(){
    if(posicion_x  + PERSONAJE_WIDTH < WIDTH) {
        //posicion_x += VELOCIDAD;
        velocidad_x = VELOCIDAD;
        esta_quieto = 1;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_izquierda(){
    if(posicion_x > 0) {
        //posicion_x -= VELOCIDAD;
        velocidad_x = -VELOCIDAD;
        esta_quieto = 1;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_arriba() {
    if(posicion_y > 0) {
        posicion_y -= VELOCIDAD;
        velocidad_y = VELOCIDAD;
    }
     std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
   
}

void Personaje::mover_abajo() {
    if(posicion_y  + PERSONAJE_HEIGHT < HEIGHT) {
        posicion_y += VELOCIDAD;
        esta_quieto = 1;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::quedarse_quieto(){
    velocidad_x = 0;
    esta_quieto = 0;
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

uint8_t Personaje::obtener_movimiento(){
    return esta_quieto;
}

void Personaje::actualizar_posicion(double tiempo){
    posicion_x += velocidad_x;
}


Personaje::~Personaje(){
    
}