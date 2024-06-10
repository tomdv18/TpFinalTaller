#ifndef BALAVIEW_H_
#define BALAVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <map>
#include "../src/common_src/evento.h"
#include "../src/common_src/codigo_objeto.h"

#include "../src/client_src/Animaciones/animacion.h"
#include "../src/client_src/Animaciones/Animaciones_Proyectiles/animacion_bala_pistola.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_1.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_2.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_3.h"

#include "../src/client_src/direcciones.h"

#define BALA_HEIGHT 15
#define BALA_WIDTH 15

class BalaView {
   
   private:

    int posicion_x;
    int posicion_y;
    int width;
    int height;
    std::unique_ptr<Animacion> animacion_bala;

    bool facingLeft;

   public:
    
    BalaView(bool face, int x, int y, uint8_t tipo);

    ~BalaView();

    void crear_animaciones(uint8_t tipo);

    void crear_texturas(SDL2pp::Renderer *render);

    void actualizar(EventoBala const &evento,float dt);

    void renderizar(SDL2pp::Renderer &render, int cam_x, int cam_y);
    
};















#endif