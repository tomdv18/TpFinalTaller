#ifndef ITEM_VIDA_H
#define ITEM_VIDA_H

#include "item.h"
#include "personaje.h"

class Item_vida : public Item {

    private:

    int vida_agregada;
    
    public:

    Item_vida();

    void aplicar_item(Personaje &personaje);

};

#endif