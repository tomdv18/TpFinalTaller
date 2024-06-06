#ifndef BALAVIEW_H_
#define BALAVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <map>
#include "../common_src/evento.h"
#include "animacion.h"
#include "direcciones.h"

#define BALA_HEIGHT 50
#define BALA_WIDTH 50

class BalaView{
   
   private:
    SDL2pp::Texture *texturas_bala;
    int posicion_x;
    int posicion_y;
    int width;
    int height;
    Animacion animacion_bala;

    bool facingLeft;

   public:
    
    BalaView();

    ~BalaView();

    SDL2pp::Texture crear_surface_y_texturas(std::string const &path_sprite, SDL2pp::Renderer *render);

    void crear_texturas(SDL2pp::Renderer *render);

    void actualizar(EventoBala const &evento,float dt);

    void renderizar(SDL2pp::Renderer &render, int cam_x, int cam_y);
};















#endif