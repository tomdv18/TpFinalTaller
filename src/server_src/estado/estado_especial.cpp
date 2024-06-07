#include "estado_especial.h"
#include "estado_caminando.h"
#include "estado_quieto.h"
#include "estado_corriendo.h"
#include "estado_saltando.h"
#include "estado_herido.h"
#include "estado_muerto.h"

EstadoEspecial::EstadoEspecial() : Estado(ESTADO_ESPECIAL){
    
}

void EstadoEspecial::manejarEstado(uint8_t codigo_estado, double tiempo){

    if(codigo_estado == ESTADO_MUERTO){
        this->personaje->cambiarEstado(new EstadoMuerto(tiempo));
    }

    if(codigo_estado == ESTADO_HERIDO){
        this->personaje->cambiarEstado(new EstadoHerido(tiempo));
    }

    if(this->personaje->obtener_habilidad()){
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
    case ESTADO_SALTANDO:
        std::cout << "ESTADO SALTANDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoSaltando());
        break;
    
    default:
        break;
    }
}

void EstadoEspecial::actualizar(double tiempo){
    
}