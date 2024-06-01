#include "personajeView.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50

PersonajeView::PersonajeView(SDL2pp::Texture &&textura) : posicion_x(0), posicion_y(0), width(50), height(50), animacion(std::move(textura)), facingLeft(false) {}

void PersonajeView::actualizar_vista_personaje(int const &posicion_x, int const &posicion_y, float dt) {
    
    animacion.acualizar(dt);
    this->posicion_x = posicion_x;
    this->posicion_y = posicion_y;  
}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render) {
    
    SDL2pp::Rect personaje(posicion_x, posicion_y, width, height);
    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    animacion.animar(*render, personaje, flip);
    
}

