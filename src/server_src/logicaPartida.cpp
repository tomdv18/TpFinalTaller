#include "logicaPartida.h"

#define DURACION_PARTIDA 120.0f

LogicaPartida::LogicaPartida() : fabrica_objetos(){

    //map_objetos_solidos[1] = new Solido(1, 0, 550, 1, 5000, 100); //Limite del mapa abajo

    map_objetos_solidos[2] = new Solido(2, 100, 300, 1, 5000, 25); //Piso grande

    map_objetos_solidos[3] = new Solido(3, 75, 0, 1, 25, 5000); //X pared izq

    map_objetos_solidos[4] = new Solido(4, 280, 225, 1, 150, 25);  //Piso chiquito

    map_objetos_solidos[5] = new Solido(5, 0, 0, 1, 5000, 50);   //Limite del mapa arriba

    map_objetos_solidos[6] = new Solido(6, 590, 150, 1, 25, 5000); //X pared derecha


/*

    piso:
  - x: 100
    y: 150
  - x: 260
    y: 150
  - x: 420
    y: 150
  - x: 280
    y: 70
pared:
  - x: 100
    y: 150
  - x: 596
    y: 150
*/

    //Enemigo necesita
    /*

    posicion en X
    posicion en Y

    
    */

   /*

    LEER YAML DEL MAPA INICIALIZAR TODAS ESTAS COSAS
    SETEAR ZONAS DE RESPAWN PARA JUGADOR
   
   */
  
    map_enemigos[0] = new Rat(0);  // DESCOMENTAR ESTA LINEA PARA EL MUESTREO DE ENEMIGOS

    map_objetos_comunes[0] = fabrica_objetos.crear_objeto(ZANAHORIA,250,250,false);
}


void LogicaPartida::ejecutar(Accion accion,
                             std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {

    

    switch (accion.codigo) {
        case DERECHA:
            mover_derecha(accion.id_jugador, tiempo);
            break;
        case IZQUIERDA:
            mover_izquierda(accion.id_jugador, tiempo);
            break;
        case ARRIBA:
            mover_arriba(accion.id_jugador, tiempo);
            break;
        case ABAJO:
            // mover_abajo(accion.id_jugador);
            break;
        case CORRER_RAPIDO:
            mover_correr_rapido(accion.id_jugador, tiempo);
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

void LogicaPartida::mover_derecha(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->mover_derecha(tiempo_transcurrido);
    }
}

void LogicaPartida::mover_izquierda(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
     std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->mover_izquierda(tiempo_transcurrido);
    }
}

void LogicaPartida::mover_arriba(
        uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;

    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->mover_arriba(tiempo_transcurrido);
    }
}

void LogicaPartida::mover_abajo(uint32_t id_jugador) {
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->mover_abajo();
    }
}

void LogicaPartida::mover_quieto(uint32_t id_jugador) {
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->quedarse_quieto();
    }
}

void LogicaPartida::mover_correr_rapido(uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->correr_rapido(tiempo_transcurrido);
    }
}

void LogicaPartida::mover_correr(uint32_t id_jugador) {
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->correr();
    }
}

void LogicaPartida::disparar(uint32_t id_jugador,
                             std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;

    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        uint8_t codigo_bala = personaje->disparar(tiempo_transcurrido);
        if (codigo_bala != NINGUNO) {
            int velocidad = personaje->mirando_izquierda() ? -1 : 1;
            int salida_x = personaje->mirando_izquierda() ? personaje->obtener_posicionX() + PERSONAJE_WIDTH/2 : personaje->obtener_posicionX();
            controlador_balas.agregar_bala(codigo_bala, id_jugador, salida_x,
                                           personaje->obtener_posicionY() + PERSONAJE_HEIGHT / 4,
                                           velocidad);
        }
    }
}

void LogicaPartida::dejar_disparar(uint32_t id_jugador) {
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->dejar_disparar();
    }
}

void LogicaPartida::usar_habilidad(
        uint32_t id_jugador, std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->usar_habilidad(tiempo_transcurrido);
    }
}


void LogicaPartida::abandonar_partida(uint32_t id_jugador) {
    auto it = map_personajes.find(id_jugador);

    if (it != map_personajes.end()) {
        delete it->second;

        map_personajes.erase(it);
    }
}


void LogicaPartida::agregar_personaje(Accion accion) {
    // Personaje *personaje;
    switch (accion.codigo) {
        case JAZZ: {
            std::cout << "CREAR PERSONAJE JAZZ" << std::endl;
            // personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if (map_personajes[accion.id_jugador] == nullptr) {
                map_personajes[accion.id_jugador] = new Jazz(accion.id_jugador);
            }
            break;
        }
        case SPAZ: {
            std::cout << "CREAR PERSONAJE SPAZ" << std::endl;
            // personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if (map_personajes[accion.id_jugador] == nullptr) {
                map_personajes[accion.id_jugador] = new Spaz(accion.id_jugador);
            }
            break;
        }
        case LORI: {
            std::cout << "CREAR PERSONAJE LORI" << std::endl;
            // personaje = new Personaje(accion.id_jugador);    ///new Jazz();
            if (map_personajes[accion.id_jugador] == nullptr) {
                map_personajes[accion.id_jugador] = new Lori(accion.id_jugador);
            }
            break;
        }

        default:
            break;
    }
}

