#include "item_moneda.h"

Item_moneda::Item_moneda() : cantidad_puntos(10) {}

void Item_moneda::aplicar_item(Personaje &persoanaje) {
    persoanaje.aumenatar_puntos(this->cantidad_puntos);
    
}