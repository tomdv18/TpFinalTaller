#include "animacion_Lori_herido.h"

Animacion_Lori_Herido::Animacion_Lori_Herido() : Animacion() {}

void Animacion_Lori_Herido::crear_texturas(SDL2pp::Renderer *render) {
    std::cout << 1 << std::endl;
    this->texturas = std::unique_ptr<SDL2pp::Texture>(new SDL2pp::Texture(this->crear_surface_y_texturas(PATH_LORI_HERIDO, render)));
    std::cout<< "HOLASDA 6" << std::endl;
    this->set_size_frames_y_cantida_frames();

} 

Animacion_Lori_Herido::~Animacion_Lori_Herido() {}