#ifndef SERVER_ENEMIGO_BRUJA_H_
#define SERVER_ENEMIGO_BRUJA_H_

#include "enemigo.h"

class Bruja: public Enemigo {
private:
    void mover_derecha() override;

    void mover_izquierda() override;

public:
    explicit Bruja(uint32_t id_enemigo, uint32_t x, uint32_t y);

    uint8_t obtener_personaje() override;

    void revivir() override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*>& map_objetos_solidos) override;
};


#endif