#include "estado_muerto.h"
#include "estado_quieto.h"
#include "estado_caminando.h"
#include "estado_corriendo.h"
#include "estado_saltando.h"
#include "estado_herido.h"

EstadoMuerto::EstadoMuerto(double tiempo_muerte) : Estado(ESTADO_MUERTO){
    this->tiempo_muerte = tiempo_muerte;
    this->cambiar_estado = false;
}



void EstadoMuerto::manejarEstado(uint8_t codigo_estado, double tiempo){

    if(!cambiar_estado){
        return;
    }

    switch (codigo_estado)
    {
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
    case ESTADO_HERIDO:
        std::cout << "ESTADO HERIDO" << std::endl;
        this->personaje->cambiarEstado(new EstadoHerido(tiempo));
        break;
    
    default:
        break;
    }
}

void EstadoMuerto::actualizar(double tiempo){
    if(tiempo - tiempo_muerte >= TIEMPO_MUERTO){
        cambiar_estado = true;
        this->personaje->revivir();
        this->personaje->cambiarEstado(new EstadoQuieto());
    }
}