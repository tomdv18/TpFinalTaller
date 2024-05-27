#ifndef CLIENT_LOBBY_PROTOCOLO_H_
#define CLIENT_LOBBY_PROTOCOLO_H_

#include "../common_src/socket.h"   
#include "../common_src/evento.h"
#include "../common_src/accion.h"
#include <arpa/inet.h>

class LobbyProtocolo{
private:
    Socket skt;
public:
    LobbyProtocolo(const std::string &hostname, const std::string &servname);

    void enviar_accion(uint8_t accion, bool &was_closed);

    void enviar_jugadores(uint8_t jugadores, bool &was_closed);

    void enviar_id_partida(uint32_t id_partida, bool &was_closed);

    Evento recibir_evento(bool &was_closed);

    void close();

    ~LobbyProtocolo();
};





#endif