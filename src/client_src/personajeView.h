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
    
    uint32_t id_jugador;
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

    PersonajeView(uint32_t id_jugador);

    ~PersonajeView();

    virtual SDL2pp::Texture crear_surface_y_texturas(std::string const &path_sprites, SDL2pp::Renderer *render);
    
    virtual void crear_texturas(SDL2pp::Renderer *render) = 0;

    virtual void crear_animaciones() = 0;

    virtual void referenciar_animaciones();

    virtual void actualizar_vista_personaje(EventoPersonaje const &evento,float dt);

    virtual void renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y);

    virtual int obtener_posicion_x() {
        return posicion_x;
    }

    virtual int obtener_posicion_y() {
        return posicion_y;
    }

    virtual void definir_posicion_x(int x) {
        posicion_x = x;
    }

    virtual void definir_posicion_y(int y) {
        posicion_y = y;
    }
};

#endif //PERSONAJEVIEW_H_