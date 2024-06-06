#ifndef PERSONAJE_JAZZ_VIEW_H_
#define PERSONAJE_JAZZ_VIEW_H_

#include "personajeView.h"

class PersonajeJazzView : public PersonajeView {

    public:
    
    PersonajeJazzView(uint32_t id_jugador, int x, int y);

    void crear_texturas(SDL2pp::Renderer *render) override;

    void crear_animaciones() override;

    ~PersonajeJazzView();

};

#endif