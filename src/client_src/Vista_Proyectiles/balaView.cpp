#include "balaView.h"
BalaView::BalaView(bool face, int x, int y, uint8_t tipo) : 
posicion_x(y), posicion_y(y), width(BALA_WIDTH), height(BALA_HEIGHT), 
facingLeft(face),
animacion_bala(nullptr) {
    this->crear_animaciones(tipo);
}

void BalaView::crear_animaciones(uint8_t tipo_bala) {
    switch (tipo_bala)
    {
    case CodigoObjeto::BALA_VELOZ:
        this->animacion_bala = std::unique_ptr<Animacion_municion_tipo_1>(new Animacion_municion_tipo_1());
        break;
    case CodigoObjeto::COHETE_RAPIDO:
        this->animacion_bala = std::unique_ptr<Animacion_municion_tipo_2>(new Animacion_municion_tipo_2());
        break;
    case CodigoObjeto::COHETE_TOXICO:
        this->animacion_bala = std::unique_ptr<Animacion_municion_tipo_3>(new Animacion_municion_tipo_3());
        break;
    default:
        this->animacion_bala = std::unique_ptr<Animacion_Bala_Pistola>(new Animacion_Bala_Pistola());
        break;
    }
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
