#include "objetoZanahoriaView.h"

ObjetoZanahoriaView::ObjetoZanahoriaView(int x, int y) : ObjetoView(x, y) {}

void ObjetoZanahoriaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Zanahoria()); 

}

ObjetoZanahoriaView::~ObjetoZanahoriaView() {}