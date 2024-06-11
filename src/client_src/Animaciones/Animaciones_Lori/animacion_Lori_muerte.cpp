#include "animacion_Lori_muerte.h"

Animacion_Lori_Muerte::Animacion_Lori_Muerte() : Animacion() {}

void Animacion_Lori_Muerte::crear_texturas(SDL2pp::Renderer *render) {
    std::cout << 3 << std::endl;
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_LORI_MUERTE, render)));
    std::cout<< "HOLASDA 7" << std::endl;
    this->set_size_frames_y_cantida_frames();
}

Animacion_Lori_Muerte::~Animacion_Lori_Muerte() {}