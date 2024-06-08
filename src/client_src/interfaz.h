#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "SDL2pp/SDL2pp.hh"
#include "SDL2pp/SDLTTF.hh"
#include "personajeView.h"

class Interfaz {
    private:
        int ancho_ventana;
        int alto_ventana;
        SDL2pp::Rect rect;
        SDL2pp::SDLTTF sdl_ttf;
        SDL2pp::Font font;
        std::map<std::string, SDL2pp::Texture*> texturas;
        uint32_t id_jugador;
        std::string texto;
        uint16_t tiempo;
        uint32_t puntos;

        void mostrar_vida();

        void mostrar_municiones();

        void mostrar_arma_seleccionada();

        void mostrar_top_3(const std::map<uint32_t, std::unique_ptr<PersonajeView>>& personajesViews);

        void mostrar_tablero_final();

    public:
        explicit Interfaz(SDL2pp::Renderer &render, int ancho, int alto, uint32_t id_jugador);

        void definir_tiempo(uint16_t tiempo);

        void definir_puntaje(uint32_t puntaje);

        void mostrar_hud(SDL2pp::Renderer &render, std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews);

        ~Interfaz();
};



#endif