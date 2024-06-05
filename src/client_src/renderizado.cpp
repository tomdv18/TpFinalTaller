#include "renderizado.h"
#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <map>
#include "paths.h"

Renderizado::Renderizado(std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews) : cantidad_jugadores(1), personajesViews(personajesViews) {}

void Renderizado::inicializar_SDL2pp() {

    this->sdl = std::make_unique<SDL2pp::SDL>(SDL_INIT_VIDEO);
    ///
}

void Renderizado::recibir_id(uint32_t id_jugador){
    this->id_jugador = id_jugador;
}

void Renderizado::renderizar(Evento evento) {

    render->SetDrawColor(0x80, 0x80, 0x80);
    
    render->Clear();
    
    for(EventoPersonaje evento : evento.eventos_personaje){
        if(personajesViews.find(evento.id_jugador) == personajesViews.end()){
            std::unique_ptr<PersonajeView> personaje;
            switch(evento.id_personaje){
                case JAZZ:
                    personaje = std::unique_ptr<PersonajeView>(new PersonajeJazzView(evento.id_jugador));
                    personaje->crear_texturas(render.get());
                    personaje->crear_animaciones();
                    
                    break;
                case SPAZ:
                    personaje = std::unique_ptr<PersonajeView>(new PersonajeSpazView(evento.id_jugador));
                    personaje->crear_texturas(render.get());
                    personaje->crear_animaciones();
                    break;
                case LORI:
                    personaje = std::unique_ptr<PersonajeView>(new PersonajeLoriView(evento.id_jugador));
                    personaje->crear_texturas(render.get());
                    personaje->crear_animaciones();
            }
            //std::unique_ptr<PersonajeView> p = std::unique_ptr<PersonajeView>(new PersonajeView(e.id_jugador,texturas));
            personajesViews[evento.id_jugador] = std::move(personaje);
            std::cout << "CREANDO JUGADOR" << std::endl;
                
        }else{
            PersonajeView &personaje = *(personajesViews.at(evento.id_jugador));
            personaje.actualizar_vista_personaje(evento,50000);
            personaje.renderizar_personaje(render);
        }
    }

    // Creacion de las balas
    /*
    for (const EventoBala &e : evento.eventos_bala) {
        if (balas.find(e.id_jugador) == balas.end()) {
            // Crear una nueva lista de balas para este jugador
                balas[e.id_jugador] = std::map<uint32_t, std::unique_ptr<BalaView>>();
        }else{
                
            if (balas[e.id_jugador].find(e.id_bala) == balas[e.id_jugador].end()){
            // Crear la bala
                std::unique_ptr<BalaView> b = std::make_unique<BalaView>(texturas_balas, e.posicion_x, e.posicion_y);
                balas[e.id_jugador][e.id_bala] = std::move(b);
                std::cout << "CREANDO BALA PARA JUGADOR: " << e.id_jugador << std::endl;
            }
        }
    }
    */


    

    render->Clear();

    // Renderizado de las balas de cada jugador
    /*
    for (const EventoBala &e : evento.eventos_bala) {
            uint32_t id_jugador = e.id_jugador;
            if (balas.find(id_jugador) != balas.end()) {
                auto& lista_balas = balas[id_jugador]; // Balas del jugador

                for (auto it = lista_balas.begin(); it != lista_balas.end(); ) {
                    auto& bala = it->second;

                    bala->actualizar(e, 50000);
                    bala->renderizar(render);

                    if (e.impacto) {
                        // Eliminar la bala de la lista si hubo impacto
                        it = lista_balas.erase(it);
                    } else {
                        ++it;
                    }
                }

                // Si la lista de balas para este jugador está vacía después de eliminar, eliminar la entrada del jugador
                if (lista_balas.empty()) {
                    balas.erase(id_jugador);
                }
            }
        }
    */






    for (auto &personaje : this->personajesViews) {

        PersonajeView &p = *(personaje.second);
        p.renderizar_personaje(render);
		
	}

    render->Present();
}

void Renderizado::crear_ventana_y_render(const std::string& title, int width, int height) {
    this->window = std::make_unique<SDL2pp::Window>(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->render = std::make_unique<SDL2pp::Renderer>(*window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderizado::crear_personajes() {
    /*
    this->personajeJazzView = new PersonajeJazzView();
    

    this->personajeLoriView = new PersonajeLoriView();
    this->personajeLoriView->crear_texturas(render.get());
    this->personajeLoriView->crear_animaciones();

    this->personajeSpazView = new PersonajeSpazView();
    this->personajeSpazView->crear_texturas(render.get());
    this->personajeSpazView->crear_animaciones();
    std::cout << "Se creo el personaje"<< std::endl;
    */

}

Renderizado::~Renderizado() { 
    
    std::cout << "Renderizador joineado\n";

}
