#include "objetoGemaView.h"

ObjetoGemaView::ObjetoGemaView() : ObjetoView() {}

void ObjetoGemaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Gema()); 

}

ObjetoGemaView::~ObjetoGemaView() {}