#include "animacion_bala_pistola.h"

Animacion_Bala_Pistola::Animacion_Bala_Pistola() : Animacion() {}

void Animacion_Bala_Pistola::crear_texturas(SDL2pp::Renderer *render) {

    this->texturas = std::unique_ptr<SDL2pp::Texture> (new SDL2pp::Texture(crear_surface_y_texturas(PATH_PROYECTIL_PISTOLA, render)));
    this->size_frame = 15;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
    std::cout <<"LA CANTAD ES : " <<cantidad_frames;
}

Animacion_Bala_Pistola::~Animacion_Bala_Pistola() {}