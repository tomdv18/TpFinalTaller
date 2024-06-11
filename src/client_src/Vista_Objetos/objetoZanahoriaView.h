#ifndef OBJETO_ZANAHORIA_VIEW_H_
#define OBJETO_ZANAHORIA_VIEW_H_

#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_zanahoria.h"
#include "objetoView.h"

class ObjetoZanahoriaView : public ObjetoView {

   public:

    explicit ObjetoZanahoriaView();

    void crear_animacion() override;

    ~ObjetoZanahoriaView();
};

#endif