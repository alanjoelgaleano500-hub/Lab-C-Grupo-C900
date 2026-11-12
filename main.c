
#include <stdio.h>
#include "validaciones.h"

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
