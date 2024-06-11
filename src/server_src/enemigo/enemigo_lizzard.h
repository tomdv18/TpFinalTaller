#ifndef SERVER_ENEMIGO_LIZZARD_H_
#define SERVER_ENEMIGO_LIZZARD_H_

#include "enemigo.h"

class Lizzard: public Enemigo {
private:
    void mover_derecha() override;

    void mover_izquierda() override;

public:
    explicit Lizzard(uint32_t id_enemigo, uint32_t x, uint32_t y);

    uint8_t obtener_personaje() override;

    void revivir() override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido) override;
};


#endif
