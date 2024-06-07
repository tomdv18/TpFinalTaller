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
#include "enemigoView.h"
#include "enemigoLizzardView.h"
#include "enemigoFencerView.h"
#include "enemigoRatView.h"
#include "direcciones.h"
#include "mapa.h"
#include "camara.h"
#include "balasPersonajes.h"

#include "protocolo_cliente.h"

class Renderizado {
    
   private:
    std::unique_ptr<SDL2pp::SDL> sdl;
    std::unique_ptr<SDL2pp::Window> window;
    std::unique_ptr<SDL2pp::Renderer> render;
    std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews;
    std::map<uint32_t, std::unique_ptr<EnemigoView>> enemigosViews;
    BalasPersonajes mapa_balas_pj;
    uint32_t id_jugador;
    std::unique_ptr<Mapa> mapa;
    std::unique_ptr<Camara> camara;

    // Map id_jugador, map de sus balas -> id_bala, balaView
    //std::map<uint32_t, std::map<uint32_t, std::unique_ptr<BalaView>>> balas;

   public:

    explicit Renderizado(std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews);
    
    virtual ~Renderizado();

    public: 

    void inicializar_SDL2pp();

    void recibir_id(uint32_t id_jugador);

    void crear_ventana_y_render(const std::string& title, int width, int height);

    void renderizar(Evento evento);

    void iniciar_mapa(MapaEntidades &&map);

    void iniciar_camara(Camara &&cam);

};

#endif
