#include "logicaPartida.h"

#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

#define CONFIG Configuracion::config()

LogicaPartida::LogicaPartida() : fabrica_objetos(), fabrica_enemigos(), mapa("../src/mapas/mapa.yaml"){

    //map_objetos_solidos[1] = new Solido(1, 0, 750, 1, 5000, 100); //Limite del mapa abajo
    
    /* MAPA 1
    map_objetos_solidos[2] = new Solido(2, 100, 300, 1, 5000, 25); //Piso grande

    map_objetos_solidos[3] = new Solido(3, 75, 0, 1, 25, 5000); //X pared izq

    map_objetos_solidos[4] = new Solido(4, 280, 225, 1, 150, 25);  //Piso chiquito

    map_objetos_solidos[5] = new Solido(5, 0, 0, 1, 5000, 50);   //Limite del mapa arriba

    map_objetos_solidos[6] = new Solido(6, 590, 150, 1, 10, 5000); //X pared derecha
    
    */

   // MAPA 2
    YAML::Node mapNode = YAML::LoadFile("../src/mapas/mapa2.yaml");
        int i = 0;
        for (const auto& objNode : mapNode["solids"]) {
            map_objetos_solidos[i] = new Solido(i,objNode["x"].as<uint32_t>(),objNode["y"].as<uint32_t>(),1,objNode["width"].as<uint32_t>(),objNode["height"].as<uint32_t>());
            i++;
        }


        i = 0;
        for (const auto& monedaNode : mapNode["moneda"]) {
            map_objetos_comunes[i] = fabrica_objetos.crear_objeto(MONEDA,monedaNode["x"].as<uint32_t>(),monedaNode["y"].as<uint32_t>(),monedaNode["veneno"].as<bool>());
            i++;
        }


        for (const auto& gemaNode : mapNode["gema"]) {
            map_objetos_comunes[i] = fabrica_objetos.crear_objeto(GEMA,gemaNode["x"].as<uint32_t>(),gemaNode["y"].as<uint32_t>(),gemaNode["veneno"].as<bool>());
            i++;
        }


        for (const auto& zanahoriaNode : mapNode["zanahoria"]) {
            map_objetos_comunes[i] = fabrica_objetos.crear_objeto(ZANAHORIA,zanahoriaNode["x"].as<uint32_t>(), zanahoriaNode["y"].as<uint32_t>(),zanahoriaNode["veneno"].as<bool>());
            i++;
        }

    /*
        for (const auto& coheteRapidoNode : mapNode["bala_veloz"]) {
            map_objetos_comunes[i] = fabrica_objetos.crear_objeto(BALA_VELOZ,coheteRapidoNode["x"].as<uint32_t>(), coheteRapidoNode["y"].as<uint32_t>(),coheteRapidoNode["veneno"].as<bool>());
            i++;
        }
        */


        // Carga de enemigos
        i = 0;
        
        for (const auto& lizzardNode : mapNode["lizzard"]) {
            map_enemigos[i] = fabrica_enemigos.crear_enemigo(i,LIZZARD,lizzardNode["x"].as<uint32_t>(), lizzardNode["y"].as<uint32_t>());
            i++;
        }
        

        map_objetos_comunes[20] = fabrica_objetos.crear_objeto(BALA_VELOZ,700,600,false);
        map_objetos_comunes[21] = fabrica_objetos.crear_objeto(BALA_VELOZ,700,500,false);

        map_objetos_comunes[22] = fabrica_objetos.crear_objeto(COHETE_RAPIDO,100,600,false);
        map_objetos_comunes[23] = fabrica_objetos.crear_objeto(COHETE_RAPIDO,100,500,false);

        /*
        }



        // Carga de enemigos
        i = 1;
        for (const auto& lizzardNode : mapNode["lizzard"]) {
            std::shared_ptr<Enemigo> lizzard = fabrica_enemigos.crear_enemigo(
                i,
                LIZZARD,
                lizzardNode["x"].as<uint32_t>(),
                lizzardNode["y"].as<uint32_t>()
            );
            entidades.push_back(lizzard);
            map_enemigos[i] = lizzard;
            i++;
        }

        */
    
  

    //map_enemigos[0] = new Lizzard(0);  // DESCOMENTAR ESTA LINEA PARA EL MUESTREO DE ENEMIGOS

    //map_objetos_comunes[0] = fabrica_objetos.crear_objeto(ZANAHORIA,400,275,true);
    //map_objetos_comunes[1] = fabrica_objetos.crear_objeto(GEMA,475,275,false);
    //map_objetos_comunes[2] = fabrica_objetos.crear_objeto(MONEDA,475,200,false);
    //map_objetos_comunes[3] = fabrica_objetos.crear_objeto(BALA_VELOZ,525,275,false);

  
    
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
            break;
        case QUIETO:
            mover_quieto(accion.id_jugador);
            break;
        case DISPARAR:
            disparar(accion.id_jugador, tiempo);
            //std::cout << "DISPARANDO" << std::endl;
            break;
        case DEJAR_DISPARAR:
            dejar_disparar(accion.id_jugador);
            //std::cout << "DEJO DE DISPARAR" << std::endl;
            break;
        case ESPECIAL:
            usar_habilidad(accion.id_jugador, tiempo);
            break;
        case CAMBIAR_ARMA:
            cambiar_bala(accion.id_jugador);
        case JAZZ:
            agregar_personaje(accion);
            break;
        case SPAZ:
            agregar_personaje(accion);
            break;
        case LORI:
            agregar_personaje(accion);
            break;
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
            uint32_t offset = personaje->mirando_izquierda() ? -CONFIG.getAnchoPersonaje()/2 : velocidad * (CONFIG.getAnchoPersonaje());
            controlador_balas.agregar_bala(codigo_bala, id_jugador, personaje->obtener_posicionX(), offset,
                                           personaje->obtener_posicionY() + CONFIG.getAnchoPersonaje() / 4,
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

void LogicaPartida::cambiar_bala(uint32_t id_jugador){
    Personaje* personaje = map_personajes[id_jugador];
    if (personaje != nullptr) {
        if(personaje->esta_muerto()) return;
        personaje->cambiar_bala_siguiente();
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
        Rectangulo rect_personaje = {par_personaje.second->obtener_posicionX(), par_personaje.second->obtener_posicionY(),
                                    par_personaje.second->obtener_ancho(), par_personaje.second->obtener_alto()};
        // Ver colision con otros personajes

        //ASDASD
        //std::cout << "CELDA ACTUAL X: " << par_personaje.second->obtener_posicionX()/ cell_size << std::endl;
        //std::cout << "CELDA ACTUAL Y: " << par_personaje.second->obtener_posicionY()/ cell_size << std::endl;

        
        for (const auto& par_otro: map_personajes) {
            Rectangulo rect_otro = {par_otro.second->obtener_posicionX(), par_otro.second->obtener_posicionY(),
                                    par_otro.second->obtener_ancho(), par_otro.second->obtener_alto()};
            if(!par_otro.second->esta_muerto() && par_otro.first != par_personaje.first){
                if(rect_personaje.hay_colision(rect_otro) && par_personaje.second->obtener_habilidad()){
                   par_personaje.second->inflingir_danio_habilidad(par_otro.second, tiempo_transcurrido);
                }
            }                       
        }
        
    }
    
    
    for (const auto& par: map_enemigos) {
        par.second->actualizar_posicion(tiempo_transcurrido);

        //ASD
        //std::cout << "CELDA ACTUAL X: " << par.second->obtener_posicionX()/ cell_size << std::endl;
        //std::cout << "CELDA ACTUAL Y: " << par.second->obtener_posicionY()/ cell_size << std::endl;

        Rectangulo rect_enemigo = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                    par.second->obtener_ancho(), par.second->obtener_alto()};
        if(par.second->esta_vivo()){
            for (const auto& par_pj: map_personajes) {
                    Rectangulo rect_personaje = {par_pj.second->obtener_posicionX(), par_pj.second->obtener_posicionY(),
                                    par_pj.second->obtener_ancho(), par_pj.second->obtener_alto()};
                    if(rect_personaje.hay_colision(rect_enemigo)){
                        if(!par_pj.second->esta_muerto()){
                                // Si esta muerto lo ignoro
                            if(par_pj.second->obtener_habilidad()){
                                // El personaje le hace daño a el
                                par.second->recibir_golpe(par_pj.second, tiempo_transcurrido);
                            } else{
                                // El personaje recibe danio
                                par_pj.second->recibir_golpe(par.second.get(),tiempo_transcurrido); 
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


        for (const auto& par: map_enemigos) {
            Rectangulo rect_enemigo = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                    par.second->obtener_ancho(), par.second->obtener_alto()};
            if(rect_enemigo.hay_colision(rect_bala)){
                if(par.second->esta_vivo()){
                    par.second->recibir_golpe(*it,tiempo_transcurrido);  // Por ahora hardcodeado recibe 10 de daño
                    if(!par.second->esta_vivo()){
                        map_personajes[it->obtener_id_jugador()]->asignar_puntos(par.second->obtener_puntos());
                    }
                    it->impactar();
                    break;
                }
            }
        }
            

        if(!it->obtener_impacto()){
            for (const auto& par: map_personajes) {
                Rectangulo rect_personaje = {par.second->obtener_posicionX(), par.second->obtener_posicionY(),
                                par.second->obtener_ancho(), par.second->obtener_alto()};
                if(rect_personaje.hay_colision(rect_bala) && it->obtener_id_jugador() != par.first){  // No se puede hacer daño solo
                    if(!par.second->esta_muerto()){
                        par.second->recibir_golpe(*it,tiempo_transcurrido);  // Por ahora hardcodeado recibe 10 de daño
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

        if (it->obtener_impacto() || it->obtener_posicionX() >= CONFIG.getAnchoPantalla()) {
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
    evento.tiempo_restante = CONFIG.getDuracionPartida() - (uint16_t)tiempo.count();

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
        evento_personaje.puntos = par.second->obtener_puntos();
        evento_personaje.bala_actual = par.second->obtener_bala_actual();
        evento_personaje.municion = par.second->obtener_municion_actual();

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

}
