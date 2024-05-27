#ifndef PISTOLA_H
#define PISTOLA_H

#include "arma.h"

class Pistola : public Arma {
   
   public:

   explicit Pistola(int danio, int velocidad_disparo, int velocidad_proyectil,int cantidad_municion);

};

#endif 