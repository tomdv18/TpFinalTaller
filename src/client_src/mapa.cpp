#include "mapa.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Dimensiones piso
#define PISO_WIDTH 160
#define PISO_HEIGHT 17

// Dimensiones pared
#define PARED_WIDTH 16
#define PARED_HEIGHT 160

Mapa::Mapa(SDL2pp::Renderer &render, MapaEntidades &&map): 
mapa(std::move(map)), src(), dest(){
        // Cargo las texturas (deberia estar en una clase aparte?, ver con Santiago)
        SDL2pp::Surface fondo("../src/mapas/beach_fondo.png");
        SDL2pp::Texture fondo_textura(render, (fondo));
        SDL2pp::Surface piso("../src/mapas/beach_piso.png");
        SDL2pp::Texture piso_textura(render, (piso));
        SDL2pp::Surface pared("../src/mapas/beach_pared.png");
        SDL2pp::Texture pared_textura(render, (pared));

        texturas["fondo"] = new SDL2pp::Texture(render, fondo);
        texturas["piso"] = new SDL2pp::Texture(render, piso);
        texturas["pared"] = new SDL2pp::Texture(render, pared);
};

void Mapa::dibujar_fondo(SDL2pp::Renderer &render) {
    src.x = 0;
    src.y = 0;
    src.w = SCREEN_WIDTH;
    src.h = SCREEN_HEIGHT;

    dest.x = 0;
    dest.y = 0;
    dest.w = SCREEN_WIDTH;
    dest.h = SCREEN_HEIGHT;
    render.Copy(*texturas["fondo"], src, dest);
}

void Mapa::dibujar_entidades(SDL2pp::Renderer &render, Camara &camara) {
    for (const auto& pair : mapa) {
        if (pair.first == "piso") {
            for (const auto& pos : pair.second) {
                src.w = PISO_WIDTH;
                src.h = PISO_HEIGHT;
                dest.x = pos.x - camara.obtener_posicion_x();
                dest.y = pos.y - camara.obtener_posicion_y();
                dest.w = PISO_WIDTH;
                dest.h = PISO_HEIGHT;
                render.Copy(*texturas["piso"], src, dest);
            }
        }
        if (pair.first == "pared") {
            for (const auto& pos : pair.second) {
                src.w = PARED_WIDTH;
                src.h = PARED_HEIGHT;
                dest.x = pos.x - camara.obtener_posicion_x()- PARED_WIDTH;
                dest.y = pos.y - camara.obtener_posicion_y() - PARED_HEIGHT;
                dest.w = PARED_WIDTH;
                dest.h = PARED_HEIGHT;
                render.Copy(*texturas["pared"], src, dest);
            }
        }
    }
    // Ver como mejorar
}

Mapa::~Mapa() {
    for (auto it = texturas.begin(); it != texturas.end(); ++it) {
        delete it->second; 
    }
}
