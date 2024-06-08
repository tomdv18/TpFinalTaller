#include "objetoZanahoriaView.h"

ObjetoZanahoriaView::ObjetoZanahoriaView() : ObjetoView() {}

void ObjetoZanahoriaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Zanahoria()); 

}

ObjetoZanahoriaView::~ObjetoZanahoriaView() {}