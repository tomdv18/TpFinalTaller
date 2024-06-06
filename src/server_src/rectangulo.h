#ifndef SERVER_RECTANGULO_H_
#define SERVER_RECTANGULO_H_

#include <iostream>

class Rectangulo {
public:
    uint32_t x, y, ancho, alto;

    Rectangulo(uint32_t x, uint32_t y, uint32_t ancho, uint32_t alto)
        : x(x), y(y), ancho(ancho), alto(alto) {}

    bool hay_colision(const Rectangulo& otro) const {
        return (this->x < otro.x + otro.ancho &&
                this->x + this->ancho > otro.x &&
                this->y < otro.y + otro.alto &&
                this->y + this->alto > otro.y);
    }


    // Detección de colisión en el eje X (horizontal)
    bool hay_colision_x(const Rectangulo& otro) const {
        return (this->x < otro.x + otro.ancho &&
                this->x + this->ancho > otro.x);
    }

    // Detección de colisión en el eje Y (vertical)
    bool hay_colision_y(const Rectangulo& otro) const {
        return (this->y < otro.y + otro.alto &&
                this->y + this->alto > otro.y);
    }
};


#endif