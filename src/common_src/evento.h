#ifndef COMMON_EVENTO_H_
#define COMMON_EVENTO_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <yaml-cpp/yaml.h>

struct __attribute__((packed)) EventoPersonaje{

    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    uint8_t id_personaje;
    uint8_t esta_quieto;
    uint8_t esta_corriendo;
    uint8_t usando_habilidad;
    uint8_t esta_saltando;
    uint8_t esta_disparando;
    uint8_t codigo_estado;
    uint8_t mirando_izquierda;

};

struct __attribute__((packed)) EventoBala{

    uint32_t id_jugador;
    uint32_t id_bala;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t impacto;
    uint8_t tipo_bala;

};

struct __attribute__((packed)) EventoObjeto{

    uint32_t id_objeto;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t mostrandose;
    uint8_t codigo_objeto;

};

struct __attribute__((packed)) EventoEnemigo{

    uint32_t id_enemigo;
    uint32_t posicion_x;
    uint32_t posicion_y;
    uint8_t vida;
    uint8_t id_personaje;
    bool esta_vivo;
    bool mirando_izquierda;

};

struct Evento{
    uint16_t tiempo_restante;
    std::vector<EventoPersonaje> eventos_personaje;
    std::vector<EventoObjeto> eventos_objeto;
    std::vector<EventoBala> eventos_bala;
    std::vector<EventoEnemigo> eventos_enemigos;
};

enum Entidad: uint8_t {
    PISO,
    PARED,
    PERSONAJE
    // PLATAFORMA, DIAGONAL, etc...
    // GEMAS? ENEMIGOS? Ver cuando se haga el editor
};

// Representa una posicion x e y.
struct __attribute__((packed)) Position {
    uint32_t x;
    uint32_t y;
} ;

// Mapa de entidades (piso, paredes, plataforma, diagonales, etc).
using MapaEntidades = std::unordered_map<std::string, std::vector<Position>>;

#endif