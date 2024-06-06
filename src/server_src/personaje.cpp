#include "personaje.h"



Personaje::Personaje(uint32_t id_jugador) : id_jugador(id_jugador),
    posicion_x(150),posicion_y(0), vida(100), esta_quieto(0),arma(){
    corriendo = false;
    usando_especial = false;
    saltando = false;
    esta_quieto = true;
    esta_disparando = false;
    tiempo_salto = 0;
    tiempo_especial = 0;
    direccion_mirando = DERECHA;
}

void Personaje::posicion_X(uint32_t x){
    this->posicion_x = x;
}

void Personaje::posicion_Y(uint32_t y){
    this->posicion_y = y;
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

uint8_t Personaje::disparar(std::chrono::duration<double> tiempo_transcurrido){
    esta_disparando = true;
    if(arma.disparar(tiempo_transcurrido)){
       return arma.obtener_bala();
    }
    return NINGUNA;
}

void Personaje::dejar_disparar(){
    esta_disparando = false;
}

void Personaje::quedarse_quieto(){
    if(!saltando) {
        esta_quieto = true;
        //velocidad_x = 0;
    }
    velocidad_x = 0;
}

void Personaje::correr_rapido(){
    corriendo = saltando ? false : true;
}

void Personaje::correr(){
    corriendo = false;
}

void Personaje::recibir_golpe(uint8_t golpe){
    this->vida -= golpe;
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

uint8_t Personaje::obtener_saltando(){
    return saltando;
}

uint8_t Personaje::obtener_disparando(){
    return esta_disparando;
}

bool Personaje::hay_colision(uint32_t pos_x, uint32_t pos_y, uint32_t ancho, uint32_t largo) {
    return (this->posicion_x < pos_x + ancho && 
            this->posicion_x + PERSONAJE_WIDTH > pos_x &&
            this->posicion_y < pos_y + largo && 
            this->posicion_y + PERSONAJE_HEIGHT > pos_y);

}

bool Personaje::mirando_izquierda(){
    return direccion_mirando == IZQUIERDA;
}


void Personaje::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*> &map_objetos){
        int32_t nueva_posicion_x = posicion_x + (velocidad_x);
        double tiempo_segundos = tiempo_transcurrido.count();
        double delta_tiempo = tiempo_segundos - tiempo_salto;

        if(velocidad_x == 0 && velocidad_y == 0 && !saltando){
            esta_quieto = true;
        }

        velocidad_y += GRAVEDAD * delta_tiempo;

        Rectangulo rect_personaje = {   posicion_x + velocidad_x,
                                        posicion_y,
                                        PERSONAJE_WIDTH,
                                        PERSONAJE_HEIGHT};

        Rectangulo rect_personaje_arriba = {   posicion_x,
                                        posicion_y + velocidad_y,
                                        PERSONAJE_WIDTH,
                                        PERSONAJE_HEIGHT};


        for (const auto& par_objeto : map_objetos) {
            par_objeto.second->reaparecer(tiempo_transcurrido);

            Rectangulo rect_objeto = {par_objeto.second->obtener_posicionX(),
                                        par_objeto.second->obtener_posicionY(),
                                        par_objeto.second->obtener_ancho(),
                                        par_objeto.second->obtener_alto() };

            if(par_objeto.second->obtener_mostrar()){
                if(par_objeto.second->obtener_objeto() == SOLIDO){
                    if(rect_personaje.hay_colision(rect_objeto)){
                            //std::cout << "HAY COLISION CON OBJETO SOLIDO" << std::endl;
                            velocidad_x = 0;
                    }
                    if(rect_personaje_arriba.hay_colision(rect_objeto)){
                        //std::cout << "HAY COLISION CON OBJETO SOLIDO" << std::endl;
                        velocidad_y = 0;
                        saltando = false;
                        /*
                        if(velocidad_x == 0){
                            esta_quieto = true;
                        }
                        */
                    }else{
                        saltando = true;
                    }
                }else{
                    if(rect_personaje.hay_colision(rect_objeto)){
                        //std::cout << "HAY COLISION CON OBJETO NORMAL" << std::endl;
                        par_objeto.second->interactuar_personaje(this, tiempo_transcurrido);
                    }
                }

            }

        }

        posicion_x += velocidad_x;
        posicion_y += velocidad_y;
    

 
    
        
        if (posicion_y > HEIGHT - PERSONAJE_HEIGHT) { // Si hay colision abajo
            posicion_y = HEIGHT - PERSONAJE_HEIGHT;
            saltando = false;
        }
        
        
    
    
    
}


Personaje::~Personaje(){
    
}