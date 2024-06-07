#include "personaje.h"
#include "../estado/estado_quieto.h"

Personaje::Personaje(uint32_t id_jugador):
        id_jugador(id_jugador), posicion_x(150), posicion_y(100), vida(100), esta_quieto(0), arma(), velocidad_x(0), velocidad_y(0), estado(nullptr){
    corriendo = false;
    usando_especial = false;
    saltando = true;
    esta_quieto = true;
    esta_disparando = false;
    en_superficie = false;
    muerto = false;
    tiempo_salto = 0;
    tiempo_especial = 0;
    direccion_mirando = DERECHA;

    this->cambiarEstado(new EstadoQuieto());
}

void Personaje::posicion_X(uint32_t x) { this->posicion_x = x; }

void Personaje::posicion_Y(uint32_t y) { this->posicion_y = y; }


void Personaje::mover_derecha(std::chrono::duration<double> tiempo_transcurrido) {
 
    velocidad_x = corriendo ? VELOCIDAD * 2 : VELOCIDAD;
    esta_quieto = false;
    if(!corriendo){
        this->manejarEstado(ESTADO_CAMINANDO, tiempo_transcurrido);
    }else{
        this->manejarEstado(ESTADO_CORRIENDO, tiempo_transcurrido);
    }

    direccion_mirando = DERECHA;
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_izquierda(std::chrono::duration<double> tiempo_transcurrido) {

    velocidad_x = corriendo ? -VELOCIDAD * 2 : -VELOCIDAD;
    esta_quieto = false;
    if(!corriendo){
            this->manejarEstado(ESTADO_CAMINANDO, tiempo_transcurrido);
    }else{
            this->manejarEstado(ESTADO_CORRIENDO, tiempo_transcurrido);
    }
    direccion_mirando = IZQUIERDA;
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_arriba(std::chrono::duration<double> tiempo_transcurrido) {
    
    if (en_superficie && !corriendo) {
        velocidad_y = -VELOCIDAD_SALTO;
        esta_quieto = false;
        saltando = true;
        en_superficie = false;
        tiempo_salto = tiempo_transcurrido.count();
        this->manejarEstado(ESTADO_SALTANDO, tiempo_transcurrido);
    }
    

    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_abajo() {
    if (posicion_y + PERSONAJE_HEIGHT < HEIGHT) {
        posicion_y += VELOCIDAD;
        esta_quieto = false;
    }
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

uint8_t Personaje::disparar(std::chrono::duration<double> tiempo_transcurrido) {
    esta_disparando = true;
    if (arma.disparar(tiempo_transcurrido)) {
        std::cout << "DISPARAR" << std::endl;
        return arma.obtener_bala();
    }
    return NINGUNA;
}

void Personaje::dejar_disparar() { 
    std::cout << "DEJANDO DE DISPARAR" << std::endl;
    esta_disparando = false; }

void Personaje::quedarse_quieto() {
    velocidad_x = 0;
    corriendo = false;
}

void Personaje::correr_rapido(std::chrono::duration<double> tiempo_transcurrido) { 
    corriendo = saltando ? false : true; 
    if(corriendo){
        this->manejarEstado(ESTADO_CORRIENDO, tiempo_transcurrido);
    }
}

void Personaje::correr() { 
    if(corriendo){
        corriendo = false; 
        velocidad_x = velocidad_x/2;
    }
}

void Personaje::recibir_golpe(uint8_t golpe, std::chrono::duration<double> tiempo_transcurrido) {
    this->vida -= golpe; 
    if(this->vida <= 0){
        muerto = true;
        this->estado->manejarEstado(ESTADO_MUERTO,tiempo_transcurrido.count());
    } else {
        this->estado->manejarEstado(ESTADO_HERIDO, tiempo_transcurrido.count());
    }
}

void Personaje::revivir(){
    // Aca deberia setearse alguna nueva posicion de spawn
    this->vida = 100;
    this->muerto = false;
}

uint32_t Personaje::obtener_posicionX() { return posicion_x; }

uint32_t Personaje::obtener_posicionY() { return posicion_y; }

uint8_t Personaje::obtener_vida() { return vida; }

uint8_t Personaje::obtener_movimiento() { return esta_quieto; }

uint8_t Personaje::obtener_corriendo() { return corriendo; }

uint8_t Personaje::obtener_habilidad() { return usando_especial; }

uint8_t Personaje::obtener_saltando() { return saltando; }

uint8_t Personaje::obtener_disparando() { return esta_disparando; }

uint8_t Personaje::obtener_estado(){
    return estado->obtener_estado();
}

bool Personaje::esta_muerto(){
    return muerto;
}

bool Personaje::hay_colision(uint32_t pos_x, uint32_t pos_y, uint32_t ancho, uint32_t largo) {
    return (this->posicion_x<pos_x + ancho&& this->posicion_x + PERSONAJE_WIDTH> pos_x &&
            this->posicion_y<pos_y + largo&& this->posicion_y + PERSONAJE_HEIGHT> pos_y);
}

bool Personaje::mirando_izquierda() { return direccion_mirando == IZQUIERDA; }


void Personaje::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                                    std::map<uint32_t, Objeto*>& map_objetos_solidos, std::map<uint32_t, Objeto*>& map_objetos_comunes) {
    double tiempo_segundos = tiempo_transcurrido.count();
    double delta_tiempo = tiempo_segundos - tiempo_salto;
    
    
    if (!en_superficie) {
        velocidad_y += GRAVEDAD * delta_tiempo;
    } else {
        velocidad_y = 0;
    }


    uint32_t nueva_posicion_x = posicion_x + velocidad_x;
    uint32_t nueva_posicion_y = posicion_y + velocidad_y;

    Rectangulo rect_personaje = {nueva_posicion_x, posicion_y, PERSONAJE_WIDTH, PERSONAJE_HEIGHT};
    Rectangulo rect_personaje_arriba = {posicion_x, nueva_posicion_y, PERSONAJE_WIDTH, PERSONAJE_HEIGHT};

    for (const auto& par_objeto : map_objetos_solidos) {
        //par_objeto.second->reaparecer(tiempo_transcurrido);

        Rectangulo rect_objeto = {
            par_objeto.second->obtener_posicionX(), par_objeto.second->obtener_posicionY(),
            par_objeto.second->obtener_ancho(), par_objeto.second->obtener_alto()
        };

        if (par_objeto.second->obtener_mostrar()) {
            if (par_objeto.second->obtener_objeto() == SOLIDO) {
                if (rect_personaje.hay_colision(rect_objeto)) {
                    corriendo = false;
                    if (velocidad_x > 0) {  // Moviéndose a la derecha
                        nueva_posicion_x = rect_objeto.x - PERSONAJE_WIDTH;
                    } else if (velocidad_x < 0) {  // Moviéndose a la izquierda
                        nueva_posicion_x = rect_objeto.x + rect_objeto.ancho;
                    }
                    velocidad_x = 0;
                }
                if (rect_personaje_arriba.hay_colision(rect_objeto)) {
                    if (velocidad_y > 0) {  // Cayendo
                        nueva_posicion_y = rect_objeto.y - PERSONAJE_HEIGHT;
                        velocidad_y = 0;
                        saltando = false;
                        en_superficie = true;
                    } else if (velocidad_y < 0) {  // Saltando hacia arriba
                        nueva_posicion_y = rect_objeto.y + rect_objeto.alto;
                        velocidad_y = 0;
                    }
                }
            }/*  PARA OBJETOS COMUNES
            else {
                if (rect_personaje.hay_colision(rect_objeto)) {
                    par_objeto.second->interactuar_personaje(this, tiempo_transcurrido);
                }
            }
            */
        }
    }


    //Aca colision con objetos comunes
    for (const auto& par_objeto : map_objetos_comunes) {
        par_objeto.second->reaparecer(tiempo_transcurrido);

        Rectangulo rect_objeto = {
            par_objeto.second->obtener_posicionX(), par_objeto.second->obtener_posicionY(),
            par_objeto.second->obtener_ancho(), par_objeto.second->obtener_alto()
        };

        if (par_objeto.second->obtener_mostrar()) {
            
            if (rect_personaje.hay_colision(rect_objeto) || rect_personaje_arriba.hay_colision(rect_objeto)){
                par_objeto.second->interactuar_personaje(this, tiempo_transcurrido);
            }
        }
    }


    if(!saltando && velocidad_x == 0){
        this->manejarEstado(ESTADO_QUIETO, tiempo_transcurrido);
    }

    posicion_x = nueva_posicion_x;
    posicion_y = nueva_posicion_y;


    this->actualizar(tiempo_transcurrido.count());

    if (posicion_y > HEIGHT - PERSONAJE_HEIGHT) {  // Si hay colision abajo
        posicion_y = HEIGHT - PERSONAJE_HEIGHT;
        saltando = false;
        en_superficie = true;
    }
}



void Personaje::cambiarEstado(Estado *estado){
    if (this->estado != nullptr){
        delete this->estado;
    }
    this->estado = estado;
    this->estado->asignarPersonaje(this);
}

void Personaje::manejarEstado(uint8_t codigo_estado, std::chrono::duration<double> tiempo_transcurrido){
    this->estado->manejarEstado(codigo_estado, tiempo_transcurrido.count());
}

void Personaje::actualizar(double tiempo){
    this->estado->actualizar(tiempo);
}


Personaje::~Personaje() {
    delete estado;
}
