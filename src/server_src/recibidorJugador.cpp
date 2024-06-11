#include "recibidorJugador.h"

#include <string>


RecibidorJugador::RecibidorJugador(ProtocoloServidor* protocolo_servidor,
                                   MonitorPartidas* monitor_partidas, Queue<Evento>* queue_jugador,
                                   int id, std::atomic<bool>& en_partida,
                                   std::atomic<bool>& conectado):
        protocolo_servidor(protocolo_servidor),
        monitor_partidas(monitor_partidas),
        queue_acciones(nullptr),
        queue_jugador(queue_jugador),
        enviador_jugador(protocolo_servidor, queue_jugador, id, std::ref(en_partida),
                         std::ref(conectado)),
        id(id),
        en_partida(en_partida),
        conectado(conectado) {}
// Leo un .yaml
MapaEntidades importFromYAML(const std::string& filename) {
    MapaEntidades entities;
    YAML::Node config = YAML::LoadFile(filename);
    // Verific0 si el nodo es válido
    if (!config.IsMap()) {
        // Manejo el caso en el que el nodo principal no sea un mapa
        throw std::runtime_error("El archivo YAML no tiene un formato valido");
    }

    // Itero sobre cada entrada en el mapa
    for (auto it = config.begin(); it != config.end(); ++it) {
        std::string entity_name = it->first.as<std::string>();  // Obtener el nombre de la entidad

        // Verifico si el valor asociado con la clave es una secuencia
        if (!it->second.IsSequence()) {
            // Manejar el caso en el que el valor asociado no sea una secuencia
            throw std::runtime_error("Error: La entrada '" + entity_name +
                                     "' no es una secuencia de posiciones válida.");
        }

        // Itero sobre las posiciones de la entidad
        for (std::size_t i = 0; i < it->second.size(); ++i) {
            YAML::Node posNode = it->second[i];
            Position pos = {posNode["x"].as<uint32_t>(), posNode["y"].as<uint32_t>()};
            entities[entity_name].push_back(pos);
        }
    }
    return entities;
}


void RecibidorJugador::run() {

    bool was_closed = false;
    while (conectado) {

        // monitor_partidas->listar_partidas();

        try {
            // Seguir en el lobby mientras no encuentre partida ni se cierre conexion
            while (!en_partida) {
                leer_lobby(std::ref(en_partida), was_closed);
            }
        } catch (std::runtime_error& err) {
            // Se perdio la conexion, salgo
            break;
        }


        // NO se cerro la conexion, se encontro partida
        // Inicio el sender
        try {
            // Empiezo a recibir acciones de partida
            if (!enviador_jugador.is_alive()) {
                enviador_jugador.start();
            }

            while (en_partida) {
                try {
                    Accion accion;
                    accion.id_jugador = id;
                    accion.codigo = protocolo_servidor->obtener_accion(was_closed);
                    queue_acciones->push(accion);
                    if (accion.codigo == LOBBY) {
                        en_partida = false;
                    }

                } catch (const ClosedQueue& err) {
                    // Se cerró la partida, queue cerrada
                    break;
                }
            }
        } catch (std::runtime_error& err) {
            // Se perdio la conexion, salgo
            break;
        }
        // Jugador salio de la partida, lo borro
        monitor_partidas->borrar_jugador(id);
        en_partida = false;
    }
    // Si se perdio la conexion, cierro todo
    en_partida = false;
    conectado = false;
    monitor_partidas->borrar_jugador(id);
    // Cierro queue para destrabar sender
    queue_jugador->close();
}

void RecibidorJugador::leer_lobby(std::atomic<bool>& partida_encontrada, bool& was_closed) {
    uint8_t codigo = protocolo_servidor->obtener_accion(was_closed);
    std::cout << "ACCION " << (int)codigo << std::endl;

    if (was_closed) {
        throw std::runtime_error("Se perdió la conexion con el cliente");
    }

    switch (codigo) {
        case CREAR: {
            // Logica de creacion
            uint8_t max_jugadores = protocolo_servidor->leer_jugadores(was_closed);
            if (was_closed) {
                throw std::runtime_error("Se perdió la conexion con el cliente");
            }
            this->queue_acciones =
                    monitor_partidas->crear_partida(id, max_jugadores, queue_jugador);
            break;
        }
        case UNIRSE: {
            // Logica de unirse
            uint32_t id_partida = protocolo_servidor->leer_id_partida(was_closed);
            if (was_closed) {
                throw std::runtime_error("Se perdió la conexion con el cliente");
            }
            this->queue_acciones = monitor_partidas->unir_jugador(id, id_partida, queue_jugador);
            break;
        }
        case LIST_P: {
            protocolo_servidor->enviar_lista_partidas(*monitor_partidas, was_closed);
            return;
        }
        case SALIR: {
            conectado = false;
            throw std::runtime_error("Jugador desconectado");
        }
        default: {
            throw std::runtime_error("Se perdió la conexion con el cliente");
        }
    }

    if (this->queue_acciones != nullptr) {
        // Se creo la partida, o alguien se unio, debo enviar el mapa
        std::cout << "PARTIDA EMPEZADA " << std::endl;
        Accion accion;
        accion.id_jugador = id;
        accion.codigo = codigo;
        partida_encontrada = true;
        this->queue_acciones->push(accion);

        protocolo_servidor->enviar_confirmacion(EXITO, was_closed);
        protocolo_servidor->enviar_id_jugador(this->id, was_closed);
        // Rompe aca, porque...
        MapaEntidades mapa = importFromYAML("../src/mapas/mapa.yaml");
        protocolo_servidor->enviar_mapa(mapa);
    } else {
        protocolo_servidor->enviar_confirmacion(FALLO, was_closed);
    }
}


void RecibidorJugador::join_enviador() {
    // Si esta en partida, ya se lanzo el sender

    if (queue_acciones != nullptr) {
        enviador_jugador.join();
    }
}

RecibidorJugador::~RecibidorJugador() { std::cout << "RECIBIDOR JOINEADO " << std::endl; }
