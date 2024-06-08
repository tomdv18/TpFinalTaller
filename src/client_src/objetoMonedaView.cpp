#include "objetoMonedaView.h"

ObjetoMonedaView::ObjetoMonedaView() : ObjetoView() {}

void ObjetoMonedaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Moneda()); 

}

ObjetoMonedaView::~ObjetoMonedaView() {}