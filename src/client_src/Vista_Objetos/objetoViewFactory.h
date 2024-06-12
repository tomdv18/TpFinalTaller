#ifndef OBJETO_FACTORY_H_
#define OBJETO_FACTORY_H_

#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_gema.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_moneda.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_1.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_2.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_municion_tipo_3.h"
#include "../src/client_src/Animaciones/Animaciones_Objetos/animacion_zanahoria.h"
#include "../src/client_src/direcciones.h"

class ObjetoViewFactory {

   protected:

    std::unique_ptr<Animacion> &animacion;

   public:

   explicit ObjetoViewFactory(std::unique_ptr<Animacion> &animacion);

   virtual void crear_texturas(SDL2pp::Renderer *render);

   virtual std::unique_ptr<Animacion> crear_animacion_objeto(std::string const nombre_objeto);

   virtual ~ObjetoViewFactory(); 
};

#endif