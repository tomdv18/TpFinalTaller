#ifndef CLIENTE_H
#define CLIENTE_H

#include "../common_src/socket.h"
#include "protocolo_cliente.h"
#include "renderizado.h"
#include "recibidor_cliente.h"
#include "../common_src/queue.h"
#include "../common_src/accion_juego.h"
#include "../common_src/evento.h"

/**
 * TDA Cliente.
 * Su función principal es comunicarse con el servidor enviando
 * acciones.
 */

class Cliente {
private:
    Socket skt;        
    ProtocoloCliente protocolo_cliente;
public:
    /**
     * Constructor de la clase Cliente.
     *
     * @param hostname El nombre del host al que se conectará el cliente.
     * @param servname El nombre del servicio o puerto al que se conectará el cliente.
     */
    explicit Cliente(const char* hostname, const char* servname);

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
