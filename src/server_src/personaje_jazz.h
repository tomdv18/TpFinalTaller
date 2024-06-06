#ifndef SERVER_PERSONAJE_JAZZ_H_
#define SERVER_PERSONAJE_JAZZ_H_

#include "personaje.h"

class Jazz : public Personaje{
private:


public:
    Jazz(uint32_t id_jugador);

    uint8_t obtener_personaje() override;

    void usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) override;

    void mover_derecha() override;

    void mover_izquierda() override;

    void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido, std::map<uint32_t, Objeto*> &map_objetos) override;


};







#endif