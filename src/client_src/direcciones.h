#ifndef DIRECCIONES_H_
#define DIRECCIONES_H_
#include <string>
#include <map>

char const PATH_JAZZ_CAMINANDO[] = "../src/client_src/Images/Jazz_caminando.png";
char const PATH_JAZZ_QUIETO[] = "../src/client_src/Images/Jazz_quieto.png";
char const PATH_JAZZ_CORRIENDO[] = "../src/client_src/Images/Jazz_corriendo.png";
char const PATH_JAZZ_SALTANDO[] = "../src/client_src/Images/Jazz_saltando.png";
char const PATH_JAZZ_DISPARO_QUIETO[] = "../src/client_src/Images/Jazz_disparo_quieto.png";
char const PATH_JAZZ_DEJA_DISPARO_QUIETO[] = "../src/client_src/Images/Jazz_deja_disparo_quieto.png";

char const PATH_LORI_CAMINANDO[] = "../src/client_src/Images/Lori_caminando.png";
char const PATH_LORI_QUIETO[] = "../src/client_src/Images/Lori_quieto.png";
char const PATH_LORI_CORRIENDO[] = "../src/client_src/Images/Lori_corriendo.png";
char const PATH_LORI_SALTANDO[] = "../src/client_src/Images/Lori_saltando.png";
char const PATH_LORI_DISPARO_QUIETO[] = "../src/client_src/Images/Lori_disparo_quieto.png";
char const PATH_LORI_DEJA_DISPARO_QUIETO[] = "../src/client_src/Images/Lori_deja_disparo_quieto.png";

char const PATH_SPAZ_CAMINANDO[] = "../src/client_src/Images/Spaz_caminando.png";
char const PATH_SPAZ_QUIETO[] = "../src/client_src/Images/Spaz_quieto.png";
char const PATH_SPAZ_CORRIENDO[] = "../src/client_src/Images/Spaz_corriendo.png";
char const PATH_SPAZ_SALTANDO[] = "../src/client_src/Images/Spaz_saltando.png";
char const PATH_SPAZ_DISPARO_QUIETO[] = "../src/client_src/Images/Spaz_disparo_quieto.png";
char const PATH_SPAZ_DEJA_DISPARO_QUIETO[] = "../src/client_src/Images/Spaz_deja_disparo_quieto.png";

char const PATH_PROYECTIL_PISTOLA[] = "../src/client_src/Images/proyectil_pistola.png";

char const PATH_LIZZARD_CAMINANDO[] = "../src/client_src/Images/Liazzard_caminando.png";
char const PATH_FENCER_CAMINANDO[] = "../src/client_src/Images/Fencer_caminando.png";
char const PATH_RAT_CAMINANDO[] = "../src/client_src/Images/Rat_caminando.png";

char const CAMINANDO[] = "Caminando";
char const CORRIENDO[] = "Corriendo";
char const QUIETO_CLIENTE[] = "Quieto";
char const SALTANDO[] = "Saltando";
char const DISPARO_QUIETO[] = "Disparo_Quieto";
char const DEJA_DISPARO_QUIETO[] = "Dejar_Disparo_Quieto";


class Paths {

    private:

    std::map<std::string, std::string> jazz_paths;
    std::map<std::string, std::string> lori_paths;
    std::map<std::string, std::string> spaz_paths;

    public:

    Paths() {
        jazz_paths.insert(std::make_pair("Caminando", PATH_JAZZ_CAMINANDO));
        jazz_paths.insert(std::make_pair("Quieto", PATH_JAZZ_QUIETO));
        jazz_paths.insert(std::make_pair("Corriendo", PATH_JAZZ_CORRIENDO));
        jazz_paths.insert(std::make_pair("Saltando", PATH_JAZZ_SALTANDO));

        lori_paths.insert(std::make_pair("Caminando", PATH_LORI_CAMINANDO));
        lori_paths.insert(std::make_pair("Quieto", PATH_LORI_QUIETO));
        lori_paths.insert(std::make_pair("Corriendo", PATH_LORI_CORRIENDO));
        lori_paths.insert(std::make_pair("Saltando", PATH_LORI_SALTANDO));

        spaz_paths.insert(std::make_pair("Caminando", PATH_SPAZ_CAMINANDO));
        spaz_paths.insert(std::make_pair("Quieto", PATH_SPAZ_QUIETO));
        spaz_paths.insert(std::make_pair("Corriendo", PATH_SPAZ_CORRIENDO));
        spaz_paths.insert(std::make_pair("Saltando", PATH_SPAZ_SALTANDO));

    }

    std::map<std::string, std::string> get_jazz_path();

    std::map<std::string, std::string> get_lori_path();

    std::map<std::string, std::string> get_spaz_path();
};

#endif //PATHS_H_