#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include "accion.h"
#include "estado.h"
#include "arma.h"
#include "ataque_especial.h"
#include "coordenadas.h"
#include <map>

class Personaje {

   protected:

   int cantidad_vida;
   std::map<std::string, Accion> acciones;
   std::map<std::string, Estado> estados;
   std::map<std::string, Arma> armas;
   Ataque_especial ataque_especial;
   Coordenadas coordenadas;
   int cantidad_puntos;

   public:

   explicit Personaje(int cantidad_vida, std::map<std::string, Accion> acciones, 
   std::map<std::string, Estado> estados,std::map<std::string, Arma> armas,
   Ataque_especial ataque_especial);

   void aumentar_vida(int cantidad_vida);

   void disminuir_vida(int cantidad_vida);

   void aumenatar_puntos(int cantidad_puntos);

   void agregar_estado(Estado estado);

   void eliminar_estado(Estado estado);

   void agregar_arma(Arma arma);

   void eliminar_arma(Arma arma);

   void realizar_ataque_especial();

   void realizar_accion(Accion accion);

   void modificar_coordenadas(Coordenadas coordenadas);

   Arma get_arma(std::string nombre_arma);
};

#endif
