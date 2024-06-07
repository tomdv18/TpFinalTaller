#include "cliente.h"

#include <SDL2pp/SDL2pp.hh>
#include <syslog.h>
#include <unistd.h>
#include <unordered_set>
#include <optional>


#define MAX_EVENTOS 256
#define MAX_ACCIONES 256
#define WIDTH 640
#define HEIGHT 480

Cliente::Cliente(Socket& skt): skt(skt), estado(true), personajes(), renderizado(personajes) {
    bool was_closed = false;
    skt.recvall(&id_jugador,sizeof(id_jugador), &was_closed);
    id_jugador = ntohl(id_jugador);
}

bool Cliente::verificar_argumentos(int argc, char* args[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Bad program call. Expected %s <hostname> <servname>", args[0]);
        return false;
    }
    //
    return true;
}

bool atrapar_eventos_entrada(Queue<CodigoAccion>& queue_accion) {
    static std::unordered_set<SDL_Keycode> teclas_presionadas;
    static std::optional<CodigoAccion> ultima_direccion;

    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
            case SDL_KEYDOWN: {  // Presiono la tecla
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&)evento;
                teclas_presionadas.insert(keyEvent.keysym.sym);
                switch (keyEvent.keysym.sym) {
                    case SDLK_q:
                        return false;
                    case SDLK_d:
                        queue_accion.try_push(DERECHA);
                        ultima_direccion = DERECHA;
                        break;
                    case SDLK_a:
                        queue_accion.try_push(IZQUIERDA);
                        ultima_direccion = IZQUIERDA;
                        break;
                    case SDLK_w:
                        queue_accion.try_push(ARRIBA);
                        ultima_direccion = ARRIBA;
                        break;
                    case SDLK_s:
                        queue_accion.try_push(ABAJO);
                        ultima_direccion = ABAJO;
                        break;
                    case SDLK_LSHIFT:
                        queue_accion.try_push(CORRER_RAPIDO);
                        break;
                    case SDLK_k:
                        queue_accion.try_push(ESPECIAL);
                        break;
                    case SDLK_l:
                        queue_accion.try_push(DISPARAR);
                        break;
                }
                break;  // Salir del bloque SDL_KEYDOWN
            }
            case SDL_KEYUP: {
                SDL_KeyboardEvent& keyEvent = (SDL_KeyboardEvent&)evento;
                teclas_presionadas.erase(keyEvent.keysym.sym);
                switch (keyEvent.keysym.sym) {
                    case SDLK_d:
                    case SDLK_a:
                    case SDLK_w:
                    case SDLK_s:
                        if (teclas_presionadas.empty()) {
                            queue_accion.try_push(QUIETO);
                            ultima_direccion.reset();
                        } else {
                            bool alguna_tecla_direccion_presionada = false;
                            for (const auto& tecla : teclas_presionadas) {
                                switch (tecla) {
                                    case SDLK_d:
                                        queue_accion.try_push(DERECHA);
                                        ultima_direccion = DERECHA;
                                        alguna_tecla_direccion_presionada = true;
                                        break;
                                    case SDLK_a:
                                        queue_accion.try_push(IZQUIERDA);
                                        ultima_direccion = IZQUIERDA;
                                        alguna_tecla_direccion_presionada = true;
                                        break;
                                    case SDLK_w:
                                        queue_accion.try_push(ARRIBA);
                                        ultima_direccion = ARRIBA;
                                        alguna_tecla_direccion_presionada = true;
                                        break;
                                    case SDLK_s:
                                        queue_accion.try_push(ABAJO);
                                        ultima_direccion = ABAJO;
                                        alguna_tecla_direccion_presionada = true;
                                        break;
                                }
                            }
                            if (!alguna_tecla_direccion_presionada) {
                                queue_accion.try_push(QUIETO);
                                ultima_direccion.reset();
                            }
                        }
                        break;
                    case SDLK_LSHIFT:
                        queue_accion.try_push(CORRER);
                        break;
                    case SDLK_l:
                        queue_accion.try_push(DEJAR_DISPARAR);
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
    ProtocoloCliente protocolo_temporal(skt);
    MapaEntidades mapa = protocolo_temporal.recibir_mapa();
    Camara camara(0, 0, WIDTH, HEIGHT);
    
    Queue<Evento> queue_eventos(MAX_EVENTOS);
    Queue<CodigoAccion> queue_accion(MAX_ACCIONES);
    RecibidorCliente recibidor_cliente(skt, queue_eventos, estado);
    recibidor_cliente.start();
    
    this->renderizado.recibir_id(id_jugador);
    this->renderizado.inicializar_SDL2pp();
    this->renderizado.crear_ventana_y_render("JazzJack Rabbit 2", WIDTH, HEIGHT);
    
    this->renderizado.iniciar_mapa(std::move(mapa));
    this->renderizado.iniciar_camara(std::move(camara));
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

            double frames = 1000/40.0;
            double tiempo_descanso = frames - tiempo_transcurrido;

            if (tiempo_descanso > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(tiempo_descanso)));
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(frames)));
            }

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