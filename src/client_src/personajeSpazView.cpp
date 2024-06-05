#include "personajeSpazView.h"

PersonajeSpazView::PersonajeSpazView(uint32_t id_jugador) : PersonajeView(id_jugador) {}

void PersonajeSpazView::crear_texturas(SDL2pp::Renderer *render) {

    SDL2pp::Texture texturas_caminando = crear_surface_y_texturas(PATH_SPAZ_CAMINANDO, render);
    SDL2pp::Texture texturas_quieto = crear_surface_y_texturas(PATH_SPAZ_QUIETO, render);
    SDL2pp::Texture texturas_corriendo = crear_surface_y_texturas(PATH_SPAZ_CORRIENDO, render);
    SDL2pp::Texture texturas_saltando = crear_surface_y_texturas(PATH_SPAZ_SALTANDO, render);
    this->texturas = new std::map<std::string, SDL2pp::Texture>;
    texturas->insert(std::make_pair(CAMINANDO, std::move(texturas_caminando)));
    texturas->insert(std::make_pair(QUIETO_CLIENTE, std::move(texturas_quieto)));
    texturas->insert(std::make_pair(CORRIENDO, std::move(texturas_corriendo)));
    texturas->insert(std::make_pair(SALTANDO, std::move(texturas_saltando)));
}

void PersonajeSpazView::crear_animaciones() {

    this->referenciar_animaciones();

    this->animaciones.at(CAMINANDO).set_size_frame(50.625F);
    this->animaciones.at(CORRIENDO).set_size_frame(51.5F);
    this->animaciones.at(QUIETO_CLIENTE).set_size_frame(38);
    this->animaciones.at(SALTANDO).set_size_frame(54.0F);

}

PersonajeSpazView::~PersonajeSpazView() {
    delete this->texturas;
}