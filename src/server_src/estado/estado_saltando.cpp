#include "estado_quieto.h"
#include "estado_caminando.h"
#include "estado_corriendo.h"
#include "estado_saltando.h"
#include "estado_herido.h"
#include "estado_muerto.h"
#include "estado_especial.h"
#include "estado_cayendo.h"
#include "estado_tambalear.h"

EstadoSaltando::EstadoSaltando() : Estado(ESTADO_SALTANDO){}


void EstadoSaltando::manejarEstado(uint8_t codigo_estado, double tiempo){

    if(codigo_estado == ESTADO_MUERTO){
        this->personaje->cambiarEstado(new EstadoMuerto(tiempo));
        return;
    }

    if(codigo_estado == ESTADO_HERIDO){
        this->personaje->cambiarEstado(new EstadoHerido(tiempo));
        return;
    }
    
    if(codigo_estado == ESTADO_CAYENDO){
        this->personaje->cambiarEstado(new EstadoCayendo());
        return;
    }

    if(this->personaje->obtener_saltando()){
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
    case ESTADO_TAMBALEAR:
        std::cout << "ESTADO TAMBALEAR" << std::endl;
        this->personaje->cambiarEstado(new EstadoTambalear());
        break;
    default:
        break;
    }
}

void EstadoSaltando::actualizar(double tiempo){
    
}
