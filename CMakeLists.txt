cmake_minimum_required(VERSION 3.16)

project(JazzJackRabbit2
    DESCRIPTION "TP3 Taller De Programacion 1 1c2024 FIUBA"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

option(DEBUG "Compile in debug mode" OFF)
if (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb")
endif()
option(TESTING "Build internal testing suite" OFF)

include_directories(${CMAKE_SOURCE_DIR})
include(cmakeupdate/UpdateSubmodules.cmake)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(extern/googletest) ##HABRIA QUE CAMBIARLO PERO POR AHORA LO DEJO ASI

if (TESTING)
    add_subdirectory(tests)
    add_subdirectory(extern/googletest)
endif()
