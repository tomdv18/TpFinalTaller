#ifndef PERSONAJE_SPAZ_VIEW_H_
#define PERSONAJE_SPAZ_VIEW_H_

#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_caminando.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_corriendo.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_saltando.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_disparo_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_deja_disparo_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_intoxicado_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Spaz/animacion_Spaz_intoxicado_caminando.h"
#include "personajeView.h"

class PersonajeSpazView : public PersonajeView {

    public:
    
    PersonajeSpazView(EventoPersonaje &evento);

   // void crear_texturas(SDL2pp::Renderer *render) override;

    void crear_animaciones() override;

    ~PersonajeSpazView();

};

#endif