#ifndef ANIMACION_H_
#define ANIMACION_H_

#include <SDL2pp/SDL2pp.hh>
#include <memory>
#define FRAME_RATE 40000

class Animacion {

   protected:
    
    std::unique_ptr<SDL2pp::Texture> texturas;
    int frame_actual;
    int cantidad_frames;
    float size_frame;
    float elapsed;

   public:

    explicit Animacion();

    virtual SDL2pp::Texture crear_surface_y_texturas(std::string const &path_sprites, SDL2pp::Renderer *render);

    virtual void crear_texturas(SDL2pp::Renderer *render) = 0;

    virtual ~Animacion();

    virtual void acualizar(float dt);

    virtual void animar(SDL2pp::Renderer &render, SDL2pp::Rect dest, SDL_RendererFlip &flipType);




};

#endif //ANIMACION_H_