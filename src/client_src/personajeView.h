#ifndef PERSONAJEVIEW_H_
#define PERSONAJEVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include "animacion.h"
#include <memory>
#include "../common_src/evento.h"
#include <map>

class PersonajeView {

    private:

    int posicion_x;
    int posicion_y;
    int width;
    int height;
    std::map<std::string, SDL2pp::Texture> *texturas;
    Animacion animacion_caminando;
    Animacion animacion_quieto;
    Animacion animacion_corriendo;
    bool facingLeft;
    bool isMoving;
    bool isRunning;

    public:

    PersonajeView(std::map<std::string, SDL2pp::Texture> *texturas);

    void actualizar_vista_personaje(EventoPersonaje const &evento,float dt);

    void renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render);

};

#endif //PERSONAJEVIEW_H_