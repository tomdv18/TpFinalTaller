#ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje {

    private:

    int coordenada_x;
    int coordenada_y;

    public: 

    Personaje();

    int get_coordenada_x();

    int get_coordenada_y();

    void set_coordenada_x(int coordenada_x);

    void set_coordenada_y(int coordenada_y);

};

#endif