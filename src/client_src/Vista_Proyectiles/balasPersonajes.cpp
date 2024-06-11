#include "balasPersonajes.h"

BalasPersonajes::BalasPersonajes(): 
mapa_balas_pjs()
{};

// Método para agregar un nuevo mapa para un nuevo id_cliente
void BalasPersonajes::agregarNuevoMapaBalas(uint32_t id_jugador) {
    auto it = mapa_balas_pjs.find(id_jugador);
    if (it == mapa_balas_pjs.end()) {
        mapa_balas_pjs.insert({id_jugador, std::map<uint32_t, std::unique_ptr<BalaView>>()});
        std::cout << "Nuevo mapa creado para el cliente " << id_jugador << "\n";
    } else {
        std::cout << "El cliente " << id_jugador << " ya existe en el mapa\n";
    }
}

void BalasPersonajes::agregarBala(uint32_t id_jugador, uint32_t id_bala, std::unique_ptr<BalaView> bala) {
    // Verificar si la bala ya existe
    auto& balas = mapa_balas_pjs[id_jugador];
    if (balas.find(id_bala) != balas.end()) {
        std::cout << "La bala con id " << id_bala << " ya existe para el jugador " << id_jugador << "\n";
        return;
    }

    // Insertar la nueva bala en el mapa del jugador
    balas.insert({id_bala, std::move(bala)});
    std::cout << "Nueva bala " << id_bala << " agregada para el jugador " << id_jugador << "\n";
}

// Método para eliminar una bala de un jugador
void BalasPersonajes::eliminarBala(uint32_t id_jugador, uint32_t id_bala) {
    auto it_jugador = mapa_balas_pjs.find(id_jugador);
    if (it_jugador != mapa_balas_pjs.end()) {
        auto& balas = it_jugador->second;
        auto it_bala = balas.find(id_bala);
        if (it_bala != balas.end()) {
            balas.erase(it_bala);
            std::cout << "Bala con id " << id_bala << " eliminada para el jugador " << id_jugador << "\n";
        } else {
            std::cout << "La bala con id " << id_bala << " no se encontró para el jugador " << id_jugador << "\n";
        }
    } else {
        std::cout << "El jugador " << id_jugador << " no se encontró en el mapa\n";
    }
}

// Método para eliminar todas las balas de un jugador
void BalasPersonajes::eliminarTodasLasBalasDeJugador(uint32_t id_jugador) {
    auto it_jugador = mapa_balas_pjs.find(id_jugador);
    if (it_jugador != mapa_balas_pjs.end()) {
        mapa_balas_pjs.erase(it_jugador);
        std::cout << "Todas las balas del jugador " << id_jugador << " han sido eliminadas\n";
    } else {
        std::cout << "El jugador " << id_jugador << " no se encontró en el mapa\n";
    }
}

void BalasPersonajes::eliminarTodasLasBalas() {
    mapa_balas_pjs.clear();
    std::cout << "Todas las balas han sido eliminadas\n";
}

BalaView* BalasPersonajes::obtenerBala(uint32_t id_jugador, uint32_t id_bala) {
    auto it_jugador = mapa_balas_pjs.find(id_jugador);
    if (it_jugador != mapa_balas_pjs.end()) { // Si el jugador existe en el mapa
        auto& balas = it_jugador->second;
        auto it_bala = balas.find(id_bala);
        if (it_bala != balas.end()) { // Si la bala existe para ese jugador
            std::cout << "Bala del jugador " << id_jugador << " con id " << id_bala << " obtenida\n";
            return it_bala->second.get(); // Devolvemos un puntero al objeto BalaView dentro del mapa
        } else {
            std::cout << "La bala con id " << id_bala << " no se encontró para el jugador " << id_jugador << "\n";
        }
    } else {
        std::cout << "El jugador " << id_jugador << " no se encontró en el mapa\n";
    }
    return nullptr; // Devolvemos nullptr si la bala no se encuentra o el jugador no existe (no tendria que pasar...)
}