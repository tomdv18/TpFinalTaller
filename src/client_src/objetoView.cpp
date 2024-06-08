#include "objetoView.h"

ObjetoView::ObjetoView() : posicion_x(0), posicion_y(0), animacion(nullptr), widht(25), height(25) {}

void ObjetoView::crear_texturas(SDL2pp::Renderer *render)  {
    
    this->animacion->crear_texturas(render);
}

void ObjetoView::actualizar_vista_objeto(EventoObjeto &evento, float df) {

    this->posicion_x = evento.posicion_x;
    this->posicion_y = evento.posicion_y;
    this->animacion->acualizar(df);
}

void ObjetoView::renderizar_objeto(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y) {

    SDL2pp::Rect objeto(posicion_x-cam_x, posicion_y-cam_y, widht, height);
    
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
    this->animacion->animar(*render, objeto, flip);
}

ObjetoView::~ObjetoView() {}