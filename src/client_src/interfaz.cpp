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
texto()
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

void Interfaz::mostrar_puntaje() {}

void Interfaz::mostrar_municiones() {}

void Interfaz::mostrar_arma_seleccionada() {}

void Interfaz::mostrar_tiempo() {}

void Interfaz::mostrar_top_3() {}

void Interfaz::mostrar_tablero_final() {}

void Interfaz::mostrar_hud(SDL2pp::Renderer &render, std::map<uint32_t, std::unique_ptr<PersonajeView>> &personajesViews) {
    auto it = personajesViews.find(id_jugador);
    if (it == personajesViews.end()) {
        return;
    }
    // Enfoco la camara al jugador.
    PersonajeView &personajeViewPtr = *(it->second);
    uint8_t vida = personajeViewPtr.obtener_vida();
    std::string texto = std::to_string(vida);
    rect.x = (0);
    rect.y = (alto_ventana-ICONO_HEIGHT);
    rect.w = (ICONO_WIDHT);
    rect.h = (ICONO_HEIGHT);
    render.Copy(* texturas["vida"], SDL2pp::NullOpt, rect);
    SDL2pp::Surface vida_texto = font.RenderText_Solid(texto, SDL_Color{0, 0, 0, 0}); // Color negro
    SDL2pp::Texture texto_textura(render, vida_texto);
    render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(ICONO_WIDHT+5, alto_ventana-vida_texto.GetHeight()-5, ICONO_WIDHT+10, ICONO_HEIGHT+10));
     
}

Interfaz::~Interfaz() {

}
