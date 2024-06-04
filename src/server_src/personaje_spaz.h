#ifndef SERVER_PERSONAJE_SPAZ_H_
#define SERVER_PERSONAJE_SPAZ_H_

#include "personaje.h"

class Spaz : public Personaje{
private:


public:
    Spaz(uint32_t id_jugador);

    uint8_t obtener_personaje() override;

    void usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) override;

    void mover_arriba(std::chrono::duration<double> tiempo_transcurrido) override;

    void mover_izquierda() override;

    void mover_derecha() override;

    void quedarse_quieto() override;
};

#endif