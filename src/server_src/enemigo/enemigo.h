#ifndef SERVER_ENEMIGO_H_
#define SERVER_ENEMIGO_H_

#include <chrono>
#include <cmath>
#include <iostream>

#include "../common_src/accion.h"
#include "../common_src/codigo_enemigo.h"
#include "../configuracion.h"
#include "../personaje/personaje.h"
#include "../bala/bala.h"


class Personaje;
class Bala;

#define WIDTH 640
#define HEIGHT 480

class Enemigo {
protected:
    uint32_t id_enemigo;  // EL ATRIBUTO ID PROBABLEMENTE HAYA QUE REMOVERLO
    uint32_t posicion_x;
    uint32_t posicion_y;
    int vida;
    uint32_t puntos;
    bool esta_quieto;

    uint32_t ancho;
    uint32_t alto;


    double velocidad_x;
    double tiempo_muerte;
    double tiempo_reaparicion;
    uint8_t direccion_mirando;
    bool vivo;
    int iteraciones_para_revivir;

    int pasos_patrullando;
    int danio;

    virtual void mover_derecha();

    virtual void mover_izquierda();

    virtual void patrullar();

public:
    explicit Enemigo(uint32_t id_enemigo);

    // Acciones
    virtual void quedarse_quieto();

    virtual void matar();

    virtual void revivir();

    virtual bool esta_vivo();

    virtual void recibir_golpe(uint8_t golpe, std::chrono::duration<double> tiempo_transcurrido);
    
    virtual void recibir_golpe(Bala bala, std::chrono::duration<double> tiempo_transcurrido);

    virtual void recibir_golpe(Personaje *personaje, std::chrono::duration<double> tiempo_transcurrido);


    virtual void inflingir_danio(Personaje *personaje, std::chrono::duration<double> tiempo_transcurrido);

    
    // Acciones

    // Getters Snapshot
    virtual uint32_t obtener_posicionX();

    virtual uint32_t obtener_posicionY();

    virtual uint8_t obtener_vida();

    virtual uint8_t obtener_movimiento();

    virtual uint32_t obtener_ancho();

    virtual uint32_t obtener_alto();

    virtual int obtener_danio();

    virtual bool mirando_izquierda();

    virtual uint32_t obtener_puntos();

    // Getters Snapshot

    virtual void actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido);

    virtual ~Enemigo();

    // Metodos virtuales para los diferentes personajes enemigos

    virtual uint8_t obtener_personaje() = 0;
};

#endif
