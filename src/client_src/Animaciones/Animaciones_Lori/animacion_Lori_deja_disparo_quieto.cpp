#include "animacion_Lori_deja_disparo_quieto.h"

Animacion_Lori_Deja_Disparo_Quieto::Animacion_Lori_Deja_Disparo_Quieto() : Animacion() {}

void Animacion_Lori_Deja_Disparo_Quieto::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_LORI_DEJA_DISPARO_QUIETO, render)));
    this->size_frame = 43.0F;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

Animacion_Lori_Deja_Disparo_Quieto::~Animacion_Lori_Deja_Disparo_Quieto() {}