#include "animacion.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#define FRAME_RATE 50000


Animacion::Animacion() : texturas(nullptr), frame_actual(0),
cantidad_frames(1), 
size_frame(1), elapsed(0.0F) {}

Animacion::~Animacion() {}

void Animacion::set_size_frame(float size_frame) {
    this->size_frame = size_frame;
    this->cantidad_frames = texturas->GetWidth() / this->size_frame;
}

void Animacion::acualizar(float dt) {
    this->elapsed += dt;

    while(this->elapsed > FRAME_RATE) {
        this->frame_actual += 1;
        this->frame_actual = this->frame_actual % this->cantidad_frames; 
        this->elapsed -= FRAME_RATE;
    }

}

void Animacion::set_texturas(SDL2pp::Texture* texturas) {
    this->texturas = texturas;

}

void Animacion::animar(SDL2pp::Renderer &render, SDL2pp::Rect dest, SDL_RendererFlip &flipType) {
    
    render.Copy(*texturas,
    SDL2pp::Rect(this->size_frame * this->frame_actual, 0, this->size_frame, texturas->GetHeight()),
    dest, 0.0, SDL2pp::NullOpt, flipType);

}

