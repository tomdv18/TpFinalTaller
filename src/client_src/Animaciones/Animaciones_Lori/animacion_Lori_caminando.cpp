#include "animacion_Lori_caminando.h"

Animacion_Lori_Caminando::Animacion_Lori_Caminando() : Animacion() {}

void Animacion_Lori_Caminando::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_LORI_CAMINANDO, render)));
    this->size_frame = 51.25F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Lori_Caminando::~Animacion_Lori_Caminando() {}
