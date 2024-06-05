#ifndef PERSONAJE_LORI_VIEW_H_
#define PERSONAJE_LORI_VIEW_H_

#include "personajeView.h"

class PersonajeLoriView : public PersonajeView {

    public:
    
    PersonajeLoriView(uint32_t id_jugador);

    void crear_texturas(SDL2pp::Renderer *render) override;

    void crear_animaciones() override;

    ~PersonajeLoriView();

};

#endif