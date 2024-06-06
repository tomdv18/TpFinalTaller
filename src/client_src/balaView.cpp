#include "balaView.h"

BalaView::BalaView() : 
posicion_x(0), posicion_y(0), width(15), height(15), 
texturas_bala(nullptr),
facingLeft(false),
animacion_bala(Animacion()) {}

SDL2pp::Texture BalaView::crear_surface_y_texturas(std::string const &path_sprites, SDL2pp::Renderer *render) {
    
    SDL2pp::Surface surface(path_sprites);
    surface.SetColorKey(true, SDL_MapRGB(surface.Get()->format, 44, 102, 150));
    SDL2pp::Texture textures(*render, std::move(surface));

    return std::move(textures);
}

void BalaView::crear_texturas(SDL2pp::Renderer *render) {

    this->texturas_bala = new SDL2pp::Texture(crear_surface_y_texturas(PATH_PROYECTIL_PISTOLA, render));
    this->animacion_bala.set_texturas(texturas_bala);
    this->animacion_bala.set_size_frame(15);
}

void BalaView::actualizar(EventoBala const &evento,float dt){

    facingLeft = false;
    if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    this->animacion_bala.actualizar(dt);
    this->posicion_x = evento.posicion_x;
    this->posicion_y = evento.posicion_y;
}


 void BalaView::renderizar(SDL2pp::Renderer &render, int cam_x, int cam_y){
    
    SDL2pp::Rect bala(posicion_x -cam_x, posicion_y-cam_y, 15, 15);

    SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    animacion_bala.animar(render, bala, flip);
 
}

BalaView::~BalaView() {
    delete this->texturas_bala;
}
