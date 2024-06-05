#include "balaView.h"

BalaView::BalaView(std::map<std::string, std::shared_ptr<SDL2pp::Texture>> texturas, uint32_t pos_x, uint32_t pos_y) : 
texturas(texturas),posicion_x(pos_x), posicion_y(pos_y), width(50), height(50),
animacion_bala(texturas.at("Disparando"))
{
    facingLeft = false;
}

void BalaView::actualizar(EventoBala const &evento,float dt){

    facingLeft = false;
    if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    this->animacion_bala.update(dt);
    this->posicion_x = evento.posicion_x;
    this->posicion_y = evento.posicion_y;
}


 void BalaView::renderizar(SDL2pp::Renderer &render){
     SDL2pp::Rect bala(posicion_x, posicion_y, 15, 15);

    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    animacion_bala.render(render, bala, flip);
 }
