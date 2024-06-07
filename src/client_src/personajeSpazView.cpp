#include "personajeSpazView.h"

PersonajeSpazView::PersonajeSpazView(uint32_t id_jugador, int x, int y) : PersonajeView(id_jugador, x, y) {}

void PersonajeSpazView::crear_animaciones() {

    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Spaz_Caminando()));
    this->animaciones.insert(std::make_pair(CORRIENDO, new Animacion_Spaz_Corriendo())); 
    this->animaciones.insert(std::make_pair(QUIETO_CLIENTE, new Animacion_Spaz_Quieto())); 
    this->animaciones.insert(std::make_pair(SALTANDO, new Animacion_Spaz_Saltando()));  
    this->animaciones.insert(std::make_pair(DISPARO_QUIETO, new Animacion_Spaz_Disparo_Quieto())); 
    this->animaciones.insert(std::make_pair(DEJA_DISPARO_QUIETO, new Animacion_Spaz_Deja_Disparo_Quieto())); 


}

PersonajeSpazView::~PersonajeSpazView() {}