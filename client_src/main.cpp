#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    try {
        if (argc == 3) {
            const std::string hostname = std::string(argv[1]);
            const std::string servname = std::string(argv[2]);
            //Client client(hostname, servname);
            //client.execute();
            //client.shutdown();
            return 0;
        } else {
            std::cerr << "Bad program call. Expected " << argv[0] << " <hostname> <servername>"
                      << std::endl;
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
