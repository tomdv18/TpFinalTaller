#ifndef RECIBIDOR_CLIENTE_H
#define RECIBIDOR_CLIENTE_H

#include "../common_src/thread.h"
#include "../common_src/queue.h"
#include "../common_src/evento.h"

#include "protocolo_cliente.h"

class RecibidorCliente: public Thread {
    private:
    ProtocoloCliente protocolo_cliente;
    Queue<Evento> &queue_eventos;
    
    public:
    explicit RecibidorCliente(Socket& skt, Queue<Evento>& queue);

    /**
     * Ejecuta el hilo encargado de recibir todo
     * lo que le envia el servidor.
     */
    virtual void run() override;

    /**
     * Destructor de la clase.
     */
    virtual ~RecibidorCliente();
};

#endif