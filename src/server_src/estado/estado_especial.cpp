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
    case ESTADO_SALTANDO:
        std::cout << "ESTADO SALTANDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoSaltando());
        break;
    case ESTADO_HERIDO:
        std::cout << "ESTADO HERIDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoHerido(tiempo));
        break;
    case ESTADO_MUERTO: 
        std::cout << "ESTADO MUERTO" << std::endl;
        this->personaje->cambiarEstado(new EstadoMuerto(tiempo));
        break;
    
    default:
        break;
    }
}

void EstadoEspecial::actualizar(double tiempo){
    
}