#ifndef OBJETO_MUNICION_TIPO_2_VIEW_H_
#define OBJETO_MUNICION_TIPO_2_VIEW_H_


#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_2.h"
#include "objetoView.h"

class ObjetoMunicionTipo_2View : public ObjetoView {

   public:
    
    explicit ObjetoMunicionTipo_2View();

    void crear_animacion() override;

    ~ObjetoMunicionTipo_2View();
};
#endif
