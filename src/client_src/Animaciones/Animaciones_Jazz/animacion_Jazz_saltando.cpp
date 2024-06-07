#include "animacion_Jazz_saltando.h"

Animacion_Jazz_Saltando::Animacion_Jazz_Saltando() : Animacion() {}

void Animacion_Jazz_Saltando::crear_texturas(SDL2pp::Renderer *render) {

    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_JAZZ_SALTANDO, render)));
    this->size_frame = 54.0F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Jazz_Saltando::~Animacion_Jazz_Saltando() {}