#include <iostream>
#include "servidor.h"

int main(int argc, char* argv[]) {
    try {
        if (argc == 2) {
            std::string puerto = std::string(argv[1]);
            Servidor servidor(puerto);
            servidor.run();
            return 0;
        } else {
            std::cerr << "Bad program call. Expected " << argv[0] << " <servername>" << std::endl;
            return 1;
        }
    } catch (const std::exception& err) {
        std::cerr << "Something went wrong and an exception was caught: " << err.what()
                  << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown exception was caught." << std::endl;
        return 1;
    }
}
