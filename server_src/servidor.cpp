#include "servidor.h"


Servidor::Servidor(const std::string &puerto) : puerto(puerto){}


void Servidor::run(){
    while(std::cin.get() != 'q'){
        /*Esperando mensaje de salida*/
    }
}