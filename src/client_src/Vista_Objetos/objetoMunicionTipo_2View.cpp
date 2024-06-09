#include "objetoMunicionTipo_2View.h"

ObjetoMunicionTipo_2View::ObjetoMunicionTipo_2View() : ObjetoView() {
    this->crear_animacion();
}

void ObjetoMunicionTipo_2View::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion>(new Animacion_municion_tipo_2());
}

ObjetoMunicionTipo_2View::~ObjetoMunicionTipo_2View() {}