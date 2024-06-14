#include "enemigoFencerView.h"

EnemigoFencerView::EnemigoFencerView(SDL2pp::Renderer *render) : EnemigoView() {
    this->animaciones.insert(std::make_pair(CAMINANDO, this->factory.crear_animacion_enemigo(ENEMIGO_FENCER)));
    this->animaciones.insert(std::make_pair(DESAPARECER, this->factory.crear_animacion_enemigo(DESAPARECER)));
    this->factory.crear_texturas(render);
    width = 70;
    height = 50;
}

EnemigoFencerView::~EnemigoFencerView() {}