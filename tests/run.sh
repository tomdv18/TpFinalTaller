#!/bin/bash

# Ruta al directorio donde se encuentran los ejecutables de prueba
TEST_DIR="./tests"

# Contadores de pruebas
TOTAL_TESTS=0
FAILED_TESTS=0

# Itera sobre todos los ejecutables de prueba en el directorio
for TEST_EXECUTABLE in $(ls $TEST_DIR/test_* | grep -v 'CMakeLists.txt'); do
    if [ -x "$TEST_EXECUTABLE" ]; then
        echo "Ejecutando prueba: $TEST_EXECUTABLE"
        TOTAL_TESTS=$((TOTAL_TESTS + 1))
        # Ejecuta el test
        "$TEST_EXECUTABLE"
        # Verifica el código de salida del test
        EXIT_CODE=$?
        if [ $EXIT_CODE -ne 0 ]; then
            echo "Error en la prueba: $TEST_EXECUTABLE"
            FAILED_TESTS=$((FAILED_TESTS + 1))
        fi
    fi
done

echo ""
echo "#--------------------------------------------------#"
echo "Total de pruebas ejecutadas: $TOTAL_TESTS"
echo "Total de pruebas fallidas: $FAILED_TESTS"
echo ""

if [ $FAILED_TESTS -ne 0 ]; then
    exit 1
else
    echo "Todos los tests han sido ejecutados exitosamente"
fi