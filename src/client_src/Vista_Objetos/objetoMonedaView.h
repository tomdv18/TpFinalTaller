#ifndef OBJETO_MONEDA_VIEW_H_
#define OBJETO_MONEDA_VIEW_H_

#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_moneda.h"
#include "objetoView.h"

class ObjetoMonedaView : public ObjetoView {
    
   public:

    explicit ObjetoMonedaView();

    void crear_animacion() override;

    ~ObjetoMonedaView();
};

#endif