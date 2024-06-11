#include "personaje_jazz.h"

#include <memory>
#define CONFIG Configuracion::config()

Jazz::Jazz(uint32_t id_jugador): Personaje(id_jugador) {
    tiempo_especial = -CONFIG.getEnfriamientoHabilidadJazz();
}

uint8_t Jazz::obtener_personaje() { return JAZZ; }

void Jazz::usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) {

    if (!saltando && !corriendo &&
        (tiempo_transcurrido.count() - tiempo_especial) >= CONFIG.getEnfriamientoHabilidadJazz()) {
        velocidad_y = -CONFIG.getVelocidadYHabilidadJazz();
        velocidad_x = 0;
        esta_quieto = false;
        saltando = true;
        usando_especial = true;
        en_superficie = false;
        tiempo_salto = tiempo_transcurrido.count();
        tiempo_especial = tiempo_transcurrido.count();
        this->estado->manejarEstado(ESTADO_ESPECIAL, tiempo_transcurrido.count());
    }
}


void Jazz::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                               std::map<uint32_t, Objeto*>& map_objetos,
                               std::map<uint32_t, std::unique_ptr<Objeto>>& map_objetos_comunes) {
    if (!saltando) {
        usando_especial = false;
    }
    Personaje::actualizar_posicion(tiempo_transcurrido, map_objetos, map_objetos_comunes);
}
