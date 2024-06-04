#include "renderizado.h"
#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <map>
#include "paths.h"

Renderizado::Renderizado() : cantidad_jugadores(1), personajeJazzView(nullptr) {}

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
        std::cout << "ESTA CORRIENDO " << (int) evento.eventos_personaje[0].esta_corriendo << std::endl;
        std::cout << "ESTA Saltando " << (int) evento.eventos_personaje[0].esta_saltando << std::endl;
        render->SetDrawColor(0x80, 0x80, 0x80);
    
        render->Clear();
        this->personajeJazzView->actualizar_vista_personaje(evento.eventos_personaje[0], 50000);

        this->personajeJazzView->renderizar_personaje(render);
        render->Present();

    }
    
    
    if(evento.eventos_personaje.size() >= 2) {
        std::cout << "PERSONAJE DE " << evento.eventos_personaje[1].id_jugador << std::endl;
        std::cout << "VIDA " << evento.eventos_personaje[1].vida << std::endl;
        std::cout << "EN LA POSICION " << "(" << evento.eventos_personaje[1].posicion_x << "," << evento.eventos_personaje[1].posicion_y << ")" << std::endl;
    
        this->personajeLoriView->actualizar_vista_personaje(evento.eventos_personaje[1], 50000);

        this->personajeLoriView->renderizar_personaje(render);
        render->Present();
    }

    if(evento.eventos_personaje.size() >= 3) {
        std::cout << "PERSONAJE DE " << evento.eventos_personaje[2].id_jugador << std::endl;
        std::cout << "VIDA " << evento.eventos_personaje[2].vida << std::endl;
        std::cout << "EN LA POSICION " << "(" << evento.eventos_personaje[2].posicion_x << "," << evento.eventos_personaje[2].posicion_y << ")" << std::endl;
        
        this->personajeSpazView->actualizar_vista_personaje(evento.eventos_personaje[2], 50000);

        this->personajeSpazView->renderizar_personaje(render);
        render->Present();
    }
    

    // Presento el renderizado
    //render->Present();

}

void Renderizado::crear_ventana_y_render(const std::string& title, int width, int height) {
    this->window = std::make_unique<SDL2pp::Window>(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->render = std::make_unique<SDL2pp::Renderer>(*window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderizado::crear_personajes() {
    
    this->personajeJazzView = new PersonajeJazzView();
    this->personajeJazzView->crear_texturas(render.get());
    this->personajeJazzView->crear_animaciones();

    this->personajeLoriView = new PersonajeLoriView();
    this->personajeLoriView->crear_texturas(render.get());
    this->personajeLoriView->crear_animaciones();

    this->personajeSpazView = new PersonajeSpazView();
    this->personajeSpazView->crear_texturas(render.get());
    this->personajeSpazView->crear_animaciones();
    std::cout << "Se creo el personaje"<< std::endl;

}

Renderizado::~Renderizado() { 
    
    delete this->personajeJazzView;
    delete this->personajeLoriView;
    delete this->personajeSpazView;
    std::cout << "Renderizador joineado\n";

}
