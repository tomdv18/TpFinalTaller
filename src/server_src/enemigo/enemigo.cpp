#include "enemigo.h"

#define PASOS_POR_DIRECCION 15

#define CONFIG Configuracion::config()

Enemigo::Enemigo(uint32_t id_enemigo, uint32_t x, uint32_t y):
        id_enemigo(id_enemigo),
        posicion_x(x),
        posicion_y(y),
        vida(CONFIG.obtenerVidaDefaultEnemigo()),
        esta_quieto(true),
        vivo(true),
        iteraciones_para_revivir(-1),
        pasos_patrullando(0),
        danio(CONFIG.obtener_danio_default_enemigo()),
        tiempo_reaparicion(CONFIG.obtenerTiempoReaparicionEnemigo()),
        direccion_mirando(DERECHA),
        ancho(CONFIG.obtenerAnchoEnemigo()),
        alto(CONFIG.obtenerAltoEnemigo()){
    tiempo_muerte = 0;
    puntos = 0;
    velocidad_x = 10;
}

void Enemigo::mover_derecha() {
    if (posicion_x + ancho < WIDTH) {
        velocidad_x = CONFIG.obtenerVelocidadEnemigos();
        esta_quieto = false;
    }
    direccion_mirando = DERECHA;
}

void Enemigo::mover_izquierda() {
    if (posicion_x > 0) {
        velocidad_x = -CONFIG.obtenerVelocidadEnemigos();;
        esta_quieto = false;
    }
    direccion_mirando = IZQUIERDA;
}

void Enemigo::recibir_golpe(Bala bala, std::chrono::duration<double> tiempo_transcurrido){
    bala.inflingir_danio(this, tiempo_transcurrido);
}

void Enemigo::recibir_golpe(Personaje *personaje, std::chrono::duration<double> tiempo_transcurrido){
    personaje->inflingir_danio_habilidad(this, tiempo_transcurrido);
}


void Enemigo::recibir_golpe(uint8_t golpe, std::chrono::duration<double> tiempo_transcurrido) {
    vida -= golpe; 
    std::cout << "VIDA ACTUAL"<< (int) vida << std::endl;
    if(vida <= 0){
        vivo = false;
        vida = 0;
        tiempo_muerte = tiempo_transcurrido.count();
    }
}

void Enemigo::inflingir_danio(Personaje *personaje, std::chrono::duration<double> tiempo_transcurrido){
    personaje->recibir_golpe(this->danio,tiempo_transcurrido);
}


void Enemigo::matar() { 
    vida = 0;
    vivo = false; }

void Enemigo::revivir() { 
    vivo = true; }

bool Enemigo::esta_vivo() { return vivo; }

int Enemigo::obtener_danio() { return danio; }

uint32_t Enemigo::obtener_puntos(){ return puntos; }


void Enemigo::quedarse_quieto() {
    //velocidad_x = 0;
    esta_quieto = true;
}


uint32_t Enemigo::obtener_posicionX() { return posicion_x; }

uint32_t Enemigo::obtener_posicionY() { return posicion_y; }

uint8_t Enemigo::obtener_vida() { return vida; }

uint8_t Enemigo::obtener_movimiento() { return esta_quieto; }


uint32_t Enemigo::obtener_alto(){
    return alto;
}

uint32_t Enemigo::obtener_ancho(){
    return ancho;
}

bool Enemigo::mirando_izquierda(){
    return direccion_mirando == IZQUIERDA;
}

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
    
    if(!vivo){
        return;
    }

    patrullar();
    int32_t nueva_posicion_x = posicion_x + static_cast<int32_t>(velocidad_x);
    double tiempo_segundos = tiempo_transcurrido.count();

    if (velocidad_x == 0) {
        esta_quieto = true;
    }

    if (velocidad_x > 0) {
         if (nueva_posicion_x >= WIDTH - ancho) {
            posicion_x = WIDTH - ancho;
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
    

   /*
   if (!vivo) {
        return;
    }

    // Actualizar posición basada en la velocidad
    int32_t nueva_posicion_x = posicion_x + velocidad_x;
    int32_t nueva_posicion_y = posicion_y;


    int32_t cell_x = nueva_posicion_x / 50;
    int32_t cell_y = nueva_posicion_y / 50;

    std::cout << "CELDA: " << cell_x << "   " << cell_y << std::endl;

    // Verificar colisión revisando la celda del grid
    if (grid.count(cell_x) && grid[cell_x].count(cell_y)) {
        if(grid.at(cell_x).at(cell_y).tiene_objeto_solido){
            std::cout << "COLISION" << std::endl;
            velocidad_x = -velocidad_x;
        }
    }
   
    posicion_x = nueva_posicion_x;
    posicion_y = nueva_posicion_y;
    */

}


Enemigo::~Enemigo() {}
