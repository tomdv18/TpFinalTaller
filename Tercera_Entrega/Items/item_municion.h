#ifndef ITEM_MUNICION_H
#define ITEM_MUNICION_H

#include "item.h"


class Item_municion : public Item {

   private:

   int cantidad_municion;
   std::string tipo_municion; //Probablemente sea un objeto

   public:

   Item_municion();

   void aplicar_item(Personaje &personaje);

};

#endif