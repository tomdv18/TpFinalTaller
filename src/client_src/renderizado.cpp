#include "renderizado.h"
#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <map>
#include "paths.h"

Renderizado::Renderizado() : cantidad_jugadores(1), personajeViewJazz() {}

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

        this->personajeViewJazz->actualizar_vista_personaje(evento.eventos_personaje[0], 50000);
        render->SetDrawColor(0x80, 0x80, 0x80);
        render->Clear();
        this->personajeViewJazz->renderizar_personaje(render);
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

void Renderizado::crear_personajes() {
    
    SDL2pp::Texture texturas_Jazz_caminando = crear_surface_y_texturas(PATH_JAZZ_CAMINANDO);
    SDL2pp::Texture texturas_Jazz_quieto = crear_surface_y_texturas(PATH_JAZZ_QUIETO);
    SDL2pp::Texture texturas_Jazz_corriendo = crear_surface_y_texturas(PATH_JAZZ_CORRIENDO);
    this->texturas = new std::map<std::string, SDL2pp::Texture>;
    texturas->insert(std::make_pair("Caminando", std::move(texturas_Jazz_caminando)));
    texturas->insert(std::make_pair("Quieto", std::move(texturas_Jazz_quieto)));
    texturas->insert(std::make_pair("Corriendo", std::move(texturas_Jazz_corriendo)));
    
    this->personajeViewJazz = new PersonajeView(texturas);
    std::cout << "Se creo el personaje"<< std::endl;

}

SDL2pp::Texture Renderizado::crear_surface_y_texturas(std::string const &path_sprites) {
    SDL2pp::Surface surface(path_sprites);
    surface.SetColorKey(true, SDL_MapRGB(surface.Get()->format, 44, 102, 150));
    SDL2pp::Texture textures(*render, std::move(surface));

    return std::move(textures);
}




Renderizado::~Renderizado() { 
    std::cout << "Renderizador joineado\n";
    delete this->personajeViewJazz;
    delete this->texturas;

}
