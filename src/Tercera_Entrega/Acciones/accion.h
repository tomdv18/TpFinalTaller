#ifndef ACCION_H_
#define ACCION_H_

class Accion {

   private:

   std::string nombre;

   public:

   void realizar();

   std::string get_nombre_accion();
};

#endif