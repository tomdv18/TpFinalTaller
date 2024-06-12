#include "personajeLoriView.h"

PersonajeLoriView::PersonajeLoriView(EventoPersonaje &evento) : PersonajeView(evento) {
    this->crear_animaciones();
}

void PersonajeLoriView::crear_animaciones() {
    
    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Lori_Caminando()));
    this->animaciones.insert(std::make_pair(CORRIENDO, new Animacion_Lori_Corriendo())); 
    this->animaciones.insert(std::make_pair(QUIETO_CLIENTE, new Animacion_Lori_Quieto())); 
    this->animaciones.insert(std::make_pair(SALTANDO, new Animacion_Lori_Saltando()));  
    this->animaciones.insert(std::make_pair(SALTANDO_HORIZONTAL, new Animacion_Lori_Saltando_Horizontal())); 
    this->animaciones.insert(std::make_pair(DISPARO_QUIETO, new Animacion_Lori_Disparo_Quieto())); 
    this->animaciones.insert(std::make_pair(DEJA_DISPARO_QUIETO, new Animacion_Lori_Deja_Disparo_Quieto()));
    this->animaciones.insert(std::make_pair(INTOXICADO_QUIETO, new Animacion_Lori_Intoxicado_Quieto())); 
    this->animaciones.insert(std::make_pair(INTOXICADO_CAMINANDO, new Animacion_Lori_Intoxicado_Caminando()));
    this->animaciones.insert(std::make_pair(HERIDO, new Animacion_Lori_Herido()));
    this->animaciones.insert(std::make_pair(MUERTO, new Animacion_Lori_Muerte()));
    this->animaciones.insert(std::make_pair(HABILIDAD, new Animacion_Lori_Habilidad()));
    this->animaciones.insert(std::make_pair(CAYENDO, new Animacion_Lori_Cayendo()));
    this->animaciones.insert(std::make_pair(CAYENDO_HORIZONTAL, new Animacion_Lori_Cayendo_Horizontal()));
    this->animaciones.insert(std::make_pair(DISPARO_SALTANDO, new Animacion_Lori_Disparo_Saltando()));
}

PersonajeLoriView::~PersonajeLoriView() {}