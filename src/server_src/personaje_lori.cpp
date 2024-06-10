#include "personaje_lori.h"

#include <map>

Lori::Lori(uint32_t id_jugador): Personaje(id_jugador) { tiempo_especial = -ENFRIAMIENTO_LORI; }

uint8_t Lori::obtener_personaje() { return LORI; }

void Lori::usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) {
    if (posicion_y > 0 && !saltando && !usando_especial &&
        (tiempo_transcurrido.count() - tiempo_especial) >= ENFRIAMIENTO_JAZZ) {
        velocidad_y = -VELOCIDAD_SALTO;
        esta_quieto = false;
        saltando = true;
        usando_especial = true;
        tiempo_salto = tiempo_transcurrido.count();
        tiempo_especial = tiempo_transcurrido.count();
    }
}


void Lori::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                               std::map<uint32_t, Objeto*>& map_objetos) {
    if (!saltando) {
        usando_especial = false;
    }
    Personaje::actualizar_posicion(tiempo_transcurrido, map_objetos);
}
