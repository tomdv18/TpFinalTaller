#ifndef COMMON_EVENTO_H_
#define COMMON_EVENTO_H_

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <yaml-cpp/yaml.h>

struct __attribute__((packed)) EventoPersonaje {
    // cppcheck-suppress unusedStructMember
    uint32_t id_jugador;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_x;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_y;
    // cppcheck-suppress unusedStructMember
    uint32_t puntos;
    // cppcheck-suppress unusedStructMember
    uint32_t municion;
    // cppcheck-suppress unusedStructMember
    uint8_t vida;
    // cppcheck-suppress unusedStructMember
    uint8_t id_personaje;
    // cppcheck-suppress unusedStructMember
    uint8_t esta_quieto;
    // cppcheck-suppress unusedStructMember
    uint8_t esta_corriendo;
    // cppcheck-suppress unusedStructMember
    uint8_t usando_habilidad;
    // cppcheck-suppress unusedStructMember
    uint8_t esta_saltando;
    // cppcheck-suppress unusedStructMember
    uint8_t esta_disparando;
    // cppcheck-suppress unusedStructMember
    uint8_t codigo_estado;
    // cppcheck-suppress unusedStructMember
    uint8_t mirando_izquierda;
    // cppcheck-suppress unusedStructMember
    uint8_t esta_intoxicado;
    // cppcheck-suppress unusedStructMember
    uint8_t bala_actual;
};

struct __attribute__((packed)) EventoBala {
    // cppcheck-suppress unusedStructMember
    uint32_t id_jugador;
    // cppcheck-suppress unusedStructMember
    uint32_t id_bala;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_x;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_y;
    // cppcheck-suppress unusedStructMember
    uint8_t impacto;
    // cppcheck-suppress unusedStructMember
    uint8_t tipo_bala;
};

struct __attribute__((packed)) EventoObjeto {
    // cppcheck-suppress unusedStructMember
    uint32_t id_objeto;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_x;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_y;
    // cppcheck-suppress unusedStructMember
    uint8_t mostrandose;
    // cppcheck-suppress unusedStructMember
    uint8_t codigo_objeto;
};

struct __attribute__((packed)) EventoEnemigo {
    // cppcheck-suppress unusedStructMember
    uint32_t id_enemigo;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_x;
    // cppcheck-suppress unusedStructMember
    uint32_t posicion_y;
    // cppcheck-suppress unusedStructMember
    uint8_t vida;
    // cppcheck-suppress unusedStructMember
    uint8_t id_personaje;
    // cppcheck-suppress unusedStructMember
    bool esta_vivo;
    // cppcheck-suppress unusedStructMember
    bool mirando_izquierda;
};

struct Evento {
    // cppcheck-suppress unusedStructMember
    uint16_t tiempo_restante;
    std::vector<EventoPersonaje> eventos_personaje;
    std::vector<EventoObjeto> eventos_objeto;
    std::vector<EventoBala> eventos_bala;
    std::vector<EventoEnemigo> eventos_enemigos;
};

enum Entidad : uint8_t {
    PISO,
    PARED,
    PERSONAJE
    // PLATAFORMA, DIAGONAL, etc...
    // GEMAS? ENEMIGOS? Ver cuando se haga el editor
};

// Representa una posicion x e y.
struct __attribute__((packed)) Position {
    // cppcheck-suppress unusedStructMember
    uint32_t x;
    // cppcheck-suppress unusedStructMember
    uint32_t y;
};

// Mapa de entidades (piso, paredes, plataforma, diagonales, etc).
using MapaEntidades = std::unordered_map<std::string, std::vector<Position>>;

#endif
