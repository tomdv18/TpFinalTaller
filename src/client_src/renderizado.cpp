#include "renderizado.h"
#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <map>
#include "../src/client_src/Animaciones/animacion.h"

Renderizado::Renderizado(std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews) : 
personajesViews(personajesViews), mapa_balas_pj() {}

void Renderizado::inicializar_SDL2pp() {

    this->sdl = std::make_unique<SDL2pp::SDL>(SDL_INIT_VIDEO);

}

void Renderizado::recibir_id(uint32_t id_jugador){
    this->id_jugador = id_jugador;
}

void Renderizado::iniciar_mapa(MapaCompleto &&map) {
    this->mapa = std::make_unique<Mapa>(*render, std::move(map));
}

void Renderizado::iniciar_camara(Camara &&cam) {
    this->camara = std::make_unique<Camara>(std::move(cam));
}

void Renderizado::iniciar_interfaz(int w, int h) {
    this->interfaz = std::make_unique<Interfaz>(*render, w, h, id_jugador);
    std::cout << "sdrfgdsfdsfdsf"<< std::endl;
}

bool Renderizado::renderizar(Evento evento) {
    if(evento.tiempo_restante == 0) {
        return false;
    }
    // Defino tiempo
    this->interfaz->definir_tiempo(evento.tiempo_restante);
    
    render->Clear();
    std::vector<uint32_t> jugadoresJugando = {}; // Vector de jugadores jugando actualmente
    for(EventoPersonaje evento : evento.eventos_personaje){
        jugadoresJugando.push_back(evento.id_jugador); // Agrego a los jugadores actuales
        if(personajesViews.find(evento.id_jugador) == personajesViews.end()){
            std::unique_ptr<PersonajeView> personaje;
            switch(evento.id_personaje){
                case JAZZ:
                    personaje = std::unique_ptr<PersonajeView>(new PersonajeJazzView(evento));
                    break;
                case SPAZ:
                    personaje = std::unique_ptr<PersonajeView>(new PersonajeSpazView(evento));
                    break;
                case LORI:
                    personaje = std::unique_ptr<PersonajeView>(new PersonajeLoriView(evento));    
            }
            std::cout << "MUERE ACA" << std::endl;
            personaje->crear_texturas(render.get());
            personaje->definir_vida(evento.vida);
            personaje->definir_puntos(evento.puntos);
            personaje->definir_cantidad_municion(evento.municion);
            personaje->definir_tipo_bala(evento.bala_actual);
            personajesViews[evento.id_jugador] = std::move(personaje);
            std::cout << "CREANDO JUGADOR" << std::endl;
                
        }else{
            PersonajeView &personaje = *(personajesViews.at(evento.id_jugador));
            personaje.definir_vida(evento.vida);
            personaje.definir_puntos(evento.puntos);
            personaje.definir_cantidad_municion(evento.municion);
            personaje.definir_tipo_bala(evento.bala_actual);
            personaje.actualizar_vista_personaje(evento, FRAME_RATE);
        }
    }
    // Saco a los jugadores que ya no estan jugando, es decir, se desconectaron
    {
        for (auto it = personajesViews.begin(); it != personajesViews.end(); ) {
            // Busco el ID en el vector
            if (std::find(jugadoresJugando.begin(), jugadoresJugando.end(), it->first) == jugadoresJugando.end()) {
                // Si no se encuentra, elimino la entrada del mapa
                it = personajesViews.erase(it);
            } else {
                // Si se encuentra, avanzar al siguiente ID
                ++it;
            }
        }
    }
    

    //Creacion del mapa de enemigos del juego
    for(EventoEnemigo &evento : evento.eventos_enemigos) {
        if(enemigosViews.find(evento.id_enemigo) == enemigosViews.end()) {
            std::unique_ptr<EnemigoView> enemigo;
            switch(evento.id_personaje) {
                case LIZZARD:
                    enemigo = std::unique_ptr<EnemigoView>(new EnemigoLizzardView());
                    break;
                case FENCER:
                    enemigo = std::unique_ptr<EnemigoView>(new EnemigoFencerView());
                    break;
                case RAT:
                    enemigo = std::unique_ptr<EnemigoView>(new EnemigoRatView());
                    break;
                default:
                    break;
            }
            enemigo->crear_texturas(render.get());
            enemigosViews[evento.id_enemigo] = std::move(enemigo);
            std::cout << "CREANDO ENEMIGO" << std::endl;
        } else {
            EnemigoView &enemigo = *(enemigosViews.at(evento.id_enemigo));
            enemigo.actualizar_vista_enemigo(evento, FRAME_RATE);
        }
    }
    
    //Crear de gemas, monedas y zanahorias del juego
    for(auto &evento : evento.eventos_objeto) {
        if(objetosViews.find(evento.id_objeto) == objetosViews.end()) {
            std::unique_ptr<ObjetoView> objeto;
            switch(evento.codigo_objeto) {
                case GEMA:
                    objeto = std::unique_ptr<ObjetoView>(new ObjetoGemaView());
                    break;
                case MONEDA:
                    objeto = std::unique_ptr<ObjetoView>(new ObjetoMonedaView());
                    break;
                case ZANAHORIA:
                    objeto = std::unique_ptr<ObjetoView>(new ObjetoZanahoriaView());
                    break;
                case BALA_VELOZ:
                   objeto = std::unique_ptr<ObjetoView>(new ObjetoMunicionTipo_1View());
                   break;
                case COHETE_RAPIDO:
                    objeto = std::unique_ptr<ObjetoView>(new ObjetoMunicionTipo_2View());
                    break; 
                default:
                    break;
            }
            objeto->crear_texturas(render.get());
            objetosViews[evento.id_objeto] = std::move(objeto);
            std::cout << "Creando Objeto" << std::endl;
        } else {
            ObjetoView &objeto = *(objetosViews.at(evento.id_objeto));
            objeto.actualizar_vista_objeto(evento, FRAME_RATE);
        }
    }

    //std::cout << "SALASDASDF" << std::endl;
    

    // Creacion del mapa de balas que tendra los jugadores
    for (const EventoBala &e : evento.eventos_bala) {
        mapa_balas_pj.agregarNuevoMapaBalas(e.id_jugador);
        /*
        if (balasViews.find(e.id_jugador) == balasViews.end()) {
            // Crear una nueva lista de balas para este jugador
            std::cout << "SAASASASSA\n";
                balasViews[e.id_jugador] = std::map<uint32_t, std::unique_ptr<BalaView>>();
        }else{
                
            if (balasViews[e.id_jugador].find(e.id_bala) == balasViews[e.id_jugador].end()){
            // Crear la bala
                std::unique_ptr<BalaView> b = std::make_unique<BalaView>();
                balasViews[e.id_jugador][e.id_bala] = std::move(b);
                balasViews[e.id_jugador][e.id_bala]->crear_animaciones();
                balasViews[e.id_jugador][e.id_bala]->crear_texturas(render.get());
                std::cout << "CREANDO BALA PARA JUGADOR: " << e.id_jugador << std::endl;
            }
        }
        */
    }
    // Actualiza la camara
    {
        auto it = personajesViews.find(id_jugador);
        if (it == personajesViews.end()) {
            // No hago nada.
        } else {
            // Enfoco la camara al jugador.
            PersonajeView &personajeViewPtr = *(it->second);
            camara->actualizar_posicion(personajeViewPtr.obtener_posicion_x(), personajeViewPtr.obtener_posicion_y());   
        }
    }

    // Agrego la bala
    for (const EventoBala &e : evento.eventos_bala) {
        auto it = personajesViews.find(e.id_jugador);
        PersonajeView &personajeViewPtr = *(it->second);

        // Defino la face de la bala
        std::unique_ptr<BalaView> bala_nueva = std::make_unique<BalaView>(personajeViewPtr.obtener_face(), e.posicion_x, e.posicion_y, e.tipo_bala);
        bala_nueva->crear_texturas(render.get());
        mapa_balas_pj.agregarBala(e.id_jugador, e.id_bala, std::move(bala_nueva));
    }

    // Renderizo el fondo y HUD
    {
        render->Clear();
        mapa->dibujar_fondo(*render, *camara);
        mapa->dibujar_entidades(*render, *camara);
    }

    // Renderizo balas y verifico el impacto
    for (const EventoBala &e : evento.eventos_bala) {
        BalaView* bala = mapa_balas_pj.obtenerBala(e.id_jugador, e.id_bala);
        bala->actualizar(e, FRAME_RATE);
        bala->renderizar(*render, camara->obtener_posicion_x(), camara->obtener_posicion_y());

        if( (bool)e.impacto) {
            // Nunca impacta...
            std::cout << "-----------------------------------IMPACTO-------------------------------\n"; // Nunca impacta...
            mapa_balas_pj.eliminarBala(e.id_jugador, e.id_bala);
        }
    }
    
    // Renderizo enemigos
    for(auto &enemigo : this->enemigosViews) {

        EnemigoView &e = *(enemigo.second);
        e.renderizar_enemigo(render, camara->obtener_posicion_x(), camara->obtener_posicion_y());
    }
    
    
    // Renderizo objetos
    for(auto &objeto : this->objetosViews) {
        ObjetoView &o = *(objeto.second);
        if(!o.mostrandose()){
            continue;
        }
        o.renderizar_objeto(render, camara->obtener_posicion_x(), camara->obtener_posicion_y());
    }
 
    for (auto &personaje : this->personajesViews) {

        PersonajeView &p = *(personaje.second);
        p.renderizar_personaje(render, camara->obtener_posicion_x(), camara->obtener_posicion_y());
		
	}

    interfaz->mostrar_hud(*render, personajesViews);
    render->Present();
    return true;
}

void Renderizado::crear_ventana_y_render(const std::string& title, int width, int height) {
    this->window = std::make_unique<SDL2pp::Window>(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->render = std::make_unique<SDL2pp::Renderer>(*window, -1, SDL_RENDERER_ACCELERATED);
}

void Renderizado::mostrar_tablero_final() {
    render->Clear();
    mapa->dibujar_fondo(*render, *camara);
    interfaz->mostrar_tabla_final(*render);
    render->Present();
    SDL_Delay(3000); // Muestro la tabla final por 3 segundos
}

Renderizado::~Renderizado() { 
    
    std::cout << "Renderizador joineado\n";

}
