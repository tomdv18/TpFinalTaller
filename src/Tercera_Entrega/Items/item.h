#ifndef ITEM_H
#define ITEM_H
#include "personaje.h"

class Item {

   protected:

   virtual void aplicar_item(Personaje &personaje) = 0;

   virtual ~Item();

};

#endif