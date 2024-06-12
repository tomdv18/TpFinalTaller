#include "personajeSpazView.h"

PersonajeSpazView::PersonajeSpazView(EventoPersonaje &evento, SDL2pp::Renderer *render) : PersonajeView(evento), factory(this->animaciones) {
    factory.crear_animaciones_personaje();
    factory.crear_texturas(render);
}

PersonajeSpazView::~PersonajeSpazView() {}