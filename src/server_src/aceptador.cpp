#include "aceptador.h"


Aceptador::Aceptador(Socket *skt) : skt_servidor(skt){}

void Aceptador::run(){
    MonitorPartidas monitor_partidas;
    while(_keep_running){
        try{
            Socket skt_jugador = skt_servidor->accept();
            
            agregar_jugador(std::move(skt_jugador), monitor_partidas);
            verificar_jugadores();
        }catch(...){
            break;
        }
        
    }

    monitor_partidas.borrar_partidas();
    borrar_jugadores();
}

void Aceptador::agregar_jugador(Socket skt_jugador, MonitorPartidas &monitor_partidas){
    Jugador *nuevo_jugador = new Jugador((uint32_t)jugadores.size(),std::move(skt_jugador), monitor_partidas);
    jugadores.emplace_back(nuevo_jugador);
}


void Aceptador::verificar_jugadores(){
    auto terminado = [](Jugador *jugador) {
        if(!jugador->esta_vivo()){
            jugador->join();
            delete jugador;
            return true;
        }
        return false;
    };
    jugadores.remove_if(terminado);
}

void Aceptador::borrar_jugadores(){
    for(Jugador* jugador : jugadores){
        jugador->stop();
        jugador->join();
        delete jugador;
    }
    jugadores.clear();
}

Aceptador::~Aceptador(){}