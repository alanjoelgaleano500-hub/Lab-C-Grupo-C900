#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "simulador.h"
// para acordarme gcc main.c simulador.c fisica.c validaciones.c -o simulador.exe -lm y luego .\simulador.exe
void clean() {
    system("cls");
}
void presionar() {
    printf("\nPresiona Enter para continuar...");
    getchar();
}
int main() {
    int opcion;
    do {
        clean();
        printf("\n===== SIMULADOR ARTEMIS =====\n");
        printf("1. Iniciar simulacion\n");
        printf("2. Modificar parametros\n");
        printf("3. Salir\n");
        opcion = leerEntero(1, 3);
        switch (opcion) {
            case 1:
                clean();
                iniciarSimulacion();
                presionar();
                break;
            case 2: {
                int subOpcion;
                do {
                    clean();
                    printf("\n===== MODIFICAR PARAMETROS DE MISION =====\n");
                    printf("1. Aceleracion Fase 1 (m/s2)\n");
                    printf("2. Aceleracion Fase 2 (m/s2)\n");
                    printf("3. Tiempo de desprendimiento (s)\n");
                    printf("4. Altura objetivo (m)\n");
                    printf("5. Gravedad (m/s2)\n");
                    printf("6. Volver al menu principal\n");
                    subOpcion = leerEntero(1, 6);
                    if (subOpcion >= 1 && subOpcion <= 5) {
                        double nuevoValor = leerParametroMision(subOpcion);
                        actualizarParametro(subOpcion, nuevoValor);
                        presionar();
                    }
                } while (subOpcion != 6);
                break;
            }
            case 3:
                printf("\nSaliendo del programa...\n");
                break;
        }
    } while (opcion != 3);
    return 0;
}
