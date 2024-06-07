#include "animacion_Spaz_disparo_quieto.h"

Animacion_Spaz_Disparo_Quieto::Animacion_Spaz_Disparo_Quieto() : Animacion() {}

void Animacion_Spaz_Disparo_Quieto::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_SPAZ_DISPARO_QUIETO, render)));
    this->size_frame = 51.5F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Spaz_Disparo_Quieto::~Animacion_Spaz_Disparo_Quieto() {}