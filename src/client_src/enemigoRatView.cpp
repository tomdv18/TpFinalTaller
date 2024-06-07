#include "enemigoRatView.h"

EnemigoRatView::EnemigoRatView() : EnemigoView() {}

void EnemigoRatView::crear_animaciones() {

    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Rat_Caminando()));

}

EnemigoRatView::~EnemigoRatView() {}