#include "enemigoFencerView.h"

EnemigoFencerView::EnemigoFencerView(SDL2pp::Renderer *render) : EnemigoView() {
    this->animaciones.insert(std::make_pair(CAMINANDO, this->factory.crear_animacion_enemigo(ENEMIGO_FENCER)));
    factory.crear_texturas(render);
}

EnemigoFencerView::~EnemigoFencerView() {}