#ifndef RENDERIZADO_H
#define RENDERIZADO_H

#include "../common_src/thread.h"
#include "../common_src/queue.h"
#include "../common_src/evento.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "protocolo_cliente.h"

class Renderizado: public Thread {
    private:
    Queue<Evento> &queue_eventos;
    SDL_Window* ventana;
    SDL_Renderer* renderizador;

    void crear_ventana();

    void crear_renderizador();

    SDL_Rect crear_personaje();
    
    public:
    explicit Renderizado(Queue<Evento>& queue);

    /**
     * Ejecuta el hilo encargado renderizar los eventos recibidos
     * del servidor.
     */
    virtual void run() override;

    /**
     * Destructor de la clase.
     */
    virtual ~Renderizado();
};

#endif
