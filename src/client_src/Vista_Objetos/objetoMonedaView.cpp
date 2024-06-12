#include "objetoMonedaView.h"

ObjetoMonedaView::ObjetoMonedaView(SDL2pp::Renderer *render) : ObjetoView() {
    this->animacion = this->factory.crear_animacion_objeto(MONEDA_OBJETO);
    this->factory.crear_texturas(render);
}

ObjetoMonedaView::~ObjetoMonedaView() {}