#include "item_municion.h"

Item_municion::Item_municion() : cantidad_municion(cantidad_municion) {}

void Item_municion::aplicar_item(Personaje &personaje) {
    personaje.get_arma(this->tipo_municion).aumentar_cantidad_municion(this->cantidad_municion);
}