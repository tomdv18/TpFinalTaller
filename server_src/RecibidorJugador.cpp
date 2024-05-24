#include "RecibidorJugador.h"


RecibidorJugador::RecibidorJugador(ProtocoloServidor *protocolo_servidor, MonitorPartidas *monitor_partidas, Queue<Accion> *queue_jugador, int id)
    : protocolo_servidor(protocolo_servidor),
      monitor_partidas(monitor_partidas),
      queue_acciones(nullptr),
      queue_jugador(queue_jugador),
      enviador_jugador(protocolo_servidor, queue_jugador, id),
      id(id)
                {
        
    
}


void RecibidorJugador::run(){
    
    bool partida_encontrada = false;
    bool was_closed = false;
    
    while(_keep_running){

        //monitor_partidas->listar_partidas();
        // ENVIAR LISTA DE PARTIDAS, CODE P DE PARTIDAS
        // ENVIO ID(UINT32_T), UIN8_T JUGADORES, UINT8_T MAX_JUGADORES
        // REPETIR PARA TODAS LAS PARTIDAS
        // AGREGAR UN CASE REFRESH PARTIDAS
        //protocolo_servidor->enviar_lista_partidas(*monitor_partidas, was_closed);
        
        try{
            //Seguir en el lobby mientras no encuentre partida ni se cierre conexion
            while(!partida_encontrada){
                leer_lobby(partida_encontrada, was_closed);
            }
        } catch(std::runtime_error &err){
            //Se perdio la conexion, salgo
            break;
        }


        // NO se cerro la conexion, se encontro partida
        // Inicio el sender
        try{
            // Empiezo a recibir acciones de partida 
            if(!enviador_jugador.is_alive()){
                enviador_jugador.start();
            }
            
            while(true){
                try{
                    Accion accion;
                    accion.id_jugador = id;
                    accion.codigo = protocolo_servidor->obtener_accion(was_closed);
                    queue_acciones->push(accion);
                    if(accion.codigo == LOBBY){
                        break;
                    }
                } catch(const ClosedQueue &err){
                    //Se cerró la partida, queue cerrada
                    break;
                }
            }
        }
        catch(std::runtime_error &err){
            //Se perdio la conexion, salgo
            break;
        }
        //Jugador salio de la partida, lo borro
        monitor_partidas->borrar_jugador(id);

        partida_encontrada = false;
    }

    // Join sender, cierro Queue sender para destrabarlo
    queue_jugador->close();
    if(enviador_jugador.is_alive()){
        enviador_jugador.join();
    }
}

void RecibidorJugador::leer_lobby(bool &partida_encontrada, bool &was_closed){
    uint8_t codigo = protocolo_servidor->obtener_accion(was_closed);
    
    if(was_closed){
        throw std::runtime_error("Se perdió la conexion con el cliente");
    }
    
    switch (codigo){
        case CREAR:{
                //Logica de creacion
                uint8_t max_jugadores = protocolo_servidor->leer_jugadores(was_closed);
                if(was_closed){
                    throw std::runtime_error("Se perdió la conexion con el cliente");
                }
                this->queue_acciones = monitor_partidas->crear_partida(id, max_jugadores, queue_jugador);
            break;
        }
        case UNIRSE:{
                //Logica de unirse
                uint32_t id_partida = protocolo_servidor->leer_id_partida(was_closed);
                if(was_closed){
                    throw std::runtime_error("Se perdió la conexion con el cliente");
                }
                this->queue_acciones = monitor_partidas->unir_jugador(id, id_partida, queue_jugador);
            break;
        }
        case LIST_P:{
                protocolo_servidor->enviar_lista_partidas(*monitor_partidas, was_closed);
            break;
        }
        case SALIR:{
            throw std::runtime_error("Jugador desconectado");
            break;
        }
        default:{
            throw std::runtime_error("Se perdió la conexion con el cliente");
            break;
        }
    }

    if(this->queue_acciones != nullptr){
        Accion accion;
        accion.id_jugador = id;
        accion.codigo = codigo;
        partida_encontrada = true;
        this->queue_acciones->push(accion);
    }
}


void RecibidorJugador::join_enviador(){
    if(enviador_jugador.is_alive()){
        enviador_jugador.join();
    }
}

RecibidorJugador::~RecibidorJugador(){
    
}