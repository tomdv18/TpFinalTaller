#include "objetoGemaView.h"

ObjetoGemaView::ObjetoGemaView(int x, int y) : ObjetoView(x, y) {}

void ObjetoGemaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Gema()); 

}

ObjetoGemaView::~ObjetoGemaView() {}