#include "animacion.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#define FRAME_RATE 50000

Animacion::Animacion(SDL2pp::Texture &&textura, int size_frame) : textura(std::move(textura)), frame_actual(0),
cantidad_frames(this->textura.GetWidth() / size_frame), 
size_frame(size_frame), elapsed(0.0F) {
    assert(this->cantidad_frames > 0);
    assert(this->size_frame > 0);
}

Animacion::~Animacion() {}

void Animacion::acualizar(float dt) {
    this->elapsed += dt;
    std::cout << elapsed << std::endl;

    while(this->elapsed > FRAME_RATE) {
        this->frame_actual += 1;
        this->frame_actual = this->frame_actual % this->cantidad_frames; 
        this->elapsed -= FRAME_RATE;
        std::cout << "EL frame_actual es: " << frame_actual << std::endl;
    }

}

void Animacion::animar(SDL2pp::Renderer &render, SDL2pp::Rect dest, SDL_RendererFlip &flipType) {
    
    render.Copy(this->textura,
    SDL2pp::Rect(this->size_frame * this->frame_actual, 0, this->size_frame, textura.GetHeight()),
    dest, 0.0, SDL2pp::NullOpt, flipType);

}

