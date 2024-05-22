#ifndef CLIENT_RECIBIDOR_LOBBY_H_
#define CLIENT_RECIBIDOR_LOBBY_H_

#include "LobbyProtocolo.h"
#include "../common_src/thread.h"
#include "../common_src/Accion.h"

class RecibidorLobby : public Thread{
private:
    LobbyProtocolo *lobby_protocolo;
public:
    RecibidorLobby(LobbyProtocolo *lobby_protocolo);

    void run() override;

    ~RecibidorLobby() override;
};


#endif