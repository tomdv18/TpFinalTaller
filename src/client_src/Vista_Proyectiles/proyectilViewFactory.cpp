#include "proyectilViewFactory.h"

ProyectilViewFactory::ProyectilViewFactory(std::unique_ptr<Animacion> &animacion) : animacion(animacion) {}

void ProyectilViewFactory::crear_animaciones(uint8_t tipo_bala) {
    
    
    switch (tipo_bala)
    {
    case CodigoObjeto::BALA_VELOZ:
        this->animacion = std::unique_ptr<Animacion_Proyectil_Tipo_1>(new Animacion_Proyectil_Tipo_1());
        break;
    case CodigoObjeto::COHETE_RAPIDO:
        this->animacion = std::unique_ptr<Animacion_Proyectil_Tipo_2>(new Animacion_Proyectil_Tipo_2());
        break;
    case CodigoObjeto::COHETE_TOXICO:
        this->animacion = std::unique_ptr<Animacion_Proyectil_Tipo_3>(new Animacion_Proyectil_Tipo_3());
        break;
    default:
        this->animacion = std::unique_ptr<Animacion_Bala_Pistola>(new Animacion_Bala_Pistola());
        break;
    }
}

void ProyectilViewFactory::crear_texturas(SDL2pp::Renderer *render) {
    this->animacion->crear_texturas(render); 
}

ProyectilViewFactory::~ProyectilViewFactory() {}