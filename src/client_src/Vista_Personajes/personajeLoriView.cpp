#include "personajeLoriView.h"

PersonajeLoriView::PersonajeLoriView(EventoPersonaje &evento) : PersonajeView(evento) {
    this->crear_animaciones();
}

void PersonajeLoriView::crear_animaciones() {
    
    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Lori_Caminando()));
    this->animaciones.insert(std::make_pair(CORRIENDO, new Animacion_Lori_Corriendo())); 
    this->animaciones.insert(std::make_pair(QUIETO_CLIENTE, new Animacion_Lori_Quieto())); 
    this->animaciones.insert(std::make_pair(SALTANDO, new Animacion_Lori_Saltando()));  
    this->animaciones.insert(std::make_pair(DISPARO_QUIETO, new Animacion_Lori_Disparo_Quieto())); 
    this->animaciones.insert(std::make_pair(DEJA_DISPARO_QUIETO, new Animacion_Lori_Deja_Disparo_Quieto()));
    this->animaciones.insert(std::make_pair(DISPARO_QUIETO, new Animacion_Lori_Disparo_Quieto())); 
    this->animaciones.insert(std::make_pair(DEJA_DISPARO_QUIETO, new Animacion_Lori_Deja_Disparo_Quieto()));  
}

PersonajeLoriView::~PersonajeLoriView() {}