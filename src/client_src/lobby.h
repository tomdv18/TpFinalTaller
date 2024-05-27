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

    LobbyProtocolo lobby_protocolo;

    RecibidorLobby recibidor_lobby;

public:
    Lobby(const std::string &hostname, const std::string &servname);

    void procesar_lobby(bool &was_closed, bool &jugando);

    void main();


};







#endif