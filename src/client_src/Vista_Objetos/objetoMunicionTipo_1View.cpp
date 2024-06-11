#include "objetoMunicionTipo_1View.h"

ObjetoMunicionTipo_1View::ObjetoMunicionTipo_1View() : ObjetoView() {
    this->crear_animacion();
}

void ObjetoMunicionTipo_1View::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion>(new Animacion_municion_tipo_1());
}

ObjetoMunicionTipo_1View::~ObjetoMunicionTipo_1View() {}