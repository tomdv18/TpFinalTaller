#include <gtest/gtest.h>
#include "../src/server_src/personaje/personaje_lori.h"



struct PersonajeLoriTest : testing::Test{
    Personaje * personaje;

    PersonajeLoriTest(){
        personaje = new Lori(001);
    }

    ~PersonajeLoriTest(){
        delete personaje;
    }
};

//TEST PARTICULAR DE JAZZ


TEST_F(PersonajeLoriTest, obtenerPersonaje){
    EXPECT_EQ(personaje->obtener_personaje(), LORI);
    
}

int main(int argc, char*argv[]){
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "\nTests Personaje LORI\n" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}