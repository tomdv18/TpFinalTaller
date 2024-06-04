#ifndef CLIENTE_H
#define CLIENTE_H

#include "../common_src/socket.h"
#include "protocolo_cliente.h"
#include "renderizado.h"
#include "recibidor_cliente.h"
#include "enviadorCliente.h"
#include "../common_src/queue.h"
#include "../common_src/accion.h"
#include "../common_src/evento.h"
#include <arpa/inet.h>




/**
 * TDA Cliente.
 * Su función principal es comunicarse con el servidor enviando
 * acciones.
 */

class Cliente {
private:
    Socket &skt;        
    std::atomic<bool> estado;
    Renderizado renderizado;
    uint32_t id_jugador;
    
public:
    /**
     * Constructor de la clase Cliente.
     *
     * @param skt El socket con el que se comunicara con el cliente.
     */
    explicit Cliente(Socket &skt);

    /**
     * Verifica si se proporcionan los argumentos esperados.
     * Registra un mensaje de error utilizando syslog si los
     * argumentos no son los esperados.
     *
     * @param argc El número de argumentos en la línea de comandos.
     * @param args Un arreglo de cadenas que contiene los argumentos de la línea de comandos.
     * @return Retorna false si los argumentos no son los esperados, caso contrario, verdadero.
     */
    static bool verificar_argumentos(int argc, char* args[]);

    /**
     * Inicia la comunicación con el servidor enviando/recibiendo acciones/eventos.
     */
    void comunicarse_con_el_servidor();

    /**
     * Termina la comunicacion con el servidor.
    */
    void terminar_comunicacion();

    /**
     * Deshabilita la construcción y asignación por copia de objetos.
     */
    Cliente(const Cliente&) = delete;
    Cliente& operator=(const Cliente&) = delete;

    /**
     * Permite la construcción y asignación por movimiento de objetos.
     */
    Cliente(Cliente&&) = default;
    Cliente& operator=(Cliente&&) = default;
};

#endif
