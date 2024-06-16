#ifndef SERVER_ENEMIGO_RAT_H_
#define SERVER_ENEMIGO_RAT_H_

#include "enemigo.h"

class Rat: public Enemigo {
public:
    explicit Rat(uint32_t id_enemigo, uint32_t x, uint32_t y);

    uint8_t obtener_personaje() override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,std::map<uint32_t, Objeto*>& map_objetos_solidos) override;

    uint8_t obtener_item() override;
};


#endif
