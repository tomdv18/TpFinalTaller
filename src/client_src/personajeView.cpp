#include "personajeView.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50

PersonajeView::PersonajeView() : posicion_x(0), posicion_y(0), width(50), height(50)  {}

void PersonajeView::actualizar_vista_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int const &posicion_x, int const &posicion_y) {
    
    
    SDL2pp::Rect personaje(posicion_x, posicion_y, width, height);
    render->SetDrawColor(0xff, 0xff, 0xff, 0xff);
    render->Clear();

    personaje.x = posicion_x;
    personaje.y = posicion_y;

    render->SetDrawColor(0xff, 0x00, 0xff, 0xff);

    // Dibujo el rectángulo
    render->FillRect(personaje);



}

