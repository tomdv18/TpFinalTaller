#include "animacion_Rat_caminando.h"

Animacion_Rat_Caminando::Animacion_Rat_Caminando() : Animacion() {}


void Animacion_Rat_Caminando::crear_texturas(SDL2pp::Renderer *render) {

    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_RAT_CAMINANDO, render)));
    this->size_frame = 81.66F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
    
}

Animacion_Rat_Caminando::~Animacion_Rat_Caminando() {}