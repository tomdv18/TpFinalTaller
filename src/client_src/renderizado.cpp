#include "renderizado.h"
#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>

Renderizado::Renderizado() : cantidad_jugadores(1), personajeView() {}

void Renderizado::inicializar_SDL2pp() {

    this->sdl = std::make_unique<SDL2pp::SDL>(SDL_INIT_VIDEO);
    ///
}

void Renderizado::renderizar(Evento evento) {
    

    std::cout << "cantidad de jugadores:" << evento.eventos_personaje.size() << std::endl;
    
    //Despues modularizo.
    if(evento.eventos_personaje.size() >= 1) {
        std::cout << "PERSONAJE DE " << evento.eventos_personaje[0].id_jugador << std::endl;
        std::cout << "VIDA " << evento.eventos_personaje[0].vida << std::endl;
        std::cout << "EN LA POSICION " << "(" <<(int) evento.eventos_personaje[0].posicion_x << "," << evento.eventos_personaje[0].posicion_y << ")" << std::endl;
        std::cout << "ESTA QUIETO " << (int) evento.eventos_personaje[0].esta_quieto << std::endl;
        this->personajeView->actualizar_vista_personaje(evento.eventos_personaje[0].posicion_x, evento.eventos_personaje[0].posicion_y, 50000);
        render->SetDrawColor(0x80, 0x80, 0x80);
        render->Clear();
        this->personajeView->renderizar_personaje(render);
        render->Present();

    }
    
    
    if(evento.eventos_personaje.size() >= 2) {
        std::cout << "PERSONAJE DE " << evento.eventos_personaje[1].id_jugador << std::endl;
        std::cout << "VIDA " << evento.eventos_personaje[1].vida << std::endl;
        std::cout << "EN LA POSICION " << "(" << evento.eventos_personaje[1].posicion_x << "," << evento.eventos_personaje[1].posicion_y << ")" << std::endl;
    

    }

    if(evento.eventos_personaje.size() >= 3) {
        std::cout << "PERSONAJE DE " << evento.eventos_personaje[2].id_jugador << std::endl;
        std::cout << "VIDA " << evento.eventos_personaje[2].vida << std::endl;
        std::cout << "EN LA POSICION " << "(" << evento.eventos_personaje[2].posicion_x << "," << evento.eventos_personaje[2].posicion_y << ")" << std::endl;
    
    }
    

    // Presento el renderizado
    //render->Present();

}

void Renderizado::crear_ventana_y_render(const std::string& title, int width, int height) {
    this->window = std::make_unique<SDL2pp::Window>(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->render = std::make_unique<SDL2pp::Renderer>(*window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderizado::crear_personaje() {
    SDL2pp::Texture imagen_Jazz(*render, SDL2pp::Surface("../src/client_src/Images/jazz_caminando.png").SetColorKey(true, 0x000000));
    this->personajeView = new PersonajeView(std::move(imagen_Jazz));
    std::cout << "Se creo el personaje"<< std::endl;

}


Renderizado::~Renderizado() { 
    std::cout << "Renderizador joineado\n";
    delete this->personajeView;

}
