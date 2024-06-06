#ifndef SERVER_ARMA_H_
#define SERVER_ARMA_H_

#include <chrono>
#include <iostream>

#include "../common_src/bala.h"

#define TIEMPO_ENTRE_DISPARO 0.5

class Arma {
private:
    uint8_t balas;

    double tiempo_disparo;

    CodigoBala codigo_bala;

public:
    Arma();

    void recargar();

    bool disparar(std::chrono::duration<double> tiempo_transcurrido);

    uint8_t obtener_bala();
};


#endif
