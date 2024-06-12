#include "enemigoRatView.h"

EnemigoRatView::EnemigoRatView(SDL2pp::Renderer *render) : EnemigoView() {
    this->animaciones.insert(std::make_pair(CAMINANDO, this->factory.crear_animacion_enemigo(ENEMIGO_RAT)));
    factory.crear_texturas(render);

}

EnemigoRatView::~EnemigoRatView() {}