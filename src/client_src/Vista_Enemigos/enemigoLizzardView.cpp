#include "enemigoLizzardView.h"

EnemigoLizzardView::EnemigoLizzardView() : EnemigoView() {
    this->crear_animaciones();
}

void EnemigoLizzardView::crear_animaciones() {

    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Lizzard_Caminando()));

}

EnemigoLizzardView::~EnemigoLizzardView() {}