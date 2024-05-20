#include "item_vida.h"

Item_vida::Item_vida() : vida_agregada(50) {}

void Item_vida::aplicar_item(Personaje &personaje) {
    personaje.aumentar_vida(this->vida_agregada);
}