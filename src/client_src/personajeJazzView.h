#ifndef PERSONAJE_JAZZ_VIEW_H_
#define PERSONAJE_JAZZ_VIEW_H_

#include "personajeView.h"
#include "../src/client_src/Animaciones/Animaciones_Jazz/animacion_Jazz_caminando.h"
#include "../src/client_src/Animaciones/Animaciones_Jazz/animacion_Jazz_corriendo.h"
#include "../src/client_src/Animaciones/Animaciones_Jazz/animacion_Jazz_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Jazz/animacion_Jazz_saltando.h"
#include "../src/client_src/Animaciones/Animaciones_Jazz/animacion_Jazz_disparo_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Jazz/animacion_Jazz_deja_disparo_quieto.h"

class PersonajeJazzView : public PersonajeView {

    public:
    
    PersonajeJazzView(uint32_t id_jugador, int x, int y);

    void crear_animaciones() override;

    ~PersonajeJazzView();

};

#endif