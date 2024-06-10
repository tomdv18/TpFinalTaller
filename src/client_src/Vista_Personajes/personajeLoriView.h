#ifndef PERSONAJE_LORI_VIEW_H_
#define PERSONAJE_LORI_VIEW_H_

#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_caminando.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_corriendo.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_saltando.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_disparo_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_deja_disparo_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_intoxicado_quieto.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_intoxicado_caminando.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_herido.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_muerte.h"
#include "../src/client_src/Animaciones/Animaciones_Lori/animacion_Lori_habilidad.h"
#include "personajeView.h"

class PersonajeLoriView : public PersonajeView {

    public:
    
    PersonajeLoriView(EventoPersonaje &evento);

    void crear_animaciones() override;

    ~PersonajeLoriView();

};

#endif