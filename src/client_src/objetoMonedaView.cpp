#include "objetoMonedaView.h"

ObjetoMonedaView::ObjetoMonedaView(int x, int y) : ObjetoView(x, y) {}

void ObjetoMonedaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Moneda()); 

}

ObjetoMonedaView::~ObjetoMonedaView() {}