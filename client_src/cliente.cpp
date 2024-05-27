#include "cliente.h"
#include <SDL2/SDL.h>

#include <syslog.h>

#define MAX_EVENTOS 256 // Numero a definir

Cliente::Cliente(const char* hostname, const char* servname):
skt(hostname, servname), protocolo_cliente(skt)
{}

bool Cliente::verificar_argumentos(int argc, char* args[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Bad program call. Expected %s <hostname> <servname>", args[0]);
        return false;
    }
    return true;
}

/**
 * Lee entrada standar (estando en el juego).
*/
static AccionJuego leer_entrada_estandar(SDL_Event &event){
    AccionJuego accion_juego = NINGUNA; // En teoria, nunca debe valer esto, capaz conviene un map
    
    // Ver como leer teclas con SDL (Santiago)
    /**
     * if(event.key.keysym.sym == LEFT) {
     * accion_juego = DERECHA
     * }
    */

    if(event.key.keysym.sym == SDLK_RIGHT) {
        accion_juego = AccionJuego::DERECHA;
        return accion_juego;
    } else if (event.key.keysym.sym == SDLK_LEFT) {
        accion_juego = AccionJuego::IZQUIERDA;
        return accion_juego;
    } else if (event.key.keysym.sym == SDLK_UP) {
        accion_juego = AccionJuego::ARRIBA;
        return accion_juego;
    } else if (event.key.keysym.sym == SDLK_DOWN) {
        accion_juego = AccionJuego::ABAJO;
        return accion_juego;
    }
    // Asi con las demas acciones...
    return accion_juego;
}

void Cliente::comunicarse_con_el_servidor() {
    Queue<Evento> queue_eventos(MAX_EVENTOS);
    RecibidorCliente recibidor_cliente(skt, queue_eventos);
    Renderizado renderizado(queue_eventos); 
    
    SDL_Event event;
    recibidor_cliente.start();
    renderizado.start();
    bool running = true;
    while(running) {
        while(SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }

            if(event.type == SDL_KEYDOWN) {

                AccionJuego accion_juego = leer_entrada_estandar(event);
                if (accion_juego == AccionJuego::SALIR) {
                    break;
                }
                if(!protocolo_cliente.enviar_accion_juego(accion_juego)) {
                    break;
                }
            }
        }
    }
    queue_eventos.close();
    terminar_comunicacion();
}

void Cliente::terminar_comunicacion() {
    skt.shutdown(2);
    skt.close();
}