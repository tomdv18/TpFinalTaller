#ifndef RENDERIZADO_H
#define RENDERIZADO_H

#include "../common_src/thread.h"
#include "../common_src/queue.h"
#include "../common_src/evento.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include "personajeView.h"

#include "protocolo_cliente.h"

class Renderizado {
    private:
    //Queue<Evento> &queue_eventos;
    private:
    std::unique_ptr<SDL2pp::SDL> sdl;
    std::unique_ptr<SDL2pp::Window> window;
    std::unique_ptr<SDL2pp::Renderer> render;
    PersonajeView personajeView;

    
    public:

    Renderizado() = default;
    virtual ~Renderizado();

    public: 

    void inicializar_SDL2pp();

    void crear_ventana_y_render(const std::string& title, int width, int height);

    void renderizar(Evento evento);

};

#endif
