#include "animacion_Jazz_intoxicado_quieto.h"

Animacion_Jazz_Intoxicado_Quieto::Animacion_Jazz_Intoxicado_Quieto() : Animacion() {}

void Animacion_Jazz_Intoxicado_Quieto::crear_texturas(SDL2pp::Renderer *render) {
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_JAZZ_INTOXICADO_QUIETO, render)));
    this->size_frame = 51.5F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;

} 

Animacion_Jazz_Intoxicado_Quieto::~Animacion_Jazz_Intoxicado_Quieto() {}