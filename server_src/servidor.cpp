#include "servidor.h"


Servidor::Servidor(const std::string &puerto) : 
puerto(puerto),
servidor_cerrado(false){}


void Servidor::run(){
    while(std::cin.get() != 'q'){
        /*Esperando mensaje de salida*/
    }
    
}