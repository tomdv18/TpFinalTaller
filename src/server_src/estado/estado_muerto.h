#ifndef ESTADO_MUERTO_H_
#define ESTADO_MUERTO_H_


#include "estado.h"

#define TIEMPO_MUERTO 5

class EstadoMuerto : public Estado {
private:
   bool tiempo_muerte;

   bool cambiar_estado;

public:

    EstadoMuerto(double tiempo_muerte);

    void manejarEstado(uint8_t codigo_estado, double tiempo) override;

    void actualizar(double tiempo) override;

};


#endif