#ifndef MAPA_H
#define MAPA_H

#include "SDL2pp/SDL2pp.hh"
#include "camara.h"
#include "../common_src/evento.h"

class Mapa {
    private:
        MapaEntidades mapa;
        SDL2pp::Rect src;
        SDL2pp::Rect dest;
        std::map<std::string, SDL2pp::Texture*> texturas;

    public:
        explicit Mapa(SDL2pp::Renderer &render, MapaEntidades &&map);

        void dibujar_fondo(SDL2pp::Renderer &render);

        void dibujar_entidades(SDL2pp::Renderer &render, Camara &camara);

        ~Mapa();

};

#endif