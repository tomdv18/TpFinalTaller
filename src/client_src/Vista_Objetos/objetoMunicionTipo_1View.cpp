#include "objetoMunicionTipo_1View.h"

ObjetoMunicionTipo_1View::ObjetoMunicionTipo_1View(SDL2pp::Renderer *render) : ObjetoView() {
    this->animacion = this->factory.crear_animacion_objeto(MUNICION_TIPO_1);
    this->factory.crear_texturas(render);
}


ObjetoMunicionTipo_1View::~ObjetoMunicionTipo_1View() {}