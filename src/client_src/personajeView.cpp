#include "personajeView.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50



PersonajeView::PersonajeView(uint32_t id_jugador, int x, int y) : id_jugador(id_jugador),ultimas_posiciones_x(), posicion_x(x), posicion_y(y), width(PERSONAJE_WIDTH), height(PERSONAJE_HEIGHT), 
facingLeft(false), isMoving(false), isRunning(false), isJumping(false), isShooting(false), stopShooting(false) {
    ultimas_posiciones_x[0] = 0;
    ultimas_posiciones_x[1] = 0;
}

bool PersonajeView::obtener_face() {
    return facingLeft;
}
void PersonajeView::crear_texturas(SDL2pp::Renderer *render) {
    
    this->animaciones.at(CAMINANDO)->crear_texturas(render);
    this->animaciones.at(CORRIENDO)->crear_texturas(render);
    this->animaciones.at(QUIETO_CLIENTE)->crear_texturas(render);
    this->animaciones.at(SALTANDO)->crear_texturas(render);
    this->animaciones.at(DISPARO_QUIETO)->crear_texturas(render);
    this->animaciones.at(DEJA_DISPARO_QUIETO)->crear_texturas(render);

}

void PersonajeView::actualizar_vista_personaje(EventoPersonaje const &evento, float dt) {
    
    this->isMoving = bool (!evento.esta_quieto);
    this->isRunning = bool (evento.esta_corriendo);
    this->isJumping = bool (evento.esta_saltando);
    
    this->ultimas_posiciones_x[0] = evento.posicion_x; //Ante ultima posicion
    
    if(isMoving) {
        this->ultimas_posiciones_x[1] = posicion_x; //Posicion mas actualizada
    }
    

    stopShooting = false;
    if(this->isShooting != evento.esta_disparando && !evento.esta_disparando) {
        stopShooting = true;
    }
    

    this->isShooting = bool (evento.esta_disparando);


    facingLeft = false;
    
    if(ultimas_posiciones_x[1] > ultimas_posiciones_x[0] && ultimas_posiciones_x[0] != ultimas_posiciones_x[1]) {
        facingLeft = true;
    }
    else if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    if(isJumping) {
        this->animaciones.at(SALTANDO)->acualizar(dt);
        this->posicion_y = evento.posicion_y;
    }

    if(this->isMoving && !this->isRunning) {
        this->animaciones.at(CAMINANDO)->acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if (this->isMoving && this->isRunning){
        this->animaciones.at(CORRIENDO)->acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if(!this->isMoving && !this->isShooting) {
        this->animaciones.at(QUIETO_CLIENTE)->acualizar(dt);
    } else if(!this->isMoving && this->isShooting) {
        this->animaciones.at(DISPARO_QUIETO)->acualizar(dt);
    }

    if(stopShooting) {
        this->animaciones.at(DEJA_DISPARO_QUIETO)->acualizar(50000000);
        //Funciona pero ocurre muy rapido
    }
    
      
}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y) {
    
    SDL2pp::Rect personaje(posicion_x-cam_x, posicion_y-cam_y, width, height);
    
    if(isMoving && !isRunning && !isJumping) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CAMINANDO)->animar(*render, personaje, flip);
    } else if(isMoving && isRunning){
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CORRIENDO)->animar(*render, personaje, flip);
    } else if(!this->isMoving && !this->isShooting) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(QUIETO_CLIENTE)->animar(*render, personaje, flip);
    } else if(!this->isMoving && this->isShooting) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(DISPARO_QUIETO)->animar(*render, personaje, flip);

    }
    
    if(isJumping) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(SALTANDO)->animar(*render, personaje, flip);
    }

    if(stopShooting && !isMoving) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(DEJA_DISPARO_QUIETO)->animar(*render, personaje, flip);
    }
    
    
}

PersonajeView::~PersonajeView() {

}