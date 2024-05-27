#include "item_gema.h"

Item_gema::Item_gema() : cantidad_puntos(100) {}

void Item_gema::aplicar_item(Personaje &personaje) {
    personaje.aumenatar_puntos(this->cantidad_puntos);
}