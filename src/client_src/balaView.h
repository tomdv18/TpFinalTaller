#ifndef BALAVIEW_H_
#define BALAVIEW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2pp/SDL2pp.hh>
#include <iostream>
#include <map>
#include "../common_src/evento.h"
#include "animacion.h"

#define BALA_HEIGHT 50
#define BALA_WIDTH 50

class BalaView{
private:
    std::map<std::string, std::shared_ptr<SDL2pp::Texture>> texturas;
    int posicion_x;
    int posicion_y;
    int width;
    int height;
    Animacion animacion_bala;

    bool facingLeft;

public:
    BalaView(std::map<std::string, std::shared_ptr<SDL2pp::Texture>> texturas, uint32_t pos_x, uint32_t pos_y);


    void actualizar(EventoBala const &evento,float dt);

    void renderizar(SDL2pp::Renderer &render);


};















#endif