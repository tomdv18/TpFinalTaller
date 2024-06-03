#ifndef ANIMACION_H_
#define ANIMACION_H_

#include <SDL2pp/SDL2pp.hh>

class Animacion {

   private:
    
    SDL2pp::Texture &&textura;
    int frame_actual;
    int cantidad_frames;
    int size_frame;
    float elapsed;

   public:

    explicit Animacion(SDL2pp::Texture &&texturam, int size_frame);

    ~Animacion();

    void acualizar(float dt);

    void animar(SDL2pp::Renderer &render, SDL2pp::Rect dest, SDL_RendererFlip &flipType);




};

#endif //ANIMACION_H_