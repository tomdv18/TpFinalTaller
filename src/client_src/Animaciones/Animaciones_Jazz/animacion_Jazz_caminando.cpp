#include "animacion_Jazz_caminando.h"

Animacion_Jazz_Caminando::Animacion_Jazz_Caminando() : Animacion() {}

void Animacion_Jazz_Caminando::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_JAZZ_CAMINANDO, render)));
    this->size_frame = 57.0F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Jazz_Caminando::~Animacion_Jazz_Caminando() {}