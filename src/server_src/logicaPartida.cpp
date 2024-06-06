#include "logicaPartida.h"

#define DURACION_PARTIDA 120.0f

LogicaPartida::LogicaPartida(){
   //map_objetos[0] = new Zanahoria(0, 100, 430, 50, 50, 10);
    map_objetos[0] = new Zanahoria(0, 0, 400, 1, 1000, 250);
    map_objetos[1] = new Solido(0, 0, 400, 1, 1000, 250);
   

   //map_objetos[1] = new Zanahoria(1, 400, 0, 250, 50, 700);
    //map_enemigos[0] = new Lizzard(0); // DESCOMENTAR ESTA LINEA PARA EL MUESTREO DE ENEMIGOS
}


void LogicaPartida::ejecutar(Accion accion, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo){
    switch (accion.codigo){
        case DERECHA:
            mover_derecha(accion.id_jugador);
            break;
        case IZQUIERDA:
            mover_izquierda(accion.id_jugador);
            break;
        case ARRIBA:
            mover_arriba(accion.id_jugador, tiempo);
            break;
        case ABAJO:
            //mover_abajo(accion.id_jugador);  
            break; 
        case CORRER_RAPIDO:
            mover_correr_rapido(accion.id_jugador);
            break;
        case CORRER:
            mover_correr(accion.id_jugador);
        case QUIETO:
            mover_quieto(accion.id_jugador);
            break; 
        case DISPARAR:
            disparar(accion.id_jugador, tiempo);
            std::cout << "DISPARANDO" << std::endl;
            break;
        case DEJAR_DISPARAR:
            dejar_disparar(accion.id_jugador);
            std::cout << "DEJO DE DISPARAR" << std::endl;
            break;
        case ESPECIAL:
            usar_habilidad(accion.id_jugador, tiempo);
        case JAZZ:
            agregar_personaje(accion);
            break;
        case SPAZ:
            agregar_personaje(accion);
        case LORI:
            agregar_personaje(accion);
        default:
            break;
    }
}

void LogicaPartida::mover_derecha(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->mover_derecha();
    }
}

void LogicaPartida::mover_izquierda(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->mover_izquierda();
    }
}

void LogicaPartida::mover_arriba(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;

    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->mover_arriba(tiempo_transcurrido);
    }
}

void LogicaPartida::mover_abajo(uint32_t id_jugador) {
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->mover_abajo();
    }
}

void LogicaPartida::mover_quieto(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->quedarse_quieto();
    }
}

void LogicaPartida::mover_correr_rapido(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->correr_rapido();
    }
}

void LogicaPartida::mover_correr(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->correr();
    }
}

void LogicaPartida::disparar(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo){
    std::chrono::time_point<std::chrono::high_resolution_clock> actual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;

    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        uint8_t codigo_bala = personaje->disparar(tiempo_transcurrido);
        if(codigo_bala != NINGUNA){
            int velocidad = personaje->mirando_izquierda() ? -1 : 1;
            controlador_balas.agregar_bala(codigo_bala,id_jugador,
            personaje->obtener_posicionX(), personaje->obtener_posicionY() + PERSONAJE_HEIGHT/4, velocidad);
        }
    }
}
    
void LogicaPartida::dejar_disparar(uint32_t id_jugador){
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->dejar_disparar();
    }
}

void LogicaPartida::usar_habilidad(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo){
    std::chrono::time_point<std::chrono::high_resolution_clock> actual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;
    Personaje *personaje = map_personajes[id_jugador];
    if(personaje != nullptr){
        personaje->usar_habilidad(tiempo_transcurrido);
    }
}


void LogicaPartida::abandonar_partida(uint32_t id_jugador){
    auto it = map_personajes.find(id_jugador);

    if(it != map_personajes.end()){
        delete it->second;

        map_personajes.erase(it);
    }
}



