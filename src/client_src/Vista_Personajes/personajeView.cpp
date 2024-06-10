#include "personajeView.h"
#include <iostream>

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50



PersonajeView::PersonajeView(EventoPersonaje &evento) : id_jugador(evento.id_jugador), posicion_x(evento.posicion_x), posicion_y(evento.posicion_y), width(PERSONAJE_WIDTH), height(PERSONAJE_HEIGHT), 
facingLeft(false), isMoving(false), isRunning(false), isJumping(false), isShooting(false), stopShooting(false),
vida(0), puntaje(0) {}

bool PersonajeView::obtener_face() {
    return facingLeft;
}
void PersonajeView::crear_texturas(SDL2pp::Renderer *render) {
    
    std::cout << "textura 5" << std::endl;
    this->animaciones.at(CAMINANDO)->crear_texturas(render);
    std::cout << "textura 6" << std::endl;
    this->animaciones.at(CORRIENDO)->crear_texturas(render);
    std::cout << "textura 7" << std::endl;
    this->animaciones.at(QUIETO_CLIENTE)->crear_texturas(render);
    std::cout << "textura 8" << std::endl;
    this->animaciones.at(SALTANDO)->crear_texturas(render);
    std::cout << "textura 9" << std::endl;
    this->animaciones.at(DISPARO_QUIETO)->crear_texturas(render);
    std::cout << "textura 10" << std::endl;
    this->animaciones.at(DEJA_DISPARO_QUIETO)->crear_texturas(render);
    std::cout << "textura 11" << std::endl;
    this->animaciones.at(INTOXICADO_QUIETO)->crear_texturas(render);
    std::cout << "textura 12" << std::endl;
    this->animaciones.at(INTOXICADO_CAMINANDO)->crear_texturas(render);
    std::cout << "textura 1" << std::endl;
    this->animaciones.at(HERIDO)->crear_texturas(render);
    std::cout << "textura 2" << std::endl;
    this->animaciones.at(MUERTO)->crear_texturas(render);
    std::cout << "textura 3" << std::endl;
    this->animaciones.at(HABILIDAD)->crear_texturas(render);
    std::cout << "textura 4" << std::endl;


}

void PersonajeView::actualizar_vista_personaje(EventoPersonaje const &evento, float dt) {
    
    this->isMoving = bool (!evento.esta_quieto);
    this->isRunning = bool (evento.esta_corriendo);
    this->isJumping = bool (evento.esta_saltando);
    this->isShooting = bool (evento.esta_disparando);
    this->isIntoxicated = bool (evento.esta_intoxicado);
    this->estado = evento.codigo_estado;
    this->posicion_x = evento.posicion_x;
    this->posicion_y = evento.posicion_y;

    facingLeft = evento.mirando_izquierda;

    if(estado == ESTADO_SALTANDO) {
        this->animaciones.at(SALTANDO)->en_loop(false);
        this->animaciones.at(SALTANDO)->acualizar(dt);
    }  else if(estado == ESTADO_CAMINANDO) {
        if (this->isIntoxicated) {
            this->animaciones.at(INTOXICADO_CAMINANDO)->en_loop(true);
            this->animaciones.at(INTOXICADO_CAMINANDO)->acualizar(dt);
        } else{
            this->animaciones.at(CAMINANDO)->en_loop(true);
            this->animaciones.at(CAMINANDO)->acualizar(dt);
        }
    } else if (estado == ESTADO_CORRIENDO){
        this->animaciones.at(CORRIENDO)->en_loop(true);
        this->animaciones.at(CORRIENDO)->acualizar(dt);
    } else if(estado == ESTADO_QUIETO) {
        if (this->isShooting) {
            this->animaciones.at(DISPARO_QUIETO)->en_loop(true);
            this->animaciones.at(DISPARO_QUIETO)->acualizar(dt);
        } else if(this->isIntoxicated){
            this->animaciones.at(INTOXICADO_QUIETO)->en_loop(true);
            this->animaciones.at(INTOXICADO_QUIETO)->acualizar(dt);
        } else {
            this->animaciones.at(QUIETO_CLIENTE)->en_loop(true);
            this->animaciones.at(QUIETO_CLIENTE)->acualizar(dt);
        }
    } else if( estado == ESTADO_HERIDO){
        this->animaciones.at(HERIDO)->en_loop(false);
        this->animaciones.at(HERIDO)->acualizar(dt*0.4);
    } else if( estado == ESTADO_MUERTO){
        this->animaciones.at(MUERTO)->en_loop(false);
        this->animaciones.at(MUERTO)->acualizar(dt*0.4);
    } else if ( estado == ESTADO_ESPECIAL){
        this->animaciones.at(HABILIDAD)->en_loop(false);
        this->animaciones.at(HABILIDAD)->acualizar(dt*0.8);
    }

    // Resetear las animaciones necesarias (No loop)
    if(estado != ESTADO_SALTANDO){
        this->animaciones.at(SALTANDO)->reset_frame();
    }

    if(estado != ESTADO_ESPECIAL){
        this->animaciones.at(HABILIDAD)->reset_frame();
    }

    if(estado != ESTADO_HERIDO){
        this->animaciones.at(HERIDO)->reset_frame();
    }

    if(estado != ESTADO_MUERTO){
        this->animaciones.at(MUERTO)->reset_frame();
    }


}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y) {
    
    SDL2pp::Rect personaje(posicion_x-cam_x, posicion_y-cam_y, width, height);
    
    // Aca un ejemplo del switch con el patron de estados
    switch (this->estado) {
    case ESTADO_QUIETO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        if(isShooting){
            animaciones.at(DISPARO_QUIETO)->animar(*render, personaje, flip);
        }else if(isIntoxicated){
            animaciones.at(INTOXICADO_QUIETO)->animar(*render, personaje, flip);
        }else{
            animaciones.at(QUIETO_CLIENTE)->animar(*render, personaje, flip);
        }
        break;
    }
    case ESTADO_CAMINANDO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        if(isIntoxicated){
            animaciones.at(INTOXICADO_CAMINANDO)->animar(*render, personaje, flip);
        }else{
            animaciones.at(CAMINANDO)->animar(*render, personaje, flip);
        }
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
    case ESTADO_HERIDO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(HERIDO)->animar(*render, personaje, flip);
        break;
    }
    case ESTADO_MUERTO:{
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(MUERTO)->animar(*render, personaje, flip);
        break;
    }
    case ESTADO_ESPECIAL:{
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(HABILIDAD)->animar(*render, personaje, flip);
    }
    default:
        break;
    }
    
}

PersonajeView::~PersonajeView() {}