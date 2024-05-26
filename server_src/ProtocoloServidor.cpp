#include "ProtocoloServidor.h"
#include "sys/socket.h"


ProtocoloServidor::ProtocoloServidor(Socket skt) : skt_jugador(std::move(skt)){

}

uint8_t ProtocoloServidor::leer_jugadores(bool &was_closed){
    uint8_t max_jugadores;
    skt_jugador.recvall(&max_jugadores, sizeof(max_jugadores), &was_closed);
    return max_jugadores;
}


uint32_t ProtocoloServidor::leer_id_partida(bool &was_closed){
    uint32_t id_partida;
    skt_jugador.recvall(&id_partida, sizeof(id_partida), &was_closed);
    id_partida = ntohl(id_partida);
    return id_partida;
}


uint8_t ProtocoloServidor::obtener_accion(bool &was_closed){
    uint8_t codigo;
    skt_jugador.recvall(&codigo,sizeof(codigo), &was_closed);

    if(was_closed){
        throw std::runtime_error("Se perdió la conexion con el cliente");
    }

    return codigo;
}

void ProtocoloServidor::enviar_evento(bool &was_closed,Evento evento){
    uint8_t cant_personajes = (uint8_t)evento.eventos_personaje.size();
    skt_jugador.sendall(&cant_personajes, sizeof(cant_personajes), &was_closed);

    for(EventoPersonaje p : evento.eventos_personaje){  
        skt_jugador.sendall(&p, sizeof(p), &was_closed);
        if(was_closed){
            throw std::runtime_error("Error, se cerro la conexion con el servidor");
        }
    }
    /*

    for(EventoEnemigo e : evento.eventos_enemigo){  
        skt_jugador.sendall(&e, sizeof(e), &was_closed);
        if(was_closed){
            throw std::runtime_error("Error, se cerro la conexion con el servidor");
        }
    }
    
    
    */
}


void ProtocoloServidor::enviar_lista_partidas(MonitorPartidas monitor_partidas, bool &was_closed){
    InfoPartida info_partida;
    std::map<uint32_t, Partida*> partidas = monitor_partidas.obtener_partidas();
    for (auto it = partidas.begin(); it != partidas.end(); ++it) {
            std::cout << "ENVIANDO LISTA" << std::endl;

        info_partida.id_partida = htonl(it->first);
        info_partida.jugadores=  it->second->jugadores();
        info_partida.max_jugadores = it->second->max();
        //skt_jugador.sendall(&info_partida,sizeof(info_partida), &was_closed);
        std::cout << "CODIGO " << info_partida.codigo << std::endl;
        std::cout << "ID PARTIDA " << info_partida.id_partida << std::endl;
        std::cout << "JUGADORES " << (int)info_partida.jugadores << "/"<< (int)info_partida.max_jugadores  << std::endl;
    }
}


ProtocoloServidor::~ProtocoloServidor(){
    skt_jugador.shutdown(SHUT_RDWR);
    skt_jugador.close();
}