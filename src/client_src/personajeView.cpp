#include "personajeView.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50



PersonajeView::PersonajeView(uint32_t id_jugador) : id_jugador(id_jugador), posicion_x(0), posicion_y(0), width(50), height(50), texturas(nullptr), 
facingLeft(false), isMoving(false), isRunning(false), isJumping(false) {
    animaciones.insert(std::make_pair(CAMINANDO, Animacion()));
    animaciones.insert(std::make_pair(CORRIENDO, Animacion()));
    animaciones.insert(std::make_pair(QUIETO_CLIENTE, Animacion()));
    animaciones.insert(std::make_pair(SALTANDO, Animacion()));
}
//Hay que sacar del consturctor los tamaños de los frames.


SDL2pp::Texture PersonajeView::crear_surface_y_texturas(std::string const &path_sprites, SDL2pp::Renderer *render) {
    SDL2pp::Surface surface(path_sprites);
    surface.SetColorKey(true, SDL_MapRGB(surface.Get()->format, 44, 102, 150));
    SDL2pp::Texture textures(*render, std::move(surface));

    return std::move(textures);
}

void PersonajeView::referenciar_animaciones() {

    this->animaciones.at(CAMINANDO).set_texturas(&texturas->at(CAMINANDO));
    this->animaciones.at(CORRIENDO).set_texturas(&texturas->at(CORRIENDO));
    this->animaciones.at(QUIETO_CLIENTE).set_texturas(&texturas->at(QUIETO_CLIENTE));
    this->animaciones.at(SALTANDO).set_texturas(&texturas->at(SALTANDO));
}

void PersonajeView::actualizar_vista_personaje(EventoPersonaje const &evento, float dt) {
    
    this->isMoving = bool (!evento.esta_quieto);
    this->isRunning = bool (evento.esta_corriendo);
    this->isJumping = bool (evento.esta_saltando);

    //std::cout << "EL personaje tine id: " << evento.id_personaje << std::endl;
    
    facingLeft = false;
    if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    if(isJumping) {
        this->animaciones.at(SALTANDO);
        this->posicion_y = evento.posicion_y;
        this->posicion_x = evento.posicion_x;
    }

    if(this->isMoving && !this->isRunning && !this->isJumping) {
        this->animaciones.at(CAMINANDO).acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if (this->isMoving && this->isRunning){
        this->animaciones.at(CORRIENDO).acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if(!this->isMoving) {
        this->animaciones.at(QUIETO_CLIENTE).acualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    }
      
}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render) {
    
    SDL2pp::Rect personaje(posicion_x, posicion_y, width, height);
    
    if(isMoving && !isRunning && !isJumping) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CAMINANDO).animar(*render, personaje, flip);
    } else if(isMoving && isRunning){
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CORRIENDO).animar(*render, personaje, flip);
    } else if(!isMoving) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(QUIETO_CLIENTE).animar(*render, personaje, flip);
    }
    
    if(isJumping) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(SALTANDO).animar(*render, personaje, flip);
    }
    
    
}

PersonajeView::~PersonajeView() {

}