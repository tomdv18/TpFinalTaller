#ifndef ENEMIGO_FENCER_VIEW_H_
#define ENEMIGO_FENCER_VIEW_H_

#include "../src/client_src/Animaciones/Animaciones_Enemigos/animacion_Fencer_caminando.h"
#include "enemigoView.h"

class EnemigoFencerView : public EnemigoView {

   public:

    explicit EnemigoFencerView();

    void crear_animaciones() override;

    ~EnemigoFencerView();


};

#endif