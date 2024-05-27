#ifndef ENEMIGO_H_
#define ENEMIGO_H_

#include <map>
#include "item.h"
#include "coordenadas.h"


class Enemigo {

    protected: 
    
    int vida;
    int danio;
    int tiempo_reaparicion;
    int puntos;
    Item *item;
    Coordenadas coordenadas;
    
    public:

    explicit Enemigo(int vida, int danio, 
    int puntos, Item *item);
    
};

#endif
