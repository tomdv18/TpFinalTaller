#include "Partida.h"



Partida::Partida(uint32_t id_creador, uint8_t max_jugadores, uint32_t id,Queue<Accion> *queue_creador) : 
            id(id),id_creador(id_creador), max_jugadores(max_jugadores),queue_acciones(1000){

     
        map_jugadores[id_creador] = queue_creador;
}


Queue<Accion>* Partida::obtener_queue(){
    return &queue_acciones;
}

void Partida::listar_jugadores(){
    std::cout << "LISTA DE JUGADORES" << std::endl;

    for(const auto &par : map_jugadores){
        std::cout << "JUGADOR " << par.first << std::endl;
    }
}

Queue<Accion>* Partida::unir_jugador(uint32_t id_jugador, Queue<Accion> *queue_jugador){
    //std::lock_guard<std::mutex> lock(m);

    if((uint8_t)map_jugadores.size() < max_jugadores){
        map_jugadores[id_jugador] = queue_jugador;
        return obtener_queue();
    }
    return nullptr;
}

bool Partida::borrar_jugador(uint32_t id_jugador){
    if(map_jugadores.find(id_jugador) != map_jugadores.end()){
        map_jugadores.erase(id_jugador);
    }

    if(map_jugadores.size() == 0){
        return true;
    }
    return false;
}

void Partida::run(){

    while(_keep_running){
        // Prueba de broadcast
        Accion accion;
        if(queue_acciones.try_pop(accion)){
            for(auto it=map_jugadores.begin(); it != map_jugadores.end(); ++it){
                Queue<Accion> *queue = it->second;
                try{
                    queue->push(accion);
                }catch(const ClosedQueue &err){
                    map_jugadores.erase(it->first);
                }
            }
        }
    }
}


Partida::~Partida(){}