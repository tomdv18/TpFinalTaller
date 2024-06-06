#include "personajeLoriView.h"

PersonajeLoriView::PersonajeLoriView(uint32_t id_jugador, int x, int y) : PersonajeView(id_jugador, x, y) {}

void PersonajeLoriView::crear_texturas(SDL2pp::Renderer *render) {

    SDL2pp::Texture texturas_caminando = crear_surface_y_texturas(PATH_LORI_CAMINANDO, render);
    SDL2pp::Texture texturas_quieto = crear_surface_y_texturas(PATH_LORI_QUIETO, render);
    SDL2pp::Texture texturas_corriendo = crear_surface_y_texturas(PATH_LORI_CORRIENDO, render);
    SDL2pp::Texture texturas_saltando = crear_surface_y_texturas(PATH_LORI_SALTANDO, render);
    SDL2pp::Texture texturas_disparo_quieto = crear_surface_y_texturas(PATH_LORI_DISPARO_QUIETO, render);
    SDL2pp::Texture texturas_deja_disparo_quieto = crear_surface_y_texturas(PATH_LORI_DEJA_DISPARO_QUIETO, render);
    this->texturas = new std::map<std::string, SDL2pp::Texture>;
    texturas->insert(std::make_pair(CAMINANDO, std::move(texturas_caminando)));
    texturas->insert(std::make_pair(QUIETO_CLIENTE, std::move(texturas_quieto)));
    texturas->insert(std::make_pair(CORRIENDO, std::move(texturas_corriendo)));
    texturas->insert(std::make_pair(SALTANDO, std::move(texturas_saltando)));
    texturas->insert(std::make_pair(DISPARO_QUIETO,std::move(texturas_disparo_quieto)));
    texturas->insert(std::make_pair(DEJA_DISPARO_QUIETO,std::move(texturas_deja_disparo_quieto)));
}

void PersonajeLoriView::crear_animaciones() {

    this->referenciar_animaciones();

    this->animaciones.at(CAMINANDO).set_size_frame(51.25F);
    this->animaciones.at(CORRIENDO).set_size_frame(54.25F);
    this->animaciones.at(QUIETO_CLIENTE).set_size_frame(44.67F);
    this->animaciones.at(SALTANDO).set_size_frame(54.0F);
    this->animaciones.at(DISPARO_QUIETO).set_size_frame(47.0F);
    this->animaciones.at(DEJA_DISPARO_QUIETO).set_size_frame(43.0F);

}

PersonajeLoriView::~PersonajeLoriView() {
    delete this->texturas;
}