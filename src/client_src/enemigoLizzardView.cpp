#include "enemigoLizzardView.h"

EnemigoLizzardView::EnemigoLizzardView() : EnemigoView() {}

void EnemigoLizzardView::crear_animaciones() {

    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Lizzard_Caminando()));

}

EnemigoLizzardView::~EnemigoLizzardView() {}