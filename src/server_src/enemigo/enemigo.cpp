#include "enemigo.h"

#define PASOS_POR_DIRECCION 15
#define VIDA_DEFAULT 100
#define DANIO_DEFAULT 25

Enemigo::Enemigo(uint32_t id_enemigo):
        id_enemigo(id_enemigo),
        posicion_x(150),
        posicion_y(100),
        vida(VIDA_DEFAULT),
        esta_quieto(true),
        vivo(true),
        iteraciones_para_revivir(-1),
        pasos_patrullando(0),
        danio(DANIO_DEFAULT) {
    direccion_mirando = DERECHA;
}

void Enemigo::mover_derecha() {
    if (posicion_x + PERSONAJE_WIDTH < WIDTH) {
        velocidad_x = VELOCIDAD;
        esta_quieto = false;
    }
    direccion_mirando = DERECHA;
}

void Enemigo::mover_izquierda() {
    if (posicion_x > 0) {
        velocidad_x = -VELOCIDAD;
        esta_quieto = false;
    }
    direccion_mirando = IZQUIERDA;
}

void Enemigo::matar() { 
    vida = 0;
    vivo = false; }

void Enemigo::revivir() { 
    vida = VIDA_DEFAULT;
    vivo = true; }

bool Enemigo::esta_vivo() { return vivo; }

int Enemigo::obtener_danio() { return danio; }


void Enemigo::quedarse_quieto() {
    velocidad_x = 0;
    esta_quieto = true;
}


uint32_t Enemigo::obtener_posicionX() { return posicion_x; }

uint32_t Enemigo::obtener_posicionY() { return posicion_y; }

uint8_t Enemigo::obtener_vida() { return vida; }

uint8_t Enemigo::obtener_movimiento() { return esta_quieto; }

void Enemigo::patrullar() {
    switch (direccion_mirando) {
        case DERECHA:
            if (pasos_patrullando >= PASOS_POR_DIRECCION) {
                pasos_patrullando = 0;
                direccion_mirando = IZQUIERDA;
                //std::cout << "POSICION DEL ENEMIGO (" << posicion_x << ", " << posicion_y << ")"
                          //<< std::endl;
                //std::cout << "CAMBIO DE DIRECCION PATRULLAJE DE DERECHA A IZQUIERDA" << std::endl;
            } else {
                mover_derecha();
                pasos_patrullando++;
            }
            break;
        case IZQUIERDA:
            if (pasos_patrullando >= PASOS_POR_DIRECCION) {
                pasos_patrullando = 0;
                direccion_mirando = DERECHA;
                //std::cout << "POSICION DEL ENEMIGO (" << posicion_x << ", " << posicion_y << ")"
                   //       << std::endl;
                //std::cout << "CAMBIO DE DIRECCION PATRULLAJE DE IZQUIERDA A DERECHA" << std::endl;
            } else {
                mover_izquierda();
                pasos_patrullando++;
            }
            break;

        default:
            break;
    }
}

void Enemigo::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) {

    patrullar();
    int32_t nueva_posicion_x = posicion_x + static_cast<int32_t>(velocidad_x);
    double tiempo_segundos = tiempo_transcurrido.count();

    if (velocidad_x == 0) {
        esta_quieto = true;
    }

    if (velocidad_x > 0) {
        if (nueva_posicion_x >= WIDTH - PERSONAJE_WIDTH) {
            posicion_x = WIDTH - PERSONAJE_WIDTH;
        } else {
            posicion_x = nueva_posicion_x;
        }
    } else if (velocidad_x < 0) {
        if (nueva_posicion_x <= 0) {
            posicion_x = 0;
        } else {
            posicion_x = nueva_posicion_x;
        }
    }
}


Enemigo::~Enemigo() {}
