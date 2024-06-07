#ifndef ESTADO_HERIDO_H_
#define ESTADO_HERIDO_H_


#include "estado.h"

#define TIEMPO_HERIDO 2

class EstadoHerido : public Estado {
private:
   bool tiempo_impacto;

   bool cambiar_animacion;

public:

    EstadoHerido(double tiempo_impacto);

    void manejarEstado(uint8_t codigo_estado, double tiempo) override;

    void actualizar(double tiempo) override;

};


#endif