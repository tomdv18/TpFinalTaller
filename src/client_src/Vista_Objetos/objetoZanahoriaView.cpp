#include "objetoZanahoriaView.h"

ObjetoZanahoriaView::ObjetoZanahoriaView() : ObjetoView() {
    this->crear_animacion();
}

void ObjetoZanahoriaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Zanahoria()); 

}

ObjetoZanahoriaView::~ObjetoZanahoriaView() {}