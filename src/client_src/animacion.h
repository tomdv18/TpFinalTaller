#ifndef ANIMACION_H_
#define ANIMACION_H_
#define FRAME_RATE 40000


#include <SDL2pp/SDL2pp.hh>

class Animacion {

   private:
    
    SDL2pp::Texture *texturas;
    int frame_actual;
    int cantidad_frames;
    float size_frame;
    float elapsed;

   public:

    explicit Animacion();

    void set_size_frame(float size_frame);

    void set_texturas(SDL2pp::Texture* texturas);

    ~Animacion();

    void actualizar(float dt);

    void animar(SDL2pp::Renderer &render, SDL2pp::Rect dest, SDL_RendererFlip &flipType);




};

#endif //ANIMACION_H_