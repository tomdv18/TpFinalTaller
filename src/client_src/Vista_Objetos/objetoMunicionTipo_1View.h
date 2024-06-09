#ifndef OBJETO_MUNICION_TIPO_1_VIEW_H_
#define OBJETO_MUNICION_TIPO_1_VIEW_H_


#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_1.h"
#include "objetoView.h"

class ObjetoMunicionTipo_1View : public ObjetoView {

   public:
    
    explicit ObjetoMunicionTipo_1View();

    void crear_animacion() override;

    ~ObjetoMunicionTipo_1View();
};
#endif