void LogicaPartida::agregar_personaje(Accion accion){
    //Personaje *personaje;
    switch(accion.codigo){
        case JAZZ:{
            std::cout << "CREAR PERSONAJE JAZZ" << std::endl;
            //personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if(map_personajes[accion.id_jugador] == nullptr){
                map_personajes[accion.id_jugador] = new Jazz(accion.id_jugador);
            }
            break;
        }
        case SPAZ:{
            std::cout << "CREAR PERSONAJE SPAZ" << std::endl;
            //personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if(map_personajes[accion.id_jugador] == nullptr){
                map_personajes[accion.id_jugador] = new Spaz(accion.id_jugador);
            }
            break;
        }
        case LORI:{
            std::cout << "CREAR PERSONAJE LORI" << std::endl;
            //personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if(map_personajes[accion.id_jugador] == nullptr){
                map_personajes[accion.id_jugador] = new Lori(accion.id_jugador);
            }
            break;
        }

        default:
            break;
    }

}

void LogicaPartida::actualizar_partida(std::chrono::time_point<std::chrono::high_resolution_clock> tiempo){
    std::chrono::time_point<std::chrono::high_resolution_clock> actual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;
    for(const auto &par_personaje : map_personajes){
        par_personaje.second->actualizar_posicion(tiempo_transcurrido, map_objetos);
    
    }
    for(const auto &par : map_enemigos){
        par.second->actualizar_posicion(tiempo_transcurrido);

        //Calcular colision con los personajes
    }

    auto& balas = controlador_balas.obtener_balas();  
    auto it = balas.begin();

    while (it != balas.end()) {
        it->actualizar_posicion();
                    
        Rectangulo rect_bala = {  it->obtener_posicionX(),
                                    it->obtener_posicionY(),
                                    it->obtener_ancho(),
                                    it->obtener_largo() };


        // Calcular primero colision con enemigos
        for (const auto& par : map_personajes) {
            if (par.second->hay_colision(
                it->obtener_posicionX(),
                it->obtener_posicionY(),
                it->obtener_ancho(),
                it->obtener_largo())) {
                par.second->recibir_golpe(10);  // Por ahora hardcodeado recibe 10 de daño
                std::cout << "HAY COLISION" << std::endl;
                it->impactar();
                break;
            }
        }

        if (it->obtener_impacto() || it->obtener_posicionX() >= WIDTH) {
            controlador_balas.remover_bala(it->obtener_id_bala());
            //it = balas.erase(it);  
        } else {
            ++it;  
        }
    }
}

Evento LogicaPartida::obtener_snapshot(std::chrono::time_point<std::chrono::high_resolution_clock> start){
    Evento evento;
    evento.eventos_personaje.clear();
    std::chrono::time_point<std::chrono::high_resolution_clock> actual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo = actual - start;
    //std::cout << "Tiempo transcurrido: " << DURACION_PARTIDA - (uint16_t)tiempo.count() << " segundos" << std::endl;
    evento.tiempo_restante = DURACION_PARTIDA - (uint16_t)tiempo.count();

    for(const auto &par : map_personajes){
        EventoPersonaje evento_personaje;
        
        evento_personaje.id_jugador = par.first;
        evento_personaje.posicion_x = par.second->obtener_posicionX();
        evento_personaje.posicion_y = par.second->obtener_posicionY();
        evento_personaje.vida = par.second->obtener_vida();
        evento_personaje.id_personaje = par.second->obtener_personaje();
        evento_personaje.esta_quieto = par.second->obtener_movimiento();
        evento_personaje.esta_corriendo = par.second->obtener_corriendo();
        evento_personaje.usando_habilidad = par.second->obtener_habilidad();
        evento_personaje.esta_saltando = par.second->obtener_saltando();
        evento_personaje.esta_disparando = par.second->obtener_disparando();

        evento.eventos_personaje.emplace_back(evento_personaje);
    }

    for(Bala bala : controlador_balas.obtener_balas()){
        EventoBala evento_bala;
        evento_bala.id_jugador = bala.obtener_id_jugador();
        evento_bala.id_bala = bala.obtener_id_bala();
        evento_bala.posicion_x = bala.obtener_posicionX();
        evento_bala.posicion_y = bala.obtener_posicionY();
        evento_bala.impacto = bala.obtener_impacto();
        evento_bala.tipo_bala = bala.obtener_codigo();
       

        evento.eventos_bala.emplace_back(evento_bala);
    }


    return evento;
}


LogicaPartida::~LogicaPartida(){
    for(auto &par : map_personajes){
        delete par.second;
    }
}