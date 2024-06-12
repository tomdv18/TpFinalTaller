#include "objetoMunicionTipo_3View.h"

ObjetoMunicionTipo_3View::ObjetoMunicionTipo_3View(SDL2pp::Renderer *render) : ObjetoView() {
    this->animacion = this->factory.crear_animacion_objeto(MUNICION_TIPO_3);
    this->factory.crear_texturas(render);
}

ObjetoMunicionTipo_3View::~ObjetoMunicionTipo_3View() {}