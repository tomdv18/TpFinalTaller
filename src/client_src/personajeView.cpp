#include "personajeView.h"

#define WIDTH 640
#define HEIGHT 480
#define PERSONAJE_HEIGHT 50
#define PERSONAJE_WIDTH 50



PersonajeView::PersonajeView(uint32_t id_jugador, int x, int y) : id_jugador(id_jugador),ultimas_posiciones_x(), posicion_x(x), posicion_y(y), width(PERSONAJE_WIDTH), height(PERSONAJE_HEIGHT), 
texturas(nullptr), 
facingLeft(false), isMoving(false), isRunning(false), isJumping(false), isShooting(false), stopShooting(false) {
    animaciones.insert(std::make_pair(CAMINANDO, Animacion()));
    animaciones.insert(std::make_pair(CORRIENDO, Animacion()));
    animaciones.insert(std::make_pair(QUIETO_CLIENTE, Animacion()));
    animaciones.insert(std::make_pair(SALTANDO, Animacion()));
    animaciones.insert(std::make_pair(DISPARO_QUIETO, Animacion()));
    animaciones.insert(std::make_pair(DEJA_DISPARO_QUIETO, Animacion()));
    ultimas_posiciones_x[0] = 0;
    ultimas_posiciones_x[1] = 0;
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
    this->animaciones.at(DISPARO_QUIETO).set_texturas(&texturas->at(DISPARO_QUIETO));
    this->animaciones.at(DEJA_DISPARO_QUIETO).set_texturas(&texturas->at(DEJA_DISPARO_QUIETO));
}

void PersonajeView::actualizar_vista_personaje(EventoPersonaje const &evento, float dt) {
    
    this->isMoving = bool (!evento.esta_quieto);
    this->isRunning = bool (evento.esta_corriendo);
    this->isJumping = bool (evento.esta_saltando);
    
    this->ultimas_posiciones_x[0] = evento.posicion_x; //Ante ultima posicion
    
    if(isMoving) {
        this->ultimas_posiciones_x[1] = posicion_x; //Posicion mas actualizada
    }
    

    stopShooting = false;
    if(this->isShooting != evento.esta_disparando && !evento.esta_disparando) {
        stopShooting = true;
    }
    

    this->isShooting = bool (evento.esta_disparando);


    facingLeft = false;
    
    if(ultimas_posiciones_x[1] > ultimas_posiciones_x[0] && ultimas_posiciones_x[0] != ultimas_posiciones_x[1]) {
        facingLeft = true;
    }
    else if(posicion_x > evento.posicion_x) {
        facingLeft = true;
    }

    if(isJumping) {
        this->animaciones.at(SALTANDO).actualizar(dt);
        this->posicion_y = evento.posicion_y;
    }

    if(this->isMoving && !this->isRunning) {
        this->animaciones.at(CAMINANDO).actualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if (this->isMoving && this->isRunning){
        this->animaciones.at(CORRIENDO).actualizar(dt);
        this->posicion_x = evento.posicion_x;
        this->posicion_y = evento.posicion_y;
    } else if(!this->isMoving && !this->isShooting) {
        this->animaciones.at(QUIETO_CLIENTE).actualizar(dt);
    } else if(!this->isMoving && this->isShooting) {
        this->animaciones.at(DISPARO_QUIETO).actualizar(dt);
    }

    if(stopShooting) {
        this->animaciones.at(DEJA_DISPARO_QUIETO).actualizar(50000000);
        //Funciona pero ocurre muy rapido
    }
    
    

    std::cout << "EL STOP :" << stopShooting << std::endl;
      
}

void PersonajeView::renderizar_personaje(std::unique_ptr<SDL2pp::Renderer> &render, int cam_x, int cam_y) {
    
    SDL2pp::Rect personaje(posicion_x-cam_x, posicion_y-cam_y, width, height);
    
    if(isMoving && !isRunning && !isJumping) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CAMINANDO).animar(*render, personaje, flip);
    } else if(isMoving && isRunning){
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(CORRIENDO).animar(*render, personaje, flip);
    } else if(!this->isMoving && !this->isShooting) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(QUIETO_CLIENTE).animar(*render, personaje, flip);
    } else if(!this->isMoving && this->isShooting) {
        SDL_RendererFlip flip = facingLeft ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        animaciones.at(DISPARO_QUIETO).animar(*render, personaje, flip);

    }
    
    if(isJumping) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(SALTANDO).animar(*render, personaje, flip);
    }

    if(stopShooting && !isMoving) {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        animaciones.at(DEJA_DISPARO_QUIETO).animar(*render, personaje, flip);
    }
    
    
}

PersonajeView::~PersonajeView() {

}