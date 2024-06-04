#include "personaje.h"



Personaje::Personaje(uint32_t id_jugador) : id_jugador(id_jugador), posicion_x(0),posicion_y(0), vida(100), esta_quieto(0){
    corriendo = false;
    usando_especial = false;
    saltando = false;
    esta_quieto = true;
    tiempo_salto = 0;
    tiempo_especial = 0;
    direccion_mirando = DERECHA;
}

void Personaje::mover_derecha(){
    if(posicion_x + PERSONAJE_WIDTH < WIDTH) {
        velocidad_x = corriendo ? VELOCIDAD * 2 : VELOCIDAD;
        esta_quieto = false;
    }
    direccion_mirando = DERECHA;
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_izquierda(){
    if(posicion_x > 0) {
        velocidad_x = corriendo ? -VELOCIDAD * 2 : -VELOCIDAD;
        esta_quieto = false;
    }
    direccion_mirando = IZQUIERDA;
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_arriba(std::chrono::duration<double> tiempo_transcurrido) {
    if(posicion_y > 0 && !saltando && !corriendo) {
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

uint8_t Personaje::obtener_habilidad(){
    return usando_especial;
}

uint8_t Personaje::obtener_saltando() {
    return saltando;
}

void Personaje::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido){
    int32_t nueva_posicion_x = posicion_x + static_cast<int32_t>(velocidad_x);
    double tiempo_segundos = tiempo_transcurrido.count();

    if(velocidad_x == 0 && velocidad_y == 0 && !saltando){
        esta_quieto = true;
    }

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

        double nuevaY = static_cast<int32_t>(velocidad_y * delta_tiempo + 0.5 * GRAVEDAD * delta_tiempo * delta_tiempo);
        std::cout << "NUEVAY " << nuevaY << std::endl;
        if (nuevaY < 0) {
            posicion_y = 0;
        }
        else {
            posicion_y += nuevaY;
        }
        velocidad_y += GRAVEDAD * delta_tiempo;

        // Controlar colisiones con el suelo
        if (posicion_y > HEIGHT - PERSONAJE_HEIGHT) {
            posicion_y = HEIGHT - PERSONAJE_HEIGHT;
            saltando = false;
            velocidad_y = 0;
            velocidad_x = 0;
            std::cout << "ATERRIZO" << std::endl;
        }

    
    }
    
    
}


Personaje::~Personaje(){
    
}