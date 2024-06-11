#ifndef SERVER_CONTROLADOR_BALAS_H_
#define SERVER_CONTROLADOR_BALAS_H_

#include <algorithm>
#include <unordered_set>
#include <vector>

#include "../configuracion.h"
#include "../personaje/personaje.h"

#include "bala.h"

#define CONFIG Configuracion::config()

class ControladorBalas {
private:
    std::vector<Bala> balas;
    std::unordered_set<uint32_t> ids_disponibles;
    uint32_t proximo_id;

public:
    ControladorBalas(): proximo_id(-1) {}


    void agregar_bala(uint8_t codigo_bala, uint32_t id_jugador, uint32_t pos_x, uint32_t offset,
                      uint32_t pos_y, int velocidad) {
        uint32_t id_bala = obtener_id();
        std::cout << "ID BALA: " << id_bala << std::endl;
        const ConfigBala& config_bala = CONFIG.obtenerBala(codigo_bala);
        balas.push_back(Bala(codigo_bala, pos_x + offset, pos_y, id_jugador, id_bala,
                             velocidad * config_bala.velocidad_del_proyectil, config_bala.danio,
                             config_bala.tiempo_entre_disparo, config_bala.rango_explosion,
                             config_bala.municion, config_bala.ancho, config_bala.largo));
    }

    void remover_bala(uint32_t id_bala) {
        auto it = std::remove_if(balas.begin(), balas.end(), [id_bala](const Bala& b) {
            return b.obtener_id_bala() == id_bala;
        });

        if (it != balas.end()) {
            balas.erase(it, balas.end());
            ids_disponibles.insert(id_bala);
        }
    }

    std::vector<Bala>& obtener_balas() { return balas; }

private:
    uint32_t obtener_id() {
        /*
        if (ids_disponibles.empty()) {
            return proximo_id++;
        } else {
            uint32_t id = *ids_disponibles.begin();
            ids_disponibles.erase(id);
            return id;
        }
        */
        proximo_id += 1;
        return proximo_id;
    }
};

#endif
