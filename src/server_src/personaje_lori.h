#ifndef SERVER_PERSONAJE_LORI_H_
#define SERVER_PERSONAJE_LORI_H_

#include "personaje.h"

class Lori : public Personaje{
private:


public:
    Lori(uint32_t id_jugador);

    uint8_t obtener_personaje() override;

    void usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) override;

};

#endif

