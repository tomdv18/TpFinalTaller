#ifndef PERSONAJE_SPAZ_VIEW_H_
#define PERSONAJE_SPAZ_VIEW_H_

#include "personajeView.h"

class PersonajeSpazView : public PersonajeView {

    public:
    
    PersonajeSpazView(uint32_t id_jugador);

    void crear_texturas(SDL2pp::Renderer *render) override;

    void crear_animaciones() override;

    ~PersonajeSpazView();

};

#endif