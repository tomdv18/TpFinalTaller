#include "interfaz.h"

#define ICONO_WIDHT 30
#define ICONO_HEIGHT 24

Interfaz::Interfaz(SDL2pp::Renderer &render, int ancho, int alto, uint32_t id_jugador):
ancho_ventana(ancho), 
alto_ventana(alto), 
rect(),
sdl_ttf(),
font("../src/client_src/Images/Jazz-Jackrabbit-2.ttf", 24), 
id_jugador(id_jugador), 
texto(),
tiempo(0),
puntos(0)
{
                
        SDL2pp::Surface vida("../src/client_src/Images/vida.png");
        vida.SetColorKey(true, SDL_MapRGB(vida.Get()->format, 0, 128, 255));

        SDL2pp::Surface bala_tipo_1("../src/client_src/Images/bala_tipo_1.png");
        bala_tipo_1.SetColorKey(true, SDL_MapRGB(bala_tipo_1.Get()->format, 0, 128, 255));

        SDL2pp::Surface bala_tipo_2("../src/client_src/Images/bala_tipo_2.png");
        bala_tipo_2.SetColorKey(true, SDL_MapRGB(bala_tipo_2.Get()->format, 0, 128, 255));

        SDL2pp::Surface bala_tipo_3("../src/client_src/Images/bala_tipo_3.png");
        bala_tipo_3.SetColorKey(true, SDL_MapRGB(bala_tipo_3.Get()->format, 0, 128, 255));

        texturas["vida"] = new SDL2pp::Texture(render, vida);
        texturas["bala_tipo_1"] = new SDL2pp::Texture(render, bala_tipo_1);
        texturas["bala_tipo_2"] = new SDL2pp::Texture(render, bala_tipo_2);
        texturas["bala_tipo_3"] = new SDL2pp::Texture(render, bala_tipo_3);
}


void Interfaz::mostrar_vida() {}

void Interfaz::definir_puntaje(uint32_t puntaje) {
    this->puntos = puntaje;
}

void Interfaz::mostrar_municiones() {}

void Interfaz::mostrar_arma_seleccionada() {}

void Interfaz::definir_tiempo(uint16_t tiempo) {
    this->tiempo = tiempo;
}

void Interfaz::mostrar_top_3(const std::map<uint32_t, std::unique_ptr<PersonajeView>>& personajesViews) {

}

void Interfaz::mostrar_tablero_final() {}

void Interfaz::mostrar_hud(SDL2pp::Renderer &render, std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews) {
    auto it = personajesViews.find(id_jugador);
    if (it == personajesViews.end()) {
        return;
    }
    // Muestro vida
    PersonajeView &personajeViewPtr = *(it->second);
    uint8_t vida = personajeViewPtr.obtener_vida();
    std::string texto = std::to_string(vida);
    rect.x = (0);
    rect.y = (alto_ventana-ICONO_HEIGHT);
    rect.w = (ICONO_WIDHT);
    rect.h = (ICONO_HEIGHT);
    render.Copy(* texturas["vida"], SDL2pp::NullOpt, rect);

    
    SDL2pp::Surface surface_texto = font.RenderText_Solid(texto, SDL_Color{0, 0, 0, 0}); // Color negro
    SDL2pp::Texture texto_borde(render, surface_texto);
    render.Copy(texto_borde, SDL2pp::NullOpt, SDL2pp::Rect(ICONO_WIDHT+5, alto_ventana-surface_texto.GetHeight()-5, ICONO_WIDHT+10, ICONO_HEIGHT+10));

    
    // Muestro tiempo
    texto = std::to_string(tiempo);
    SDL_Color color = {0, 0, 0, 0};
    if (this->tiempo <= 30) { // Ver como terminar el juego...
        color = {255, 0, 0, 0};
    }
    surface_texto = font.RenderText_Solid(texto, color);
    texto_borde = SDL2pp::Texture(render, surface_texto);
    render.Copy(texto_borde, SDL2pp::NullOpt, SDL2pp::Rect(ancho_ventana/2.0, 0, 50, 50));

    // Muestro puntaje del jugador
    color = {0, 0, 0, 0};
    texto = "x" + std::to_string(personajeViewPtr.obtener_puntos());
    surface_texto = font.RenderText_Solid(texto, color);
    texto_borde = SDL2pp::Texture(render, surface_texto);
    render.Copy(texto_borde, SDL2pp::NullOpt, SDL2pp::Rect(0, 0, 50, 50));

    // Muestro los mejores 3 puntajes de los jugadores
    
    // Ver como rellenar el texto de blanco, asi se ve mejor...


}

Interfaz::~Interfaz() {

}
