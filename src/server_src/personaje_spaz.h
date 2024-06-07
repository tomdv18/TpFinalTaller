#ifndef SERVER_PERSONAJE_SPAZ_H_
#define SERVER_PERSONAJE_SPAZ_H_

#include <map>

#include "personaje.h"

class Spaz: public Personaje {
private:
public:
    explicit Spaz(uint32_t id_jugador);

    uint8_t obtener_personaje() override;

    void usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                             std::map<uint32_t, Objeto*>& map_objetos) override;

    void mover_arriba(std::chrono::duration<double> tiempo_transcurrido) override;

    void mover_izquierda(std::chrono::duration<double> tiempo_transcurrido) override;

    void mover_derecha(std::chrono::duration<double> tiempo_transcurrido) override;

    void quedarse_quieto() override;
};

#endif
