#include "enemigoBrujaView.h"

EnemigoBrujaView::EnemigoBrujaView(SDL2pp::Renderer *render) : EnemigoView() {
    this->animaciones.insert(std::make_pair(CAMINANDO, this->factory.crear_animacion_enemigo(ENEMIGO_BRUJA)));
    factory.crear_texturas(render);
}

EnemigoBrujaView::~EnemigoBrujaView() {}