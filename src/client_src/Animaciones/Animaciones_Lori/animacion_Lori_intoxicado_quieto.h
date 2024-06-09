#ifndef ANIMACION_LORI_INTOXICADO_QUIETO_H_
#define ANIMACION_LORI_INTOXICADO_QUIETO_H_

#include "../src/client_src/Animaciones/animacion.h"
#include "../src/client_src/direcciones.h"

class Animacion_Lori_Intoxicado_Quieto : public Animacion {

   public:
    
    explicit Animacion_Lori_Intoxicado_Quieto();

    void crear_texturas(SDL2pp::Renderer *render) override;

    ~Animacion_Lori_Intoxicado_Quieto();
};
#endif