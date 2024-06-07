#include "enemigoView.h"

EnemigoView::EnemigoView() : posicion_x(0), posicion_y(0), width(50), height(50), 
facingLeft(false), isMoving(false) {}

void EnemigoView::crear_texturas(SDL2pp::Renderer *render) {
    
    this->animaciones.at(CAMINANDO)->crear_texturas(render);

}

void EnemigoView::actualizar_vista_enemigo(EventoEnemigo &evento, float df) {

    this->isMoving = true;
    if(this->isMoving) {
        this->animaciones.at(CAMINANDO)->acualizar(df);
    }
}

void EnemigoView::renderizar_enemigo(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y) {

    SDL2pp::Rect enemigo(posicion_x-cam_x, posicion_y-cam_y, width, height);

    if(this->isMoving) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CAMINANDO)->animar(*render, enemigo, flip);
    }
}

EnemigoView::~EnemigoView() {}
