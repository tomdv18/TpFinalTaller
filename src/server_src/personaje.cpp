#include "personaje.h"
#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50
#define VELOCIDAD 5
#define VELOCIDAD_SALTO 25
#define GRAVEDAD 3


Personaje::Personaje(uint32_t id_jugador) : id_jugador(id_jugador), posicion_x(0),posicion_y(0), vida(100), esta_quieto(0){
    corriendo = false;
    tiempo_salto = 0;
}

void Personaje::mover_derecha(){
    if(posicion_x + PERSONAJE_WIDTH < WIDTH) {
        velocidad_x = corriendo ? VELOCIDAD * 2 : VELOCIDAD;
        esta_quieto = false;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_izquierda(){
    if(posicion_x > 0) {
        velocidad_x = corriendo ? -VELOCIDAD * 2 : -VELOCIDAD;
        esta_quieto = false;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_arriba(std::chrono::duration<double> tiempo_transcurrido) {
    if(posicion_y > 0 && !saltando) {
        velocidad_y = -VELOCIDAD_SALTO;
        esta_quieto = false;
        saltando = true;
        tiempo_salto = tiempo_transcurrido.count();
    }
     std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
   
}

void Personaje::mover_abajo() {
    if(posicion_y  + PERSONAJE_HEIGHT < HEIGHT) {
        posicion_y += VELOCIDAD;
        esta_quieto = false;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::quedarse_quieto(){
    if(!saltando) {
        velocidad_x = 0;
        esta_quieto = true;
    }
}

void Personaje::correr_rapido(){
    corriendo = saltando ? false : true;

    //corriendo = true;
}

void Personaje::correr(){
    corriendo = false;
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

uint8_t Personaje::obtener_corriendo(){
    return corriendo;
}

void Personaje::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido){
    int32_t nueva_posicion_x = posicion_x + static_cast<int32_t>(velocidad_x);
    double tiempo_segundos = tiempo_transcurrido.count();

    if (velocidad_x > 0) {
        if (nueva_posicion_x >= WIDTH - PERSONAJE_WIDTH) {
            posicion_x = WIDTH - PERSONAJE_WIDTH;  
        } else {
            posicion_x = nueva_posicion_x;
        }
    }
    else if (velocidad_x < 0) {
        if (nueva_posicion_x <= 0) {
            posicion_x = 0;  
        } else {
            posicion_x = nueva_posicion_x;
        }
    }


     if (saltando) {
        double delta_tiempo = tiempo_segundos - tiempo_salto;

        posicion_y += static_cast<int32_t>(velocidad_y * delta_tiempo + 0.5 * GRAVEDAD * delta_tiempo * delta_tiempo);
        velocidad_y += GRAVEDAD * delta_tiempo;

        if (posicion_y > HEIGHT - PERSONAJE_HEIGHT) {
            posicion_y = HEIGHT - PERSONAJE_HEIGHT;
            saltando = false;
            velocidad_y = 0;
            std::cout << "ATERRIZO" << std::endl;
        }
    }
    
}


Personaje::~Personaje(){
    
}