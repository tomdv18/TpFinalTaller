#include "../src/client_src/Animaciones/animacion.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

Animacion::Animacion() : texturas(nullptr), frame_actual(0),
cantidad_frames(1), 
size_frame(1), elapsed(0.0F) {}

Animacion::~Animacion() {}

SDL2pp::Texture Animacion::crear_surface_y_texturas(std::string const &path_sprites, SDL2pp::Renderer *render) {
    SDL2pp::Surface surface(path_sprites);
    surface.SetColorKey(true, SDL_MapRGB(surface.Get()->format, 44, 102, 150));
    SDL2pp::Texture textures(*render, std::move(surface));

    return std::move(textures);
}

void Animacion::acualizar(float dt) {
    this->elapsed += dt;

    while(this->elapsed > FRAME_RATE) {
        this->frame_actual += 1;
        this->frame_actual = this->frame_actual % this->cantidad_frames; 
        this->elapsed -= FRAME_RATE;
        //std::cout << "El frame es: "<<  frame_actual << std::endl;
    }

}

void Animacion::animar(SDL2pp::Renderer &render, SDL2pp::Rect dest, SDL_RendererFlip &flipType) {
    
    render.Copy(*texturas,
    SDL2pp::Rect(this->size_frame * this->frame_actual, 0, this->size_frame, texturas->GetHeight()),
    dest, 0.0, SDL2pp::NullOpt, flipType);

}

