#include "partida.h"



Partida::Partida(uint32_t id_creador, uint8_t max_jugadores, uint32_t id,Queue<Evento> *queue_creador) : 
            id(id),id_creador(id_creador), max_jugadores(max_jugadores),queue_acciones(1000),
            logica_partida()
            {

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

Queue<Accion>* Partida::unir_jugador(uint32_t id_jugador, Queue<Evento> *queue_jugador){
    std::lock_guard<std::mutex> lock(m);

    if((uint8_t)map_jugadores.size() < max_jugadores){
        map_jugadores[id_jugador] = queue_jugador;
        return obtener_queue();
    }
    return nullptr;
}

bool Partida::borrar_jugador(uint32_t id_jugador){
    if (map_jugadores.find(id_jugador) != map_jugadores.end()) {
        map_jugadores.erase(id_jugador);
    }

    if (map_jugadores.empty()) {
        return true;
    }
    return false;
}

uint8_t Partida::jugadores(){
    return map_jugadores.size();
}

uint8_t Partida::max(){
    return max_jugadores;
}

void Partida::run(){
    

   
   while(_keep_running){
    
        
        Accion accion;

        while(queue_acciones.try_pop(accion)){
            logica_partida.ejecutar(accion);
            std::cout << "ACCION " << accion.codigo << std::endl;
        }
    

        logica_partida.actualizar_partida();

        Evento snapshot =  logica_partida.obtener_snapshot();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        for(auto it=map_jugadores.begin(); it != map_jugadores.end(); ++it){
            Queue<Evento> *queue = it->second;
            try{
                queue->push(snapshot);
            }catch(const ClosedQueue &err){
                map_jugadores.erase(it->first);
            }
        }
        
            
            
        


    }

    // Partida terminada, cierro la queue
    queue_acciones.close();
}


Partida::~Partida(){}