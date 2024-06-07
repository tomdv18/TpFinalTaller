#include "personaje_spaz.h"

#include <map>

Spaz::Spaz(uint32_t id_jugador): Personaje(id_jugador) { tiempo_especial = -ENFRIAMIENTO_SPAZ; }

uint8_t Spaz::obtener_personaje() { return SPAZ; }

void Spaz::usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) {
    if (!saltando && !usando_especial &&
        (tiempo_transcurrido.count() - tiempo_especial) >= ENFRIAMIENTO_JAZZ) {
        esta_quieto = false;
        tiempo_especial = tiempo_transcurrido.count();
        usando_especial = true;
        if (direccion_mirando == DERECHA) {
            velocidad_x = VELOCIDAD * 2;
        } else {
            velocidad_x = -VELOCIDAD * 2;
        }
    }
}

void Spaz::mover_arriba(std::chrono::duration<double> tiempo_transcurrido) {
    if (posicion_y > 0 && !saltando && !usando_especial) {
        velocidad_y = -VELOCIDAD_SALTO;
        esta_quieto = false;
        saltando = true;
        tiempo_salto = tiempo_transcurrido.count();
    }
}

void Spaz::mover_izquierda(std::chrono::duration<double> tiempo_transcurrido) {
    if (!usando_especial) {
        Personaje::mover_izquierda(tiempo_transcurrido);
    }
}

void Spaz::mover_derecha(std::chrono::duration<double> tiempo_transcurrido) {
    if (!usando_especial) {
        Personaje::mover_derecha(tiempo_transcurrido);
    }
}

void Spaz::quedarse_quieto() {
    if (!saltando && !usando_especial) {
        velocidad_x = 0;
        esta_quieto = true;
    }
}

void Spaz::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                               std::map<uint32_t, Objeto*>& map_objetos, std::map<uint32_t, Objeto*>& map_objetos_comunes) {
    Personaje::actualizar_posicion(tiempo_transcurrido, map_objetos, map_objetos_comunes);
    if (usando_especial) {
        if (tiempo_transcurrido.count() - tiempo_especial > 0.75) { // Tiempo que dura el desplazamiento
            usando_especial = false;
            velocidad_x = 0;
        }
    }
}