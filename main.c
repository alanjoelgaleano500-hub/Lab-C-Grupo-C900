
#include <stdio.h>
#include "validaciones.h"
#include "simulador.h"
// para acordarme gcc main.c simulador.c fisica.c validaciones.c -o simulador.exe -lm y luego .\simulador.exe
int main() {
    int opcion;
    do {
        printf("\n===== SIMULADOR ARTEMIS =====\n");
        printf("1. Iniciar simulacion\n");
        printf("2. Modificar parametros\n");
        printf("3. Ver resultados\n");
        printf("4. Salir\n");
        opcion = leerEntero(1, 4);
        switch (opcion) {
            case 1:
                printf("Iniciando simulacion...\n");
                iniciarSimulacion();
                break;
            case 2: {
                double aceleracion;

                printf("\nModificar aceleracion del cohete\n");

                aceleracion = leerReal(1.0, 50.0);

                printf("Aceleracion ingresada: %.2f m/s2\n", aceleracion);
                break;
            } 
            case 3:
                printf("Mostrar resultados...\n");
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
