#ifndef PERSONAJEVIEW_H_
#define PERSONAJEVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include "animacion.h"
#include <memory>
#include "../common_src/evento.h"
#include <map>

#include "direcciones.h"

class PersonajeView {

    protected:

    int posicion_x;
    int posicion_y;
    int width;
    int height;
    std::map<std::string, SDL2pp::Texture> *texturas;
    std::map<std::string, Animacion> animaciones;
    bool facingLeft;
    bool isMoving;
    bool isRunning;
    bool isJumping;

    public:

    PersonajeView();

    ~PersonajeView();

    virtual SDL2pp::Texture crear_surface_y_texturas(std::string const &path_sprites, SDL2pp::Renderer *render);
    
    virtual void crear_texturas(SDL2pp::Renderer *render) = 0;

    virtual void crear_animaciones() = 0;

    virtual void referenciar_animaciones();

    virtual void actualizar_vista_personaje(EventoPersonaje const &evento,float dt);

    virtual void renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render);

};

#endif //PERSONAJEVIEW_H_