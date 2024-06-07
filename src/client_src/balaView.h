#ifndef BALAVIEW_H_
#define BALAVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <map>
#include "../common_src/evento.h"
#include "../src/client_src/Animaciones/animacion.h"
#include "../src/client_src/Animaciones/Animaciones_Proyectiles/animacion_bala_pistola.h"
#include "direcciones.h"

#define BALA_HEIGHT 15
#define BALA_WIDTH 15

class BalaView{
   
   private:

    int posicion_x;
    int posicion_y;
    int width;
    int height;
    std::unique_ptr<Animacion> animacion_bala;

    bool facingLeft;

   public:
    
    BalaView(bool face, int x, int y);

    ~BalaView();

    void crear_animaciones();

    void crear_texturas(SDL2pp::Renderer *render);

    void actualizar(EventoBala const &evento,float dt);

    void renderizar(SDL2pp::Renderer &render, int cam_x, int cam_y);
    
};















#endif