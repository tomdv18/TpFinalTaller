#include "animacion_Spaz_disparo_saltando.h"

Animacion_Spaz_Disparo_Saltando::Animacion_Spaz_Disparo_Saltando() : Animacion() {}

void Animacion_Spaz_Disparo_Saltando::crear_texturas(SDL2pp::Renderer *render) {
    
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_SPAZ_DISPARO_SALTANDO, render)));
    this->set_size_frames_y_cantida_frames();
}

Animacion_Spaz_Disparo_Saltando::~Animacion_Spaz_Disparo_Saltando() {}