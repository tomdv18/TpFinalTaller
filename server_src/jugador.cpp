#include "jugador.h"


Jugador::Jugador(Socket skt, int id) : 
id_jugador(id),
sigue_jugando(true),
protocolo(std::move(skt)),
sender(protocolo, sigue_jugando),
receiver(protocolo, sigue_jugando)
{}



void Jugador::run(){
    sender.start();
    receiver.start();
    
}

bool Jugador::esta_vivo(){
    return sigue_jugando;
}

void Jugador::stop(){
    receiver.stop();
    receiver.join();
    sender.join();
}