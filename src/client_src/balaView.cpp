#include "balaView.h"

BalaView::BalaView(bool face, int x, int y) : 
posicion_x(y), posicion_y(y), width(BALA_WIDTH), height(BALA_HEIGHT), 
facingLeft(face),
animacion_bala(nullptr) {}

void BalaView::crear_animaciones() {
    this->animacion_bala = std::unique_ptr<Animacion_Bala_Pistola>(new Animacion_Bala_Pistola());
}

void BalaView::crear_texturas(SDL2pp::Renderer *render) {
    this->animacion_bala->crear_texturas(render); 
}


void BalaView::actualizar(EventoBala const &evento,float dt){

    facingLeft = false;
    if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    this->animacion_bala->acualizar(dt);
    this->posicion_x = evento.posicion_x;
    this->posicion_y = evento.posicion_y;
}


 void BalaView::renderizar(SDL2pp::Renderer &render, int cam_x, int cam_y){
    
    SDL2pp::Rect bala(posicion_x -cam_x, posicion_y-cam_y, 15, 15);

    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_NONE: SDL_FLIP_HORIZONTAL;
    animacion_bala->animar(render, bala, flip);
 
}

BalaView::~BalaView() {}
