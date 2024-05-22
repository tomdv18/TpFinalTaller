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

void ProtocoloServidor::enviar_accion(bool &was_closed,Accion accion){
    skt_jugador.sendall(&accion, sizeof(accion), &was_closed);
}

ProtocoloServidor::~ProtocoloServidor(){
    skt_jugador.shutdown(SHUT_RDWR);
    skt_jugador.close();
}