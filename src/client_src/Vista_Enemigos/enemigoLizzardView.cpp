#include "enemigoLizzardView.h"

EnemigoLizzardView::EnemigoLizzardView(SDL2pp::Renderer *render) : EnemigoView() {
    this->animaciones.insert(std::make_pair(CAMINANDO, this->factory.crear_animacion_enemigo(ENEMIGO_LIZZARD)));
    factory.crear_texturas(render);
}


EnemigoLizzardView::~EnemigoLizzardView() {}