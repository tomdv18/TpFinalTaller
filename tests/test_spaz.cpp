#include <gtest/gtest.h>
#include "../src/server_src/personaje/personaje_spaz.h"



struct PersonajeSpazTest : testing::Test{
    Personaje * personaje;

    PersonajeSpazTest(){
        personaje = new Spaz(001);
    }

    ~PersonajeSpazTest(){
        delete personaje;
    }
};


//TEST PARTICULAR DE SPAZ


TEST_F(PersonajeSpazTest, obtenerPersonaje){
    EXPECT_EQ(personaje->obtener_personaje(), SPAZ);
    
}




int main(int argc, char*argv[]){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "\nTests Personaje SPAZ\n" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}