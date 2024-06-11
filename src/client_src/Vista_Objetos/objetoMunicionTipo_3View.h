#ifndef OBJETO_MUNICION_TIPO_3_VIEW_H_
#define OBJETO_MUNICION_TIPO_3_VIEW_H_


#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_3.h"
#include "objetoView.h"

class ObjetoMunicionTipo_3View : public ObjetoView {

   public:
    
    explicit ObjetoMunicionTipo_3View();

    void crear_animacion() override;

    ~ObjetoMunicionTipo_3View();
};
#endif
