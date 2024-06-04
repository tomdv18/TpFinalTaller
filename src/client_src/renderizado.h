#ifndef RENDERIZADO_H
#define RENDERIZADO_H

#include "../common_src/thread.h"
#include "../common_src/queue.h"
#include "../common_src/evento.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include "personajeView.h"
#include "personajeJazzView.h"
#include "personajeLoriView.h"
#include "personajeSpazView.h"
#include "direcciones.h"

#include "protocolo_cliente.h"

class Renderizado {
    private:
    //Queue<Evento> &queue_eventos;
    private:
    std::unique_ptr<SDL2pp::SDL> sdl;
    std::unique_ptr<SDL2pp::Window> window;
    std::unique_ptr<SDL2pp::Renderer> render;
    int cantidad_jugadores;
    PersonajeJazzView *personajeJazzView;
    PersonajeLoriView *personajeLoriView;
    PersonajeSpazView *personajeSpazView;

    public:

    Renderizado();
    virtual ~Renderizado();

    public: 

    void inicializar_SDL2pp();

    void crear_ventana_y_render(const std::string& title, int width, int height);

    void crear_personajes();

    void renderizar(Evento evento);

    void asociar_render(SDL2pp::Renderer* render);

};

#endif
