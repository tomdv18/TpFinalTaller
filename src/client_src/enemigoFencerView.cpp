#include "enemigoFencerView.h"

EnemigoFencerView::EnemigoFencerView() : EnemigoView() {}

void EnemigoFencerView::crear_animaciones() {

    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Fencer_Caminando()));

}

EnemigoFencerView::~EnemigoFencerView() {}