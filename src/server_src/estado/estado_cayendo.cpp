#include "estado_quieto.h"
#include "estado_caminando.h"
#include "estado_corriendo.h"
#include "estado_saltando.h"
#include "estado_herido.h"
#include "estado_muerto.h"
#include "estado_especial.h"
#include "estado_cayendo.h"

EstadoCayendo::EstadoCayendo() : Estado(ESTADO_CAYENDO){}


void EstadoCayendo::manejarEstado(uint8_t codigo_estado, double tiempo){

    if(codigo_estado == ESTADO_MUERTO){
        this->personaje->cambiarEstado(new EstadoMuerto(tiempo));
        return;
    }

    if(codigo_estado == ESTADO_HERIDO){
        this->personaje->cambiarEstado(new EstadoHerido(tiempo));
        return;
    }

    if(this->personaje->obtener_velocidad_y() > 0){
        return;
    }

    switch (codigo_estado)
    {
    case ESTADO_QUIETO:
        std::cout << "ESTADO QUIETO" << std::endl;
        this->personaje->cambiarEstado(new EstadoQuieto());
        break;
    case ESTADO_CAMINANDO:
        std::cout << "ESTADO CAMINANDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoCaminando());
        break;
    case ESTADO_CORRIENDO:
        std::cout << "ESTADO CORRIENDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoCorriendo());
        break;
    case ESTADO_ESPECIAL:
        std::cout << "ESTADO ESPECIAL" << std::endl;
        this->personaje->cambiarEstado(new EstadoEspecial());
        break;
    case ESTADO_SALTANDO:
        std::cout << "ESTADO SALTANDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoSaltando());
        break;

    
    default:
        break;
    }
}

void EstadoCayendo::actualizar(double tiempo){
    
}
