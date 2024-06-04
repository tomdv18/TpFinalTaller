#ifndef DIRECCIONES_H_
#define DIRECCIONES_H_
#include <string>
#include <map>

char const PATH_JAZZ_CAMINANDO[] = "../src/client_src/Images/Jazz_caminando.png";
char const PATH_JAZZ_QUIETO[] = "../src/client_src/Images/Jazz_quieto.png";
char const PATH_JAZZ_CORRIENDO[] = "../src/client_src/Images/Jazz_corriendo.png";
char const PATH_JAZZ_SALTANDO[] = "../src/client_src/Images/Jazz_saltando.png";

char const PATH_LORI_CAMINANDO[] = "../src/client_src/Images/Lori_caminando.png";
char const PATH_LORI_QUIETO[] = "../src/client_src/Images/Lori_quieto.png";
char const PATH_LORI_CORRIENDO[] = "../src/client_src/Images/Lori_corriendo";
char const PATH_LORI_SALTANDO[] = "../src/client_src/Images/Lori_saltando.png";

char const PATH_SPAZ_CAMINANDO[] = "../src/client_src/Images/Spaz_caminando.png";
char const PATH_SPAZ_QUIETO[] = "../src/client_src/Images/Spaz_quieto.png";
char const PATH_SPAZ_CORRIENDO[] = "../src/client_src/Images/Spaz_corriendo";
char const PATH_SPAZ_SALTANDO[] = "../src/client_src/Images/Spaz_saltando.png";


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