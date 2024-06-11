#ifndef CAMARA_H
#define CAMARA_H

#include "SDL2pp/SDL2pp.hh"

/**
 * @class Camara
 * @brief Clase que representa una cámara para seguir a un jugador en un entorno 2D.
 *
 * La clase Camara se encarga de manejar la posición y los límites de una cámara en un juego 2D,
 * asegurándose de que la cámara no se salga de los límites del nivel.
 */
class Camara {
private:
    SDL2pp::Rect camara; ///< Rectángulo que define la posición y el tamaño de la cámara.

    /**
     * @brief Verifica y ajusta la posición de la cámara para que no se salga de los límites del nivel.
     */
    //void verificar_limites();

public:
    /**
     * @brief Constructor de la clase Camara.
     * 
     * Inicializa la cámara con una posición y tamaño específicos dentro de los límites del nivel.
     * 
     * @param x_inicial La posición inicial en el eje X de la cámara.
     * @param y_inicial La posición inicial en el eje Y de la cámara.
     * @param ancho El ancho de la cámara.
     * @param alto El alto de la cámara.
     */
    explicit Camara(int x_inicial, int y_inicial, int ancho, int alto);

    /**
     * @brief Actualiza la posición de la cámara centrada en la posición dada.
     * 
     * @param x La nueva posición en el eje X a la que la cámara debe centrarse.
     * @param y La nueva posición en el eje Y a la que la cámara debe centrarse.
     */
    void actualizar_posicion(int x, int y);

    /**
     * @brief Obtiene la posición X actual de la cámara.
     * 
     * @return La posición X de la cámara.
     */
    int obtener_posicion_x();

    /**
     * @brief Obtiene la posición Y actual de la cámara.
     * 
     * @return La posición Y de la cámara.
     */
    int obtener_posicion_y();

    /**
     * @brief Define una nueva posición X para la cámara.
     * 
     * @param x La nueva posición X para la cámara.
     */
    void definir_posicion_x(int x);

    /**
     * @brief Define una nueva posición Y para la cámara.
     * 
     * @param y La nueva posición Y para la cámara.
     */
    void definir_posicion_y(int y);
};

#endif 