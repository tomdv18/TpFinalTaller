#include "objeto_zanahoria.h"


Zanahoria::Zanahoria(uint32_t id_objeto, uint32_t posicion_x, uint32_t posicion_y,
                     double tiempo_reaparicion, uint32_t ancho, uint32_t alto):
        Objeto(id_objeto, posicion_x, posicion_y, tiempo_reaparicion, ancho, alto) {}

uint8_t Zanahoria::obtener_objeto() { return ZANAHORIA; }

void Zanahoria::interactuar_personaje(Personaje* personaje,
                                      std::chrono::duration<double> tiempo_transcurrido) {
    // std::cout << "CURANDO AL PERSONAJE" << std::endl
    // tiempo_interaccion = tiempo_transcurrido.count();
    // mostrar = false;
}
