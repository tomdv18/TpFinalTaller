#ifndef SERVER_PROTOCOLO_SERVIDOR_H_
#define SERVER_PROTOCOLO_SERVIDOR_H_

#include "../common_src/socket.h"
#include "../common_src/Accion.h"
#include <memory>
#include <arpa/inet.h>

class ProtocoloServidor{
private:
    Socket skt_jugador;
public:
    ProtocoloServidor(Socket skt);

    uint8_t obtener_accion(bool &was_closed);

    void enviar_accion(bool &was_closed,Accion accion);

    uint8_t leer_jugadores(bool &was_closed);

    uint32_t leer_id_partida(bool &was_closed);

    ~ProtocoloServidor();

private:


};


#endif