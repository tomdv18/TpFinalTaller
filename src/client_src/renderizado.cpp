#include "renderizado.h"


void Renderizado::inicializar_SDL2pp() {

    this->sdl = std::make_unique<SDL2pp::SDL>(SDL_INIT_VIDEO);
}


void Renderizado::renderizar(Evento evento) {
    if (evento.tiempo_restante > 0){
            std::cout << "Tiempo Restante: " << evento.tiempo_restante << std::endl; 
        //parche provisorio
    }
    
    
    for(EventoPersonaje p: evento.eventos_personaje){
    
    // Por cada personajes que recorres, lo graficas (Santiago)
    std::cout << "PERSONAJE DE " << p.id_jugador << std::endl;
    std::cout << "VIDA " << p.vida << std::endl;
    std::cout << "EN LA POSICION " << "(" << p.posicion_x << "," << p.posicion_y << ")" << std::endl;

    this->personajeView.actualizar_vista_personaje(render, p.posicion_x, p.posicion_y);

    // Presento el renderizado
    render->Present();

    }

    
}

void Renderizado::crear_ventana_y_render(const std::string& title, int width, int height) {
    this->window = std::make_unique<SDL2pp::Window>(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->render = std::make_unique<SDL2pp::Renderer>(*window, -1, SDL_RENDERER_ACCELERATED);

}

Renderizado::~Renderizado() { 
    std::cout << "Renderizador joineado\n";

}
