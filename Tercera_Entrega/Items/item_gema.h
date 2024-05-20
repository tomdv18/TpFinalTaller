#ifndef ITEM_GEMA_H
#define ITEM_GEMA_H

#include "item.h"
#include "personaje.h"

class Item_gema : public Item {

   private:

   int cantidad_puntos;

   public:

   Item_gema();

   void aplicar_item(Personaje &persoaneje);
};

#endif