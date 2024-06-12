#include "personajeJazzView.h"

PersonajeJazzView::PersonajeJazzView(EventoPersonaje &evento, SDL2pp::Renderer *render) : PersonajeView(evento), factory(this->animaciones) {
    factory.crear_animaciones_personaje();
    factory.crear_texturas(render);
}

PersonajeJazzView::~PersonajeJazzView() {}