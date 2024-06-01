#include "cliente.h"

#include <SDL2pp/SDL2pp.hh>
#include <syslog.h>
#include <unistd.h>


#define MAX_EVENTOS 256   // Numero a definir
#define MAX_ACCIONES 256  // Numero a definir
#define WIDTH 640
#define HEIGHT 480
#define FRAME_RATE 50000
std::string const PATH_JAZZ = "../client_src/Images/soldier2.png";

Cliente::Cliente(Socket& skt): skt(skt), estado(true), renderizado() {}

bool Cliente::verificar_argumentos(int argc, char* args[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Bad program call. Expected %s <hostname> <servname>", args[0]);
        return false;
    }
    //
    return true;
}

bool atrapar_eventos_entrada(Queue<CodigoAccion>& queue_accion) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
            case SDL_KEYDOWN: {  // Presiono la tecla
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
                    case SDLK_w:
                        queue_accion.try_push(ARRIBA);
                        break;
                    case SDLK_s:
                        queue_accion.try_push(ABAJO);
                        break;
                }
                break;  // Salir del bloque SDL_KEYDOWN
    
            }
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&)evento;
                 switch (keyEvent.keysym.sym) {
                    case SDLK_d:
                        queue_accion.try_push(QUIETO);
                        break;
                    case SDLK_a:
                        queue_accion.try_push(QUIETO);
                        break;
                    case SDLK_w:
                        queue_accion.try_push(QUIETO);
                        break;
                    case SDLK_s:
                        queue_accion.try_push(QUIETO);
                        break;
                }
                break;
            }
            case SDL_QUIT:
                return false;
        }
    }
    return true;
}

void Cliente::comunicarse_con_el_servidor() {
    Queue<Evento> queue_eventos(MAX_EVENTOS);
    Queue<CodigoAccion> queue_accion(MAX_ACCIONES);
    RecibidorCliente recibidor_cliente(skt, queue_eventos, estado);
    recibidor_cliente.start();

    this->renderizado.inicializar_SDL2pp();
    this->renderizado.crear_ventana_y_render("Juego", WIDTH, HEIGHT);
    this->renderizado.crear_personaje();
    
    

    EnviadorCliente enviador_cliente(skt, queue_accion);
    enviador_cliente.start();
    try {

        while (estado) {
            auto inicio = std::chrono::high_resolution_clock::now();
            estado = atrapar_eventos_entrada(queue_accion);

            Evento evento;

            queue_eventos.try_pop(evento);

            renderizado.renderizar(evento);

            auto fin = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> tiempo = fin - inicio;
            double tiempo_transcurrido = tiempo.count();
            double frames = 1000/40.0; // casi el doble del server, asi lo procesa mas rapido y se ve mas fluido
            double tiempo_descanso = frames - tiempo_transcurrido;

            if (tiempo_descanso > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(tiempo_descanso)));
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(frames)));
            }

            // la cantidad de segundos que debo dormir se debe ajustar en función
            // de la cantidad de tiempo que demoró el atrapar_eventos_entrada, efectuar_evento y
            // renderizar?
           // usleep(500000);
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