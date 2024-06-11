#include "objetoMonedaView.h"

ObjetoMonedaView::ObjetoMonedaView() : ObjetoView() {
    this->crear_animacion();
}

void ObjetoMonedaView::crear_animacion() {

    this->animacion = std::unique_ptr<Animacion> (new Animacion_Moneda()); 

}

ObjetoMonedaView::~ObjetoMonedaView() {}