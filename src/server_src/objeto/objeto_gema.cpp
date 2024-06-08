#include "objeto_gema.h"


Gema::Gema(uint32_t id_objeto, uint32_t posicion_x, uint32_t posicion_y,
                     double tiempo_reaparicion, uint32_t ancho, uint32_t alto, bool envenenado):
        Objeto(id_objeto, posicion_x, posicion_y, tiempo_reaparicion, ancho, alto, envenenado) {}

uint8_t Gema::obtener_objeto() { return GEMA; }

void Gema::interactuar_personaje(Personaje* personaje,
                                      std::chrono::duration<double> tiempo_transcurrido) {
    std::cout << "AGARRANDO GEMA" << std::endl;
    tiempo_interaccion = tiempo_transcurrido.count();
    mostrar = false;
}
