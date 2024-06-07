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
    this->isShooting = bool (evento.esta_disparando);
    this->estado = evento.codigo_estado;
    this->posicion_x = evento.posicion_x;
    this->posicion_y = evento.posicion_y;

    facingLeft = evento.mirando_izquierda;

    if(estado == ESTADO_SALTANDO) {
        this->animaciones.at(SALTANDO)->en_loop(false);
        this->animaciones.at(SALTANDO)->acualizar(dt);
    } else if(estado == ESTADO_CAMINANDO) {
        this->animaciones.at(CAMINANDO)->en_loop(true);
        this->animaciones.at(CAMINANDO)->acualizar(dt);
    } else if (estado == ESTADO_CORRIENDO){
        this->animaciones.at(CORRIENDO)->en_loop(true);
        this->animaciones.at(CORRIENDO)->acualizar(dt);
    } else if(estado == ESTADO_QUIETO) {
        if (this->isShooting) {
            this->animaciones.at(DISPARO_QUIETO)->en_loop(true);
            this->animaciones.at(DISPARO_QUIETO)->acualizar(dt);
        } else {
            this->animaciones.at(QUIETO_CLIENTE)->en_loop(true);
            this->animaciones.at(QUIETO_CLIENTE)->acualizar(dt);
            this->animaciones.at(SALTANDO)->reset_frame();
        }
    } 
}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y) {
    
    SDL2pp::Rect personaje(posicion_x-cam_x, posicion_y-cam_y, width, height);
    
    // Aca un ejemplo del switch con el patron de estados
    switch (this->estado)
    {
    case ESTADO_QUIETO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        if(isShooting){
            animaciones.at(DISPARO_QUIETO)->animar(*render, personaje, flip);
        }else{
            animaciones.at(QUIETO_CLIENTE)->animar(*render, personaje, flip);
        }
        break;
    }
    case ESTADO_CAMINANDO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CAMINANDO)->animar(*render, personaje, flip);
        break;
    }
    case ESTADO_CORRIENDO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CORRIENDO)->animar(*render, personaje, flip);
        break;
    }
    case ESTADO_SALTANDO:{
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(SALTANDO)->animar(*render, personaje, flip);
        break;
    }
    default:
        break;
    }


    /*
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
    */
    
    
}

PersonajeView::~PersonajeView() {

}