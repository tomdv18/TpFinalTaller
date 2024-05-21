#ifndef SERVER_SERVIDOR_H_
#define SERVER_SERVIDOR_H_

#include <string>
#include <iostream>
#include <atomic>

class Servidor{
private:
    const std::string puerto;
    std::atomic<bool> servidor_cerrado;
    
public:
    explicit Servidor(const std::string &puerto);

    void run();

    Servidor(const Servidor&) = delete;
    Servidor& operator = (const Servidor&) = delete;

    Servidor(Servidor&&) = default;
    Servidor& operator=(Servidor&&) = default;

};


#endif