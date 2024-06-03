#include "personajeView.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50

PersonajeView::PersonajeView(std::map<std::string, SDL2pp::Texture> *texturas) : posicion_x(0), posicion_y(0), width(50), height(50), texturas(std::move(texturas)), 
animacion_caminando(std::move(texturas->at("Caminando")), 57), 
animacion_quieto(std::move(texturas->at("Quieto")), 40),
animacion_corriendo(std::move(texturas->at("Corriendo")), 67),
facingLeft(false), isMoving(false), isRunning(false) {}
//Hay que sacar del consturctor los tamaños de los frames.

void PersonajeView::actualizar_vista_personaje(EventoPersonaje const &evento, float dt) {
    
    this->isMoving = bool (evento.esta_quieto);
    this->isRunning = bool (evento.esta_corriendo);
    
    facingLeft = false;
    if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    if(this->isMoving && !this->isRunning) {
        this->animacion_caminando.acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if (this->isMoving && this->isRunning){
        this->animacion_corriendo.acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if(!this->isMoving) {
        this->animacion_quieto.acualizar(dt);
    }
      
}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render) {
    
    SDL2pp::Rect personaje(posicion_x, posicion_y, width, height);
    
    if(isMoving && !isRunning) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animacion_caminando.animar(*render, personaje, flip);
    } else if(isMoving && isRunning){
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animacion_corriendo.animar(*render, personaje, flip);
    } else if(!isMoving) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animacion_quieto.animar(*render, personaje, flip);
    }
    
    
    
}

