#include "personajeLoriView.h"

PersonajeLoriView::PersonajeLoriView(EventoPersonaje &evento, SDL2pp::Renderer *render) : PersonajeView(evento), factory(this->animaciones) {
    factory.crear_animaciones_personaje();
    factory.crear_texturas(render);
}


PersonajeLoriView::~PersonajeLoriView() {}