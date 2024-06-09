#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <yaml-cpp/yaml.h>



struct ConfigObjeto {
    uint32_t ancho;
    uint32_t alto;
    double tiempo_reaparicion;
    uint32_t vida_restaurada;
    uint32_t puntos_otorgados;
};

struct ConfigBala {
        uint16_t municion;
        double tiempo_entre_disparo;
        int velocidad_del_proyectil;
        uint8_t danio;
        uint32_t rango_explosion;
        uint32_t ancho;
        uint32_t largo;
        double tiempo_reaparicion;
};


class Configuracion {
private:
   uint8_t vida_personaje;
    int velocidad_x_personaje;
    int velocidad_y_personaje;
    int gravedad;
    double tiempo_invulnerabilidad;
    double tiempo_intoxicacion;
    int ancho_personaje;
    int alto_personaje;

    // Atributos de habilidades por personaje
    double enfriamiento_habilidad_jazz;
    int velocidad_y_habilidad_jazz;
    double enfriamiento_habilidad_spaz;
    int velocidad_x_habilidad_spaz;
    double enfriamiento_habilidad_lori;
    int velocidad_x_habilidad_lori;
    int velocidad_y_habilidad_lori;

    //Atributos de partida

    int duracion_segundos;

    // Atributos de pantalla
    int ancho_pantalla;
    int alto_pantalla;

    // Atributos de estado

    double tiempo_estado_muerto;
    double tiempo_estado_herido;

    // Atributos de municion

    std::map<uint8_t, ConfigBala> config_balas;

    // Atributo de objeto

    std::map<uint8_t, ConfigObjeto> config_objetos;

    //Atributos de enemigos

    int vida_default_enemigo;
    int danio_default_enemigo;
    int velocidad_enemigo;
    int ancho_enemigo;
    int alto_enemigo;
    int vida_fencer;
    int vida_lizzard;
    int vida_rat;
    double tiempo_reaparicion_enemigo;
    
    Configuracion(const YAML::Node& config);

public:
    static Configuracion& config();

    Configuracion(const Configuracion&) = delete;

    Configuracion& operator=(const Configuracion&) = delete;


    uint8_t getVidaPersonaje() const { return vida_personaje; }
    int getVelocidadXPersonaje() const { return velocidad_x_personaje; }
    int getVelocidadYPersonaje() const { return velocidad_y_personaje; }
    int getGravedad() const { return gravedad; }
    double getEnfriamientoHabilidadJazz() const { return enfriamiento_habilidad_jazz; }
    int getVelocidadYHabilidadJazz() const { return velocidad_y_habilidad_jazz; }
    double getEnfriamientoHabilidadSpaz() const { return enfriamiento_habilidad_spaz; }
    int getVelocidadXHabilidadSpaz() const { return velocidad_x_habilidad_spaz; }
    double getEnfriamientoHabilidadLori() const { return enfriamiento_habilidad_lori; }
    int getVelocidadXHabilidadLori() const { return velocidad_x_habilidad_lori; }
    int getVelocidadYHabilidadLori() const { return velocidad_y_habilidad_lori; }
    double getTiempoInvulnerabilidad() const { return tiempo_invulnerabilidad; }
    double getTiempoIntoxicacion() const { return tiempo_intoxicacion; }
    int getAnchoPersonaje() const { return ancho_personaje; }
    int getAltoPersonaje() const { return alto_personaje; }

    //Getters para valores de partida
    int getDuracionPartida() const {return duracion_segundos;}

    // Getters para los valores de la pantalla
    int getAnchoPantalla() const { return ancho_pantalla; }
    int getAltoPantalla() const { return alto_pantalla; }

    // Getters para Estado
    double getTiempoEstadoMuerto() const {return tiempo_estado_muerto;}
    double getTiempoEstadoHerido() const {return tiempo_estado_herido;}

    // Getters para Municion
    const ConfigBala& obtenerBala(uint8_t codigo_bala) const {
        auto it = config_balas.find(codigo_bala);
        if (it != config_balas.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Bala no encontrada en la config.");
        }
    }

    // Getters para Objetos
    const ConfigObjeto& obtenerObjeto(uint8_t codigo_objeto) const {
        auto it = config_objetos.find(codigo_objeto);
        if (it != config_objetos.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Objeto no encontrado en la config.");
        }
    }

    //Getters para enemigos
    int obtenerVidaDefaultEnemigo() const {return vida_default_enemigo;}
    int obtener_danio_default_enemigo() const {return danio_default_enemigo;}
    int obtenerVelocidadEnemigos() const {return velocidad_enemigo;}
    int obtenerAnchoEnemigo() const {return ancho_enemigo;}
    int obtenerAltoEnemigo() const {return alto_enemigo;}
    int obtenerVidaFencer() const {return vida_fencer;}
    int obtenerVidaLizzard() const {return vida_lizzard;}
    int obtenerVidaRat() const {return vida_rat;}
    double obtenerTiempoReaparicionEnemigo() const {return tiempo_reaparicion_enemigo;}

};



#endif