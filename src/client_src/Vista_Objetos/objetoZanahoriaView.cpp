#include "objetoZanahoriaView.h"

ObjetoZanahoriaView::ObjetoZanahoriaView(SDL2pp::Renderer *render) : ObjetoView() {
    this->factory.crear_animacion_objeto(ZANAHORIA_OBJETO);
    this->factory.crear_texturas(render);
}

ObjetoZanahoriaView::~ObjetoZanahoriaView() {}