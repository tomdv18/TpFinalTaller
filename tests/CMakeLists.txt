cmake_minimum_required(VERSION 3.16)
project(JazzJackRabbit2)

# Configura las pruebas
add_executable(test_personaje_jazz test_personaje_jazz.cpp)
add_executable(test_personaje_spaz test_personaje_spaz.cpp)
add_executable(test_personaje_lori test_personaje_lori.cpp)

# Enlaza con Google Test
target_link_libraries(test_personaje_jazz PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(test_personaje_spaz PRIVATE GTest::gtest GTest::gtest_main)
target_link_libraries(test_personaje_lori PRIVATE GTest::gtest GTest::gtest_main)

# Incluye el directorio raíz del proyecto para que pueda encontrar los archivos de cabecera
target_include_directories(test_personaje_jazz PUBLIC 
    ${CMAKE_SOURCE_DIR}/src/common_src 
    ${CMAKE_SOURCE_DIR}/src/server_src
)
target_include_directories(test_personaje_spaz PUBLIC 
    ${CMAKE_SOURCE_DIR}/src/common_src 
    ${CMAKE_SOURCE_DIR}/src/server_src
)
target_include_directories(test_personaje_lori PUBLIC 
    ${CMAKE_SOURCE_DIR}/src/common_src 
    ${CMAKE_SOURCE_DIR}/src/server_src
)

# Añade los archivos necesarios
target_sources(test_personaje_jazz PRIVATE  
    ${CMAKE_SOURCE_DIR}/src/common_src/accion.h 
    ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje_jazz.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/arma.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_quieto.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_muerto.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_herido.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_especial.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_corriendo.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_caminando.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_saltando.cpp
)
target_sources(test_personaje_spaz PRIVATE  
    ${CMAKE_SOURCE_DIR}/src/common_src/accion.h 
    ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje_spaz.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/arma.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_quieto.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_muerto.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_herido.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_especial.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_corriendo.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_caminando.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_saltando.cpp
)
target_sources(test_personaje_lori PRIVATE  
    ${CMAKE_SOURCE_DIR}/src/common_src/accion.h 
    ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje_lori.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/arma.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_quieto.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_muerto.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_herido.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_especial.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_corriendo.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_caminando.cpp
    ${CMAKE_SOURCE_DIR}/src/server_src/estado/estado_saltando.cpp
)
