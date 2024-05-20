#ifndef PROYECTIL_H
#define PROYECTIL_H

#include "coordenadas.h"

class Proyectil {

   private:

   Coordenadas coordenadas;
   int danio;
   int velocidad_proyectil;

   public:

   explicit Proyectil(int danio, int velocidad_proyectil);

   Coordenadas get_coordenadas();

   int get_danio();

   int get_velocidad_proyectil();

};

#endif