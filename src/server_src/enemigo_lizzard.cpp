#include "enemigo_lizzard.h"


Lizzard::Lizzard(uint32_t id_enemigo) : Enemigo(id_enemigo){
    std::cout << "LIZZARD CREADO" << std::endl;
}
 
uint8_t Lizzard::obtener_personaje(){
    return 0X00; //
}


void Lizzard::mover_derecha(){
    Enemigo::mover_derecha();
}

void Lizzard::mover_izquierda(){
    Enemigo::mover_izquierda();
}

void Lizzard::actualizar_posicion(std::chrono::duration<double> tiempo_transcurrido){
    Enemigo::actualizar_posicion(tiempo_transcurrido);
}
