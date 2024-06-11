#include "enemigoRatView.h"

EnemigoRatView::EnemigoRatView() : EnemigoView() {
    this->crear_animaciones();
}

void EnemigoRatView::crear_animaciones() {

    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Rat_Caminando()));

}

EnemigoRatView::~EnemigoRatView() {}