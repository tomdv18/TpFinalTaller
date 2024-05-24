#include <iostream>
#include "personaje.h"

#include "../common_src/socket.h"



void realizar_accion(uint8_t &accion, Personaje &personaje) {
    
    int velocidad = 5;
    int coordenada_x_actual = personaje.get_coordenada_x();
    int coordenada_y_actual = personaje.get_coordenada_y();

    if(accion == 0x01) {
        coordenada_x_actual += velocidad;
        personaje.set_coordenada_x(coordenada_x_actual);
    } else if(accion == 0x02) {
        coordenada_x_actual -= velocidad;
        personaje.set_coordenada_x(coordenada_x_actual);
    } else if(accion == 0x03) {
        coordenada_y_actual -= velocidad;
        personaje.set_coordenada_y(coordenada_y_actual);
    } else if(accion == 0x04) {
        coordenada_y_actual += velocidad;
        personaje.set_coordenada_y(coordenada_y_actual);
    }

}


int main(int argc, char* argv[]) {

    // Almaceno los argumentos
    const char* servname = argv[1];

    // Recibo los mensajes del cliente
    Socket skt(servname);
    Socket peer = skt.accept();
    bool was_closed = false;
    Personaje personaje;

    while (!was_closed) {
        uint8_t byte;
        peer.recvall(&byte, sizeof(byte), &was_closed);
        if(was_closed) {
            break;
        }
        std::cout << (static_cast<int>(byte)) << std::endl;
        realizar_accion(byte, personaje);
        
        peer.sendall(&byte, sizeof(byte), &was_closed);
    }

    return 0;
}