void LogicaPartida::actualizar_partida(
        std::chrono::time_point<std::chrono::high_resolution_clock> tiempo) {
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo_transcurrido = actual - tiempo;


    for (const auto& par_personaje: map_personajes) {
        par_personaje.second->actualizar_posicion(tiempo_transcurrido, map_objetos_solidos, map_objetos_comunes);
    }
    
    
    for (const auto& par: map_enemigos) {
        par.second->actualizar_posicion(tiempo_transcurrido);

        Rectangulo rect_enemigo = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                    par.second->obtener_ancho(), par.second->obtener_alto()};
        if(par.second->esta_vivo()){
            for (const auto& par: map_personajes) {
                    Rectangulo rect_personaje = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                                    par.second->obtener_ancho(), par.second->obtener_alto()};
                    if(rect_personaje.hay_colision(rect_enemigo)){
                        if(!par.second->esta_muerto()){
                                // Si esta muerto lo ignoro
                            if(par.second->obtener_habilidad()){
                                // El personaje le hace daño a el
                            } else{
                                par.second->recibir_golpe(50,tiempo_transcurrido); 
                            } 
                        }
                    }
            }
        }            
    }

    auto& balas = controlador_balas.obtener_balas();
    auto it = balas.begin();

    while (it != balas.end()) {
        it->actualizar_posicion();

        Rectangulo rect_bala = {it->obtener_posicionX(), it->obtener_posicionY(),
                                it->obtener_ancho(), it->obtener_largo()};


        // Calcular primero colision con enemigos
        
        
        for (const auto& par: map_enemigos) {
            Rectangulo rect_enemigo = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                    par.second->obtener_ancho(), par.second->obtener_alto()};
            if(rect_enemigo.hay_colision(rect_bala)){
                if(par.second->esta_vivo()){
                    par.second->recibir_golpe(200,tiempo_transcurrido);  // Por ahora hardcodeado recibe 10 de daño
                    it->impactar();
                    break;
                }
            }
        }
            

        if(!it->obtener_impacto()){
            for (const auto& par: map_personajes) {
                Rectangulo rect_personaje = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                                par.second->obtener_ancho(), par.second->obtener_alto()};
                if(rect_personaje.hay_colision(rect_bala)){
                    if(!par.second->esta_muerto()){
                        par.second->recibir_golpe(100,tiempo_transcurrido);  // Por ahora hardcodeado recibe 10 de daño
                        it->impactar();
                        break;
                    }
                }
            }
        }

        // Colision con objetos SOLIDOS
        if(!it->obtener_impacto()){
            for (const auto& par: map_objetos_solidos) {
                Rectangulo rect_obj = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                                par.second->obtener_ancho(), par.second->obtener_alto()};
                if (rect_obj.hay_colision(rect_bala)) {
                    it->impactar();
                    break;
                }
            }
        }

        if (it->obtener_impacto() || it->obtener_posicionX() >= WIDTH) {
            controlador_balas.remover_bala(it->obtener_id_bala());
        } else {
            ++it;
        }
    }
    
}

Evento LogicaPartida::obtener_snapshot(
        std::chrono::time_point<std::chrono::high_resolution_clock> start) {
    Evento evento;
    evento.eventos_personaje.clear();
    std::chrono::time_point<std::chrono::high_resolution_clock> actual =
            std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempo = actual - start;
    evento.tiempo_restante = DURACION_PARTIDA - (uint16_t)tiempo.count();

    for (const auto& par: map_personajes) {
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
        evento_personaje.codigo_estado = par.second->obtener_estado();
        evento_personaje.mirando_izquierda = par.second->mirando_izquierda();
        evento_personaje.esta_intoxicado = par.second->obtener_intoxicado();

        evento.eventos_personaje.emplace_back(evento_personaje);
    }

    for (const auto& par: map_objetos_comunes) {
        EventoObjeto evento_objeto;
        evento_objeto.id_objeto = par.second->obtener_id();
        evento_objeto.posicion_x = par.second->obtener_posicionX();
        evento_objeto.posicion_y = par.second->obtener_posicionY();
        evento_objeto.mostrandose = par.second->obtener_mostrar();
        evento_objeto.codigo_objeto = par.second->obtener_objeto();

        evento.eventos_objeto.emplace_back(evento_objeto);
    }


    for (Bala bala: controlador_balas.obtener_balas()) {
        EventoBala evento_bala;
        evento_bala.id_jugador = bala.obtener_id_jugador();
        evento_bala.id_bala = bala.obtener_id_bala();
        evento_bala.posicion_x = bala.obtener_posicionX();
        evento_bala.posicion_y = bala.obtener_posicionY();
        evento_bala.impacto = bala.obtener_impacto();
        evento_bala.tipo_bala = bala.obtener_codigo();

        std::cout << "IMPACTO " << (int)evento_bala.impacto << std::endl;

        evento.eventos_bala.emplace_back(evento_bala);
    }

    for (const auto& par: map_enemigos) {
        EventoEnemigo eventos_enem;
        eventos_enem.id_enemigo = par.first;
        eventos_enem.posicion_x = par.second->obtener_posicionX();
        eventos_enem.posicion_y = par.second->obtener_posicionY();
        eventos_enem.id_personaje = par.second->obtener_personaje();
        eventos_enem.vida = par.second->obtener_vida();
        eventos_enem.esta_vivo = par.second->esta_vivo();
        eventos_enem.mirando_izquierda = par.second->mirando_izquierda();

        evento.eventos_enemigos.emplace_back(eventos_enem);
    }


    return evento;
}


LogicaPartida::~LogicaPartida() {
    for (auto& par: map_personajes) {
        delete par.second;
    }

    for (auto& par: map_objetos_solidos) {
        delete par.second;
    }

    /*
    for (auto& par: map_objetos_comunes) {
        delete par.second;
    }
    */
    for (auto& par: map_enemigos) {
        delete par.second;
    }
}
