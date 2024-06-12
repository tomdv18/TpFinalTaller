#include "objetoGemaView.h"

ObjetoGemaView::ObjetoGemaView(SDL2pp::Renderer *render) : ObjetoView() {
    this->animacion = this->factory.crear_animacion_objeto(GEMA_OBJETO);
    this->factory.crear_texturas(render);
}

ObjetoGemaView::~ObjetoGemaView() {}