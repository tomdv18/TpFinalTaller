#include "logicaPartida.h"


LogicaPartida::LogicaPartida(){

}


void LogicaPartida::ejecutar(Accion accion){
    switch (accion.codigo){
        case DERECHA:
            mover_derecha(accion.id_jugador);
            break;
        case IZQUIERDA:
            mover_izquierda(accion.id_jugador);
        case LOBBY:
            //abandonar_partida(accion.id_jugador);
        case JAZZ:
            agregar_personaje(accion);
        default:
            break;
    }
}

void LogicaPartida::mover_derecha(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->mover_derecha();
    }
}

void LogicaPartida::mover_izquierda(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->mover_izquierda();
    }
}

void LogicaPartida::abandonar_partida(uint32_t id_jugador){
    auto it = map_personajes.find(id_jugador);

    if(it != map_personajes.end()){
        delete it->second;

        map_personajes.erase(it);
    }
}



void LogicaPartida::agregar_personaje(Accion accion){
    //Personaje *personaje;
    switch(accion.codigo){
        case JAZZ:{
            std::cout << "CREAR PERSONAJE JAZZ" << std::endl;
            //personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if(map_personajes[accion.id_jugador] == nullptr){
                map_personajes[accion.id_jugador] = new Personaje(accion.id_jugador);
            }
            break;
        }
        default:
            break;
    }

}

void LogicaPartida::actualizar_partida(){

}

Evento LogicaPartida::obtener_snapshot(){
    Evento evento;
    evento.eventos_personaje.clear();

    for(const auto &par : map_personajes){
        EventoPersonaje evento_personaje;
        
        evento_personaje.id_jugador = par.first;
        evento_personaje.posicion_x = par.second->obtener_posicionX();
        evento_personaje.posicion_y = par.second->obtener_posicionY();
        evento_personaje.vida = par.second->obtener_vida();

        evento.eventos_personaje.emplace_back(evento_personaje);
    }

    return evento;
}


LogicaPartida::~LogicaPartida(){
    for(auto &par : map_personajes){
        delete par.second;
    }
}