#include "renderizado.h"

Renderizado::Renderizado(Queue<Evento>& queue):
queue_eventos(queue), ventana(NULL), renderizador(NULL) {}


void Renderizado::crear_ventana() {
    this->ventana = SDL_CreateWindow("Jazz Jackrabbit 2", 100, 100, 512, 512, SDL_WINDOW_SHOWN);
    if(this->ventana == nullptr) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

void Renderizado::crear_renderizador() {

    this->renderizador = SDL_CreateRenderer(this->ventana, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->renderizador == nullptr) {
        std::cerr << "Error al crear el renderizador: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

SDL_Rect Renderizado::crear_personaje() {

    SDL_Rect personaje;
    personaje.x = 100;
    personaje.y = 100;
    personaje.h = 52;
    personaje.w = 52;
    return personaje;
}


void Renderizado::run(){
    Evento evento;
    /*
    std::cout << this->ventana << std::endl;
    crear_ventana();
    crear_renderizador();
    SDL_SetRenderDrawColor(this->renderizador, 0, 0, 0, 255);
    SDL_RenderClear(this->renderizador); // Limpiar la pantalla
    SDL_Rect personaje = std::move(crear_personaje());
    SDL_SetRenderDrawColor(this->renderizador, 255, 0, 0, 255);
    SDL_RenderFillRect(renderizador, &personaje); // Dibujar el rectángulo
    SDL_RenderPresent(renderizador);
    */
    /*
    bool running = true;
    while(running) {
 
        try {
        // Por ahora, es bloqueante, aunque no deberia.
            evento = queue_eventos.pop();
            mostrar_evento(evento);
        } catch (const ClosedQueue&) {
                // Se cerro la queue, no renderizo mas.
           break;
        }
        
    }
    */
}

Renderizado::~Renderizado() { 
    std::cout << "Renderizador joineado\n";
    this->join(); }