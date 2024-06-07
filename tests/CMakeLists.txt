cmake_minimum_required(VERSION 3.16)
project(JazzJackRabbit2)

# Define una función para configurar las pruebas para un personaje específico
function(configure_personaje_test TEST_NAME PERSONAJE_NAME)
    add_executable(${TEST_NAME} test_${PERSONAJE_NAME}.cpp)
    target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest GTest::gtest_main)
    target_include_directories(${TEST_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/common_src ${CMAKE_SOURCE_DIR}/src/server_src)
    target_sources(${TEST_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src/common_src/accion.h
        ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje.cpp
        ${CMAKE_SOURCE_DIR}/src/server_src/personaje/personaje_${PERSONAJE_NAME}.cpp
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
endfunction()

# Configura las pruebas para los diferentes personajes
configure_personaje_test(test_personaje_jazz jazz)
configure_personaje_test(test_personaje_spaz spaz)
configure_personaje_test(test_personaje_lori lori)
