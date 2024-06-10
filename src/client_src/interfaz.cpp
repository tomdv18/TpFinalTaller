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
puntajes()
{
                
        SDL2pp::Surface vida("../src/client_src/Images/vida.png");
        vida.SetColorKey(true, SDL_MapRGB(vida.Get()->format, 0, 128, 255));

        SDL2pp::Surface bala_tipo_3("../src/client_src/Images/bala_tipo_0.png");
        bala_tipo_3.SetColorKey(true, SDL_MapRGB(bala_tipo_3.Get()->format, 44, 102, 150));        

        SDL2pp::Surface bala_tipo_4("../src/client_src/Images/bala_tipo_1.png");
        bala_tipo_4.SetColorKey(true, SDL_MapRGB(bala_tipo_4.Get()->format, 0, 128, 255));

        SDL2pp::Surface bala_tipo_5("../src/client_src/Images/bala_tipo_2.png");
        bala_tipo_5.SetColorKey(true, SDL_MapRGB(bala_tipo_5.Get()->format, 0, 128, 255));

        SDL2pp::Surface bala_tipo_6("../src/client_src/Images/bala_tipo_3.png");
        bala_tipo_6.SetColorKey(true, SDL_MapRGB(bala_tipo_6.Get()->format, 0, 128, 255));

        texturas["vida"] = new SDL2pp::Texture(render, vida);
        texturas["bala_tipo_3"] = new SDL2pp::Texture(render, bala_tipo_3);
        texturas["bala_tipo_4"] = new SDL2pp::Texture(render, bala_tipo_4);
        texturas["bala_tipo_5"] = new SDL2pp::Texture(render, bala_tipo_5);
        texturas["bala_tipo_6"] = new SDL2pp::Texture(render, bala_tipo_6);
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

void Interfaz::mostrar_tabla_final(SDL2pp::Renderer &render) {
    size_t i = 0;
    SDL_Color color = {255, 255, 255, 255};
    for (const auto &entry : puntajes) {
        uint32_t id = entry.first;
        uint32_t puntaje = entry.second;
        std::cout << "ID: " << id << " - Puntaje: " << puntaje << std::endl;

        // Muestro puntaje del jugador
        std::string texto = std::to_string(id) + ": " + std::to_string(puntaje);
        SDL2pp::Surface surface_texto = font.RenderText_Solid(texto, color);
        SDL2pp::Texture texto_textura(render, surface_texto);
        
        // Calcular posición de renderizado
        int x = ancho_ventana/2.0; // Ajustar para que no se salga de la ventana
        int y = i * 50;
        render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(x, y, 100, 30));
        i++;
    }
}

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
    SDL2pp::Surface surface_texto = font.RenderText_Solid(texto, SDL_Color{255, 255, 255, 255}); // Color negro
    SDL2pp::Texture texto_textura(render, surface_texto);
    render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(ICONO_WIDHT+5, alto_ventana-surface_texto.GetHeight()-5, ICONO_WIDHT+10, ICONO_HEIGHT+10));

    // Muestro tiempo

    texto = std::to_string(tiempo);
    SDL_Color color = {255, 255, 255, 255};

    if (this->tiempo <= 30) { // Ver como terminar el juego...
        color = {255, 0, 0, 0};
    }
    surface_texto = font.RenderText_Solid(texto, color);
    texto_textura = SDL2pp::Texture(render, surface_texto);
    render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(ancho_ventana/2.0, 0, 50, 50));

    
    // Muestro puntaje del jugador
    color = {255, 255, 255, 255};
    texto = "x" + std::to_string(personajeViewPtr.obtener_puntos());
    surface_texto = font.RenderText_Solid(texto, color);
    texto_textura = SDL2pp::Texture(render, surface_texto);
    render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(0, 0, 50, 50));

    // Muestro los mejores 3 puntajes de los jugadores
        // Vector para almacenar los puntajes
    puntajes.clear();
    
        // Recorrer el mapa y extraer los puntajes
    for (const auto &entry : personajesViews) {
        uint32_t id = entry.first;
        uint32_t puntaje = entry.second->obtener_puntos();
        puntajes.emplace_back(id, puntaje);
    }

    // Ordenar los puntajes de mayor a menor
    std::sort(puntajes.begin(), puntajes.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    // Mostrar los puntajes
    //std::cout << "-------------------------" << std::endl;
    size_t i = 0;
    for (const auto &entry : puntajes) {
        if (i >= 3) {
            return; // Solo muestro el top 3...
        }
        uint32_t id = entry.first;
        uint32_t puntaje = entry.second;
        //std::cout << "ID: " << id << " - Puntaje: " << puntaje << std::endl;
        
        if (entry.first == id_jugador) {
            color = {0, 255, 0, 0};
        } else {
            color = {255, 255, 255, 255};
        }
        // Muestro puntaje del jugador
        texto = std::to_string(id) + ": " + std::to_string(puntaje);
        surface_texto = font.RenderText_Solid(texto, color);
        texto_textura = SDL2pp::Texture(render, surface_texto);
        
        // Calcular posición de renderizado
        int x = ancho_ventana - 130; // Ajustar para que no se salga de la ventana
        int y = i * 50;
        render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(x, y, 100, 30));
        
        i++;
    }

    // Muestro las municiones
    color = SDL_Color({255, 255, 255, 255});
    if(personajeViewPtr.obtener_cantidad_municion() == -1) {
        texto = "INF";
    } else {
        texto = std::to_string(personajeViewPtr.obtener_cantidad_municion());
    }
    surface_texto = font.RenderText_Solid(texto, color);
    texto_textura = SDL2pp::Texture(render, surface_texto);
    render.Copy(texto_textura, SDL2pp::NullOpt, SDL2pp::Rect(ancho_ventana-50, alto_ventana-20, 50, 20));

    // Muestro el tipo de bala
    // Ver como rellenar el texto de blanco, asi se ve mejor...
    std::cout << "MUNICIONES: " << personajeViewPtr.obtener_cantidad_municion() << std::endl;
    std::cout << "TIPO_ BALA: " << personajeViewPtr.obtener_tipo_bala() << std::endl;

    std::string tipo_bala = "bala_tipo_" + std::to_string(personajeViewPtr.obtener_tipo_bala());
    rect.x = (ancho_ventana-ICONO_WIDHT-50);
    rect.y = (alto_ventana-ICONO_HEIGHT);
    rect.w = (ICONO_WIDHT);
    rect.h = (ICONO_HEIGHT);
    render.Copy(*texturas[tipo_bala], SDL2pp::NullOpt, SDL2pp::Rect(rect.x, rect.y, rect.w, rect.h));
}

Interfaz::~Interfaz() {
    for (auto& pair : texturas) {
        delete pair.second;
    }
}
