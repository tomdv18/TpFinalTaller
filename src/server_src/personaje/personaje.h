#ifndef SERVER_PERSONAJE_H_
#define SERVER_PERSONAJE_H_

#include <chrono>
#include <cmath>
#include <iostream>
#include <map>

#include "../common_src/accion.h"
#include "../common_src/evento.h"
#include "../common_src/codigo_estado.h"
#include "../estado/estado.h"

#include "../arma.h"
#include "../objeto/objeto.h"
#include "../rectangulo.h"



#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50
#define VELOCIDAD 5
#define VELOCIDAD_SALTO 30
#define GRAVEDAD 3
#define ENFRIAMIENTO_JAZZ 5
#define ENFRIAMIENTO_LORI 5
#define ENFRIAMIENTO_SPAZ 5

class Objeto;
class Estado;

class Personaje {
protected:
    uint32_t id_jugador;
    uint32_t posicion_x;
    uint32_t posicion_y;
    int8_t vida; //DEBE SER INT PARA PODER SER NEGATIVO
    bool esta_quieto;

    int velocidad_x;
    int velocidad_y;


    bool corriendo;

    bool saltando;
    double tiempo_salto;

    bool usando_especial;
    double tiempo_especial;

    uint8_t direccion_mirando;


    bool esta_disparando;
    bool muerto;


    Arma arma;

    Estado *estado;

    bool en_superficie;


public:
    explicit Personaje(uint32_t id_jugador);


    int obtener_velocidad(){
        return velocidad_x;
    }
    // Acciones

    virtual void mover_derecha(std::chrono::duration<double> tiempo_transcurrido);

    virtual void mover_izquierda(std::chrono::duration<double> tiempo_transcurrido);

    virtual void mover_arriba(std::chrono::duration<double> tiempo_transcurrido);

    virtual void mover_abajo();

    virtual void quedarse_quieto();

    virtual void correr_rapido(std::chrono::duration<double> tiempo_transcurrido);

    virtual void correr();

    virtual void recibir_golpe(uint8_t golpe, std::chrono::duration<double> tiempo_transcurrido);

    virtual uint8_t disparar(std::chrono::duration<double> tiempo_transcurrido);

    virtual void dejar_disparar();

    virtual bool hay_colision(uint32_t pos_x, uint32_t pos_y, uint32_t ancho, uint32_t largo);

    virtual bool mirando_izquierda();

    virtual void posicion_X(uint32_t x);

    virtual void posicion_Y(uint32_t y);

    virtual void revivir();

    // Acciones

    // Getters Snapshot
    virtual uint32_t obtener_posicionX();

    virtual uint32_t obtener_posicionY();

    virtual uint8_t obtener_vida();

    virtual uint8_t obtener_movimiento();

    virtual uint8_t obtener_corriendo();

    virtual uint8_t obtener_habilidad();

    virtual uint8_t obtener_saltando();

    virtual uint8_t obtener_disparando();

    virtual uint8_t obtener_estado();

    virtual bool esta_muerto();


    virtual uint32_t obtener_ancho();

    virtual uint32_t obtener_alto();

    // Getters Snapshot

    virtual void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido,
                                     std::map<uint32_t, Objeto*>& map_objetos, std::map<uint32_t, Objeto*>& map_objetos_comunes);

    virtual ~Personaje();

    // Metodos virtuales para los diferentes personajes

    virtual uint8_t obtener_personaje() = 0;

    virtual void usar_habilidad(std::chrono::duration<double> tiempo_transcurrido) = 0;

public:
    // Logica de Estados
    void cambiarEstado(Estado *estado);

    void manejarEstado(uint8_t codigo_estado, std::chrono::duration<double> tiempo_transcurrido);

    void actualizar(double tiempo);
};

#endif
