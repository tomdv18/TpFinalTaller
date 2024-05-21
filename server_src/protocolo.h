#ifndef SERVER_PROTOCOLO_H_
#define SERVER_PROTOCOLO_H_


#include "../common_src/socket.h"

class Protocolo{
private:
    Socket skt;
    
public:
    explicit Protocolo(Socket socket);
    
    void handshake();
    
    void enviar();
    
    void recibir();

    void cerrar();

    Protocolo(const Protocolo&) = delete;
    Protocolo& operator = (const Protocolo&) = delete;
    Protocolo(Protocolo&&) = default;
    Protocolo& operator=(Protocolo&&) = default;

};


#endif