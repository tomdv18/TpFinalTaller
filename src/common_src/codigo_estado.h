#ifndef CODIGO_ESTADO_H_
#define CODIGO_ESTADO_H_

#include <iostream>


enum CodigoEstado: uint8_t{
    ESTADO_QUIETO,
    ESTADO_CAMINANDO,
    ESTADO_CORRIENDO,
    ESTADO_SALTANDO,
    ESTADO_HERIDO,
    ESTADO_INTOXICADO,
    ESTADO_MUERTO,
    ESTADO_ESPECIAL

};



#endif