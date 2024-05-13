#ifndef SERVER_SERVIDOR_H_
#define SERVER_SERVIDOR_H_

#include <string>
#include <iostream>

class Servidor{
private:
    const std::string puerto;
public:
    explicit Servidor(const std::string &puerto);

    void run();

    Servidor(const Servidor&) = delete;
    Servidor& operator = (const Servidor&) = delete;

};


#endif