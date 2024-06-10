#include "animacion_Jazz_habilidad.h"

Animacion_Jazz_Habilidad::Animacion_Jazz_Habilidad() : Animacion() {}

void Animacion_Jazz_Habilidad::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_JAZZ_HABILIDAD, render)));
    this->size_frame = texturas->GetHeight();
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Jazz_Habilidad::~Animacion_Jazz_Habilidad() {}