#include "recibidor_cliente.h"

RecibidorCliente::RecibidorCliente(Socket& skt, Queue<Evento>& queue):
        protocolo_cliente(skt), queue_eventos(queue){}

void RecibidorCliente::run() {
    /*
    Evento evento;
    while (true) {
        if (protocolo_cliente.recibir_evento(evento)) {
            try {
                queue_eventos.push(evento);
            } catch (const ClosedQueue&) {
                // Ver
            }
        } else {
            // Ver
            break;
        }
    }
    */
}

RecibidorCliente::~RecibidorCliente() { 
    std::cout << "Recibidor joineado\n";
    this->join(); }