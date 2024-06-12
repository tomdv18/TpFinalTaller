#ifndef ENEMIGO_VIEW_H_
#define ENEMIGO_VIEW_H_

#include <map>
#include "../src/client_src/Animaciones/animacion.h"
#include "../src/client_src/direcciones.h"
#include "../src/common_src/evento.h"
#include "enemigoViewFactory.h"


class EnemigoView {
   
   protected:
    
    int posicion_x;
    int posicion_y;
    int width;
    int height;
    std::map<std::string, std::unique_ptr<Animacion>> animaciones;
    EnemigoViewFactory factory;
    bool facingLeft;
    bool isMoving;

   public:

    explicit EnemigoView();

    virtual void actualizar_vista_enemigo(EventoEnemigo &evento, float df);

    virtual void renderizar_enemigo(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y);

    virtual ~EnemigoView();
};


#endif 