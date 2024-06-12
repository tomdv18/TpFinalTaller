#ifndef OBJETO_VIEW_H_
#define OBJETO_VIEW_H_

#include "../src/client_src/Animaciones/animacion.h"
#include "../src/common_src/evento.h"
#include "objetoViewFactory.h"

class ObjetoView {

   protected:
    
    int posicion_x;
    int posicion_y;
    int widht;
    int height;
    std::unique_ptr<Animacion> animacion;
    ObjetoViewFactory factory;
    bool mostrarse;

   public:

    explicit ObjetoView();

    virtual bool mostrandose();

    virtual void actualizar_vista_objeto(EventoObjeto &evento, float df);

    virtual void renderizar_objeto(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y);

    virtual ~ObjetoView();
};

#endif