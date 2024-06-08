#include <gtest/gtest.h>
#include "../src/server_src/personaje/personaje_jazz.h"


/*PERSONAJE JAZZ HEREDA DE LA CLASE PERSONAJE. AL PERSONAJE SER UNA CLASE ABSTRACTA
NO ES POSIBLE TESTEARLA USANDO GTESTS. PROBAR LOS METODOS PRINCIPALES DE JAZZ
ES LO MISMO QUE PROBAR LOS DE LA CLASE PERSONAJE*/
struct PersonajeJazzTest : testing::Test{
    Personaje * personaje;

    PersonajeJazzTest(){
        personaje = new Jazz(001);
    }

    ~PersonajeJazzTest(){
        delete personaje;
    }
};


TEST_F(PersonajeJazzTest, IniciaQuieto){
    EXPECT_EQ(personaje->obtener_movimiento(), true);
    EXPECT_EQ(personaje->obtener_corriendo(), false);
    //EXPECT_EQ(personaje->obtener_saltando(), false);
}

TEST_F(PersonajeJazzTest, IniciaSinDisparar){
    EXPECT_EQ(personaje->obtener_disparando(), false);
}

TEST_F(PersonajeJazzTest, IniciaMirandoDerecha){
    EXPECT_EQ(personaje->mirando_izquierda(), false);
}

TEST_F(PersonajeJazzTest, VidaInicial){
    EXPECT_LT(0, personaje->obtener_vida());
    EXPECT_EQ(personaje->esta_muerto(), false);
}

TEST_F(PersonajeJazzTest, IniciaSinUsarHabilidad){
    EXPECT_EQ(personaje->obtener_habilidad(), false);
}

TEST_F(PersonajeJazzTest, IniciaSinVelocidad){
    EXPECT_EQ(personaje->obtener_velocidad(), 0);
}

TEST_F(PersonajeJazzTest, AlMoverseNoEstaQuieto){
    std::chrono::duration<double> tiempo_transcurrido(0.5);
    personaje->mover_derecha(tiempo_transcurrido); //Hago un movimiento
    EXPECT_EQ(personaje->obtener_movimiento(), false);
}

TEST_F(PersonajeJazzTest, DispararActualizaSuEstado){
    std::chrono::duration<double> tiempo_transcurrido(0.5);
    personaje->disparar(tiempo_transcurrido);
    EXPECT_EQ(personaje->obtener_disparando(), true);

}

TEST_F(PersonajeJazzTest, DejarDeDisparar){
    personaje->dejar_disparar();
    EXPECT_EQ(personaje->obtener_disparando(), false);
}

TEST_F(PersonajeJazzTest, AlRecibirDanioBajaLaVida){
    uint8_t vida_incial = personaje->obtener_vida();
    std::chrono::duration<double> tiempo_transcurrido(0.5);
    personaje->recibir_golpe(uint8_t(10), tiempo_transcurrido);
    EXPECT_LT(personaje->obtener_vida(), vida_incial);
}

TEST_F(PersonajeJazzTest, Muerte){
    uint8_t vida_incial = personaje->obtener_vida();
    std::chrono::duration<double> tiempo_transcurrido(0.5);
    personaje->recibir_golpe(uint8_t(vida_incial + uint8_t(100)), tiempo_transcurrido); // le hago un danio mayor a su vida
    EXPECT_EQ(personaje->esta_muerto(), true);
}

TEST_F(PersonajeJazzTest, Revivir){
    uint8_t vida_incial = personaje->obtener_vida();
    std::chrono::duration<double> tiempo_transcurrido(0.5);
    personaje->recibir_golpe(vida_incial + uint8_t(10), tiempo_transcurrido); // le hago un danio mayor a su vida
    personaje->revivir();
    EXPECT_EQ(personaje->esta_muerto(), false);
    EXPECT_EQ(personaje->obtener_vida(), vida_incial); // VEO QUE SU VIDA SEA IGUAL A LA INICIAL
}

//TEST PARTICULAR DE JAZZ


TEST_F(PersonajeJazzTest, obtenerPersonaje){
    EXPECT_EQ(personaje->obtener_personaje(), JAZZ);
    
}




int main(int argc, char*argv[]){
    std::cout << "Tests Personaje JAZZ" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}