#include "animacion_Spaz_caminando.h"
#include <iostream>
#include <exception>
#include <unistd.h>

Animacion_Spaz_Caminando::Animacion_Spaz_Caminando() : Animacion() {}

void Animacion_Spaz_Caminando::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_SPAZ_CAMINANDO, render)));
    this->size_frame = 50.625F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Spaz_Caminando::~Animacion_Spaz_Caminando() {}

