#include "personaje.h"
#include "../estado/estado_quieto.h"

#define CONFIG Configuracion::config()

Personaje::Personaje(uint32_t id_jugador):
        id_jugador(id_jugador), posicion_x(150), posicion_y(100), vida(CONFIG.getVidaPersonaje()), arma(), velocidad_x(0), velocidad_y(0), estado(nullptr){
    corriendo = false;
    usando_especial = false;
    saltando = false;
    esta_quieto = true;
    esta_disparando = false;
    en_superficie = false;
    muerto = false;
    invulnerable = true;
    intoxicado = false;
    tiempo_intoxicado = 0;
    tiempo_invulnerable = 0;
    tiempo_salto = 0;
    tiempo_especial = 0;
    puntos = 0;
    direccion_mirando = DERECHA;
    ancho = CONFIG.getAnchoPersonaje();
    alto = CONFIG.getAltoPersonaje();


    this->cambiarEstado(new EstadoQuieto());
}

void Personaje::posicion_X(uint32_t x) { this->posicion_x = x; }

void Personaje::posicion_Y(uint32_t y) { this->posicion_y = y; }


void Personaje::mover_derecha(std::chrono::duration<double> tiempo_transcurrido) {
    if(usando_especial)return;

    velocidad_x = corriendo ? CONFIG.getVelocidadXPersonaje() * 2 : CONFIG.getVelocidadXPersonaje();
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
    if(usando_especial)return;

    velocidad_x = corriendo ? -CONFIG.getVelocidadXPersonaje() * 2 : -CONFIG.getVelocidadXPersonaje();
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
    
    if (!saltando && !corriendo) {
        velocidad_y = -CONFIG.getVelocidadYPersonaje();
        esta_quieto = false;
        saltando = true;
        en_superficie = false;
        tiempo_salto = tiempo_transcurrido.count();
        this->manejarEstado(ESTADO_SALTANDO, tiempo_transcurrido);
    }

    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

void Personaje::mover_abajo() {
    /*
    if (posicion_y + CONFIG.getAlto < HEIGHT) {
        posicion_y += VELOCIDAD;
        esta_quieto = false;
    }
    */
    
    std::cout << "POSICION DEL PERSONAJE (" << posicion_x << ", " << posicion_y << ")" << std::endl;
}

uint8_t Personaje::disparar(std::chrono::duration<double> tiempo_transcurrido) {
    if(!usando_especial && !intoxicado){
        if (arma.disparar(tiempo_transcurrido)) {
            std::cout << "DISPARAR" << std::endl;
            esta_disparando = true;
            return arma.obtener_bala();
        }
    }
    return NINGUNO;
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
    if(invulnerable) return;
    this->vida -= golpe; 
    if(vida <= 0){
        std::cout << "MUERTO" << std::endl;
        muerto = true;
        vida = 0;
        velocidad_x = 0;
        velocidad_y = 0;
        this->estado->manejarEstado(ESTADO_MUERTO,tiempo_transcurrido.count());
    } else {
        this->estado->manejarEstado(ESTADO_HERIDO, tiempo_transcurrido.count());
        volverse_invulnerable(tiempo_transcurrido.count());
    }
}

void Personaje::intoxicarse(double tiempo){
    tiempo_intoxicado = tiempo;
    intoxicado = true;
}

void Personaje::asignar_puntos(uint32_t puntos){
    this->puntos += puntos;
}

void Personaje::curarse(int vida_restaurada){
    vida += vida_restaurada;
    if(vida > CONFIG.getVidaPersonaje()){
        vida = CONFIG.getVidaPersonaje();
    }
}

void Personaje::revivir(){
    // Aca deberia setearse alguna nueva posicion de spawn
    this->vida = 100;
    this->muerto = false;
}

void Personaje::volverse_invulnerable(double tiempo){
    if(!invulnerable){
        tiempo_invulnerable = tiempo;
        invulnerable = true;
    }
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

uint32_t Personaje::obtener_ancho(){
    return ancho;
}

uint32_t Personaje::obtener_alto(){
    return alto;
}

uint8_t Personaje::obtener_intoxicado(){
    return intoxicado;
}

bool Personaje::esta_muerto(){
    return muerto;
}

bool Personaje::es_invulnerable(){
    return invulnerable;
}

bool Personaje::hay_colision(uint32_t pos_x, uint32_t pos_y, uint32_t ancho, uint32_t largo) {
    return (this->posicion_x<pos_x + ancho&& this->posicion_x + this->ancho > pos_x &&
            this->posicion_y<pos_y + largo&& this->posicion_y + this->alto > pos_y);
}

bool Personaje::mirando_izquierda() { return direccion_mirando == IZQUIERDA; }


void Personaje::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                                    std::map<uint32_t, Objeto*>& map_objetos_solidos, std::map<uint32_t, std::unique_ptr<Objeto>>& map_objetos_comunes) {
    double tiempo_segundos = tiempo_transcurrido.count();
    double delta_tiempo = tiempo_segundos - tiempo_salto;

    if(invulnerable && tiempo_segundos - tiempo_invulnerable >= CONFIG.getTiempoInvulnerabilidad()){
        invulnerable = false;
    }

    if(tiempo_segundos - tiempo_intoxicado >= CONFIG.getTiempoIntoxicacion()){
        intoxicado = false;
    }

    if (tiempo_salto == 0) {
        tiempo_salto = tiempo_segundos;
    }
    
    if (!en_superficie) {
        velocidad_y += CONFIG.getGravedad() * delta_tiempo;
    } else {
        velocidad_y = 0;
    }

    std::cout << "PUNTUACION:" << puntos << std::endl;
    //std::cout << "ESTA INVULNERABLE: " << (int) invulnerable << std::endl;

    //std::cout << "ESTA INTOXICADO: " << (int) intoxicado << std::endl;

    uint32_t nueva_posicion_x = posicion_x + velocidad_x;
    uint32_t nueva_posicion_y = posicion_y + velocidad_y;

    Rectangulo rect_personaje = {nueva_posicion_x, posicion_y,this->ancho, this->alto};
    Rectangulo rect_personaje_arriba = {posicion_x, nueva_posicion_y, this->ancho, this->alto};

    bool colision_suelo = false;

    for (const auto& par_objeto : map_objetos_solidos) {
        Rectangulo rect_objeto = {
            par_objeto.second->obtener_posicionX(), par_objeto.second->obtener_posicionY(),
            par_objeto.second->obtener_ancho(), par_objeto.second->obtener_alto()
        };

        if (par_objeto.second->obtener_mostrar()) {
            if (par_objeto.second->obtener_objeto() == SOLIDO) {
                if (rect_personaje.hay_colision(rect_objeto)) {
                    corriendo = false;
                    if (velocidad_x > 0) {  // Moviéndose a la derecha
                        nueva_posicion_x = rect_objeto.x - this-> ancho;
                    } else if (velocidad_x < 0) {  // Moviéndose a la izquierda
                        nueva_posicion_x = rect_objeto.x + rect_objeto.ancho;
                    }
                    velocidad_x = 0;
                }
                if (rect_personaje_arriba.hay_colision(rect_objeto)) {
                    if (velocidad_y > 0) {  // Cayendo
                        nueva_posicion_y = rect_objeto.y - this->alto;
                        velocidad_y = 0;
                        saltando = false;
                        colision_suelo = true;
                        tiempo_salto = tiempo_segundos;
                    } else if (velocidad_y < 0) {  // Saltando hacia arriba
                        nueva_posicion_y = rect_objeto.y + rect_objeto.alto;
                        velocidad_y = 0;
                    }
                }
            }
        }
    }

    // Verificar colisiones con objetos comunes
    for (const auto& par_objeto : map_objetos_comunes) {
        par_objeto.second->reaparecer(tiempo_transcurrido);

        Rectangulo rect_objeto = {
            par_objeto.second->obtener_posicionX(), par_objeto.second->obtener_posicionY(),
            par_objeto.second->obtener_ancho(), par_objeto.second->obtener_alto()
        };

        if (par_objeto.second->obtener_mostrar()) {
            if (rect_personaje.hay_colision(rect_objeto) || rect_personaje_arriba.hay_colision(rect_objeto)) {
                par_objeto.second->interactuar_personaje(this, tiempo_transcurrido);
            }
        }
    }

    if (!saltando && velocidad_x == 0) {
        this->manejarEstado(ESTADO_QUIETO, tiempo_transcurrido);
    }

    if (velocidad_x != 0 && !saltando) {
        if (!corriendo) this->manejarEstado(ESTADO_CAMINANDO, tiempo_transcurrido);
    }

    posicion_x = nueva_posicion_x;
    posicion_y = nueva_posicion_y;

    this->actualizar(tiempo_transcurrido.count());

    if (posicion_y > CONFIG.getAltoPantalla() - CONFIG.getAltoPersonaje()) {  // Si hay colision abajo
        posicion_y = CONFIG.getAltoPantalla() - CONFIG.getAltoPersonaje();
        saltando = false;
        colision_suelo = true;
        tiempo_salto = tiempo_segundos;
    }

    // Actualizar en_superficie basado en colision_suelo
    en_superficie = colision_suelo;
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
