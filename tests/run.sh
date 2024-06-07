#!/bin/bash

# Ruta al directorio donde se encuentran los ejecutables de prueba
TEST_DIR="./tests"

# Itera sobre todos los ejecutables de prueba en el directorio
for TEST_EXECUTABLE in $(ls $TEST_DIR/test_* | grep -v 'CMakeLists.txt'); do
    if [ -x "$TEST_EXECUTABLE" ]; then
        echo "Ejecutando prueba: $TEST_EXECUTABLE"
        # Ejecuta el test
        "$TEST_EXECUTABLE"
    fi
done

echo "Todos los tests han sido ejecutados"
