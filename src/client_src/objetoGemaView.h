#ifndef OBJETO_GEMA_VIEW_H_
#define OBJETO_GEMA_VIEW_H_

#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_gema.h"
#include "objetoView.h"

class ObjetoGemaView : public ObjetoView {

   public:

    explicit ObjetoGemaView();

    void crear_animacion() override;

    ~ObjetoGemaView();
};

#endif