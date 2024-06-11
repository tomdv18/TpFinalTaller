#ifndef ITEM_MONEDA_H
#define ITEM_MONEDA_H

#include "item.h"

class Item_moneda : public Item {

   private:

   int cantidad_puntos;

   public:

   void aplicar_item(Personaje &personaje);

};

#endif