#ifndef PERSONAJEVIEW_H_
#define PERSONAJEVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include "animacion.h"
#include <memory>

class PersonajeView {

    private:

    int posicion_x;
    int posicion_y;
    int width;
    int height;
    Animacion animacion;
    bool facingLeft;

    public:

    PersonajeView(SDL2pp::Texture &&textura);

    void actualizar_vista_personaje(int const &posicion_x, int const &posicion_y, float dt);

    void renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render);

};

#endif //PERSONAJEVIEW_H_