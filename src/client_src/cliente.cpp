#include "cliente.h"
#include <SDL2pp/SDL2pp.hh>
#include <unistd.h>
#include <syslog.h>

#define MAX_EVENTOS 256 // Numero a definir
#define MAX_ACCIONES 256 // Numero a definir
#define WIDTH 640
#define HEIGHT 480

Cliente::Cliente(Socket &skt):
skt(skt), estado(true)
{}

bool Cliente::verificar_argumentos(int argc, char* args[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Bad program call. Expected %s <hostname> <servname>", args[0]);
        return false;
    }
    return true;
}

void efectuar_evento(Evento evento) {

    for(EventoPersonaje p: evento.eventos_personaje){
        // Por cada personajes que recorres, lo graficas (Santiago)
        std::cout << "PERSONAJE DE " << p.id_jugador << std::endl;
        std::cout << "VIDA " << p.vida << std::endl;
        std::cout << "EN LA POSICION " << "(" << p.posicion_x << "," << p.posicion_y << ")" << std::endl;
    }
}

bool atrapar_eventos_entrada(Queue<CodigoAccion>& queue_accion) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
            case SDL_KEYDOWN: { // Presiono la tecla
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&)evento;
                switch (keyEvent.keysym.sym) {
                    case SDLK_q:
                        return false;
                    case SDLK_d:
                        queue_accion.try_push(DERECHA);
                        break;
                    case SDLK_a:
                        queue_accion.try_push(IZQUIERDA);
                        break;
                }
                break; // Salir del bloque SDL_KEYDOWN
            } // Ver que pasa si deja de presionar una tecla (otra accion?)
            case SDL_QUIT:
                return false;
        }
    }
    return true;
}

void renderizar(SDL2pp::Renderer &renderer) {
    // Pintamos el fondo de blanco
    renderer.SetDrawColor(0xff, 0xff, 0xff, 0xff);
    renderer.Clear();

    // Defino el rectángulo
    SDL_Rect rect;
    rect.x = 200;
    rect.y = 200;
    rect.w = 50;  // ancho del rectángulo (250 - 200)
    rect.h = 50;  // alto del rectángulo (250 - 200)

    // Establezco el color del rectángulo (magenta en este caso)
    renderer.SetDrawColor(0xff, 0x00, 0xff, 0xff);

    // Dibujo el rectángulo
    renderer.FillRect(rect);

    // Presento el renderizado
    renderer.Present();
}

void Cliente::comunicarse_con_el_servidor() {
    Queue<Evento> queue_eventos(MAX_EVENTOS);
    Queue<CodigoAccion> queue_accion(MAX_ACCIONES);
    RecibidorCliente recibidor_cliente(skt, queue_eventos, estado);
    recibidor_cliente.start();

    EnviadorCliente enviador_cliente(skt, queue_accion);
    enviador_cliente.start();
    try {
        // Inicializo biblioteca de SDL
        SDL2pp::SDL sdl(SDL_INIT_VIDEO);
        // Creo una ventana dinamica con titulo "JUEGO"
        SDL2pp::Window window("Juego", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WIDTH, HEIGHT,
                              SDL_WINDOW_RESIZABLE);

        // Creo renderer
        SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

        while (estado){
            estado = atrapar_eventos_entrada(queue_accion);
            
            Evento evento;
            queue_eventos.try_pop(evento);
            efectuar_evento(evento);
            
            renderizar(renderer);

            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el atrapar_eventos_entrada, efectuar_evento y renderizar?
            usleep(500000);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return;
    }    
    queue_accion.close();
    queue_eventos.close();
    terminar_comunicacion();
}

void Cliente::terminar_comunicacion() {
    skt.shutdown(2);
    skt.close();
}