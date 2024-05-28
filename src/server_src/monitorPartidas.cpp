#include "monitorPartidas.h"


MonitorPartidas::MonitorPartidas() : contador_partidas(0){}


Queue<Accion>* MonitorPartidas::crear_partida(uint32_t id_creador,uint8_t cant_jugadores, Queue<Evento> *queue_jugador){
    Partida *nueva_partida = new Partida(id_creador, cant_jugadores, (uint32_t)partidas.size(), queue_jugador);
    partidas.emplace(contador_partidas,nueva_partida);
    contador_partidas++;
    std::cout << "\nPARTIDA CREADA POR EL JUGADOR  " << id_creador << std::endl;
    std::cout << "CANTIDAD DE JUGADORES " << (int)cant_jugadores << std::endl;
    // Empiezo hilo partida
    nueva_partida->start();
    return nueva_partida->obtener_queue();
}

void MonitorPartidas::listar_partidas(){
    for (auto it = partidas.begin(); it != partidas.end(); ++it) {
        uint32_t key = it->first;
        Partida* partida = it->second;
        std::cout << "\nPARTIDA " << key << std::endl;
        partida->listar_jugadores();
    }
}



Queue<Accion>* MonitorPartidas::unir_jugador(uint32_t id_jugador, uint32_t id_partida, Queue<Evento> *queue_jugador){
    auto it = partidas.find(id_partida);

    // Buscar la partida en el map
    if (it != partidas.end()) {
        // Partida encontrada, uno al jugador y devuelvo la Queue si es posible
        return it->second->unir_jugador(id_jugador, queue_jugador);
    } else {
        // Partida no encontrada, devuelvo nullptr
        std::cout << "Error, partida no encontrada" << std::endl;
        return nullptr; 
    }
}


void MonitorPartidas::borrar_jugador(uint32_t id_jugador){
    auto it = partidas.begin();
    while (it != partidas.end()) {
        Partida* partida = it->second;

        // Si al eliminar el jugador la partida queda vacia, la borro
        if (partida->borrar_jugador(id_jugador)) {
            partida->stop();
            partida->join();
            delete partida;
            it = partidas.erase(it); 
        } else {
            ++it;
        }
    }
}

void MonitorPartidas::borrar_partidas(){
    for(auto& par : partidas){
        par.second->stop();
        par.second->join();
        delete par.second;
    }
    partidas.clear();
}

std::map<uint32_t, Partida*> MonitorPartidas::obtener_partidas(){
    return partidas;
}


MonitorPartidas::~MonitorPartidas(){}