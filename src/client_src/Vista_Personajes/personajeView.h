#ifndef PERSONAJEVIEW_H_
#define PERSONAJEVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include "../src/client_src/Animaciones/animacion.h"
#include "../src/common_src/codigo_estado.h"
#include <memory>
#include "../src/common_src/evento.h"
#include <map>
#include "../src/client_src/direcciones.h"

class PersonajeView {

    protected:
    
    uint32_t id_jugador;
    int vida;
    //int puntaje;
    //arma seleccionada?
    //municiones?
    int posicion_x;
    int posicion_y;
    int width;
    int height;
    std::map<std::string, std::unique_ptr<Animacion>> animaciones;
    bool facingLeft;
    bool isMoving;
    bool isRunning;
    bool isJumping;
    bool isShooting;
    bool stopShooting;


    uint8_t estado; // Almacena el estado actual del personaje

    public:

    virtual bool obtener_face();

    PersonajeView(EventoPersonaje &evento);

    virtual ~PersonajeView();
    
    virtual void crear_texturas(SDL2pp::Renderer *render);

    virtual void crear_animaciones() = 0;

    virtual void actualizar_vista_personaje(EventoPersonaje const &evento,float dt);

    virtual void renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y);

    virtual void definir_vida(uint8_t vida) {
        this->vida = int(vida);
    }

    virtual uint8_t obtener_vida() {
        return this->vida;
    }

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