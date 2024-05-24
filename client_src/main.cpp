#include <iostream>
#include <string>
#include "cliente.h"
#include <SDL2/SDL.h>

#define ERROR 1
#define SUCCESS 0

int main(int argc, char* argv[]) {
    try {
        if (!Cliente::verificar_argumentos(argc, argv)) {
            return ERROR;
        }
        const char* hostname = argv[1];
        const char* servname = argv[2];
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
        }

        Cliente cliente(hostname, servname);
        cliente.comunicarse_con_el_servidor();
    }catch (...) {
        // Loggear el error.
        return ERROR;
    }
    return SUCCESS;
}
