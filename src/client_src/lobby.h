#ifndef CLIENT_LOBBY_H_
#define CLIENT_LOBBY_H_

#include "../common_src/queue.h"
#include "lobbyProtocolo.h"
#include "../common_src/accion.h"
#include "recibidorLobby.h"

#include "SDL2/SDL.h"
#include <sstream>

class Lobby{
private:
    Socket skt;

    LobbyProtocolo lobby_protocolo;

    RecibidorLobby recibidor_lobby;

public:
    Lobby(const std::string &hostname, const std::string &servname);

    bool crear_partida(uint8_t max_jugadores);

    bool unirse_partida(uint32_t codigo_partida);

    void elegir_personaje(uint8_t personaje);

    void close();

    Socket& obtener_socket();

    std::vector<InfoPartida> obtener_partidas();

};







#endif