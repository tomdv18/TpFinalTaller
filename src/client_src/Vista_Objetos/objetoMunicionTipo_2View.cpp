#include "objetoMunicionTipo_2View.h"

ObjetoMunicionTipo_2View::ObjetoMunicionTipo_2View(SDL2pp::Renderer *render) : ObjetoView() {
    this->factory.crear_animacion_objeto(MUNICION_TIPO_2);
    this->factory.crear_texturas(render);
}


ObjetoMunicionTipo_2View::~ObjetoMunicionTipo_2View() {}