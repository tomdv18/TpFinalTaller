#include "personajeJazzView.h"

PersonajeJazzView::PersonajeJazzView(EventoPersonaje &evento) : PersonajeView(evento) {
    this->crear_animaciones();
}

void PersonajeJazzView::crear_animaciones() {
    
    this->animaciones.insert(std::make_pair(CAMINANDO, new Animacion_Jazz_Caminando()));
    this->animaciones.insert(std::make_pair(CORRIENDO, new Animacion_Jazz_Corriendo())); 
    this->animaciones.insert(std::make_pair(QUIETO_CLIENTE, new Animacion_Jazz_Quieto())); 
    this->animaciones.insert(std::make_pair(SALTANDO, new Animacion_Jazz_Saltando()));  
    this->animaciones.insert(std::make_pair(SALTANDO_HORIZONTAL, new Animacion_Jazz_Saltando_Horizontal()));
    this->animaciones.insert(std::make_pair(DISPARO_QUIETO, new Animacion_Jazz_Disparo_Quieto())); 
    this->animaciones.insert(std::make_pair(DEJA_DISPARO_QUIETO, new Animacion_Jazz_Deja_Disparo_Quieto())); 
    this->animaciones.insert(std::make_pair(INTOXICADO_QUIETO, new Animacion_Jazz_Intoxicado_Quieto));
    this->animaciones.insert(std::make_pair(INTOXICADO_CAMINANDO, new Animacion_Jazz_Intoxicado_Caminando));
    this->animaciones.insert(std::make_pair(HERIDO, new Animacion_Jazz_Herido()));
    this->animaciones.insert(std::make_pair(MUERTO, new Animacion_Jazz_Muerte()));
    this->animaciones.insert(std::make_pair(HABILIDAD, new Animacion_Jazz_Habilidad()));
    this->animaciones.insert(std::make_pair(CAYENDO, new Animacion_Jazz_Cayendo()));
    this->animaciones.insert(std::make_pair(CAYENDO_HORIZONTAL, new Animacion_Jazz_Cayendo_Horizontal()));
    this->animaciones.insert(std::make_pair(DISPARO_SALTANDO, new Animacion_Jazz_Disparo_Saltando()));
}


PersonajeJazzView::~PersonajeJazzView() {}