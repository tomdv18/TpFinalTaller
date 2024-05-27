#include "protocolo_cliente.h"

#include <vector>

#include <netinet/in.h>

ProtocoloCliente::ProtocoloCliente(Socket &skt):
skt(skt)
{}

static uint8_t serializar(AccionJuego& accion_juego) {
    return static_cast<uint8_t>(accion_juego);
}

bool ProtocoloCliente::enviar_accion_juego(AccionJuego &accion_juego) {
    bool was_closed = false;
    uint8_t byte = serializar(accion_juego);

    skt.sendall(&byte, sizeof(byte), &was_closed);

    return !was_closed;
}

Evento ProtocoloCliente::deserializar(uint8_t byte) {
    Evento evento;
    evento.accion_juego = static_cast<AccionJuego>(byte);
    return evento;
}

// Ver como recibir el evento final
bool ProtocoloCliente::recibir_evento(Evento &evento) {
    bool was_closed = false;
    uint8_t byte;
    skt.recvall(&byte, sizeof(byte), &was_closed);

    evento = deserializar(byte);

    return !was_closed;
}
