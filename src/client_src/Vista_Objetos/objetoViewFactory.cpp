#include "objetoViewFactory.h"

ObjetoViewFactory::ObjetoViewFactory(std::unique_ptr<Animacion> &animacion) : animacion(animacion) {}

std::unique_ptr<Animacion> ObjetoViewFactory::crear_animacion_objeto(std::string const nombre_objeto) {

    if(nombre_objeto == GEMA_OBJETO) {
        return std::move(std::make_unique<Animacion_Gema>());
    } else if(nombre_objeto == MONEDA_OBJETO) {
        return std::move(std::make_unique<Animacion_Moneda>());
    } else if(nombre_objeto == ZANAHORIA_OBJETO) {
        return std::move(std::make_unique<Animacion_Zanahoria>());
    } else if(nombre_objeto == MUNICION_TIPO_1) {
        return std::move(std::make_unique<Animacion_municion_tipo_1>());
    } else if(nombre_objeto == MUNICION_TIPO_2) {
        return std::move(std::make_unique<Animacion_municion_tipo_2>());
    } else if(nombre_objeto == MUNICION_TIPO_3) {
        return std::move(std::make_unique<Animacion_municion_tipo_3>());
    } 
    return nullptr;

}

void ObjetoViewFactory::crear_texturas(SDL2pp::Renderer *render) {

    this->animacion->crear_texturas(render);
}

ObjetoViewFactory::~ObjetoViewFactory() {}