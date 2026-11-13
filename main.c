#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "simulador.h"
// para acordarme gcc main.c simulador.c fisica.c validaciones.c -o simulador.exe -lm y luego .\simulador.exe

void clean() {
        system("cls");
}
void presionar() {
    printf("\nPresiona Enter para continuar.");
    while (getchar() != '\n'); 
    getchar(); 
}

int main() {
    int opcion;
    do {

        clean(); 

        printf("\n===== SIMULADOR ARTEMIS =====\n");
        printf("1. Iniciar simulacion\n");
        printf("2. Modificar parametros\n");
        printf("3. Ver resultados\n");
        printf("4. Salir\n");
        opcion = leerEntero(1, 4);
        
        switch (opcion) {
            case 1:
                printf("\nIniciando simulacion...\n");
                iniciarSimulacion();
                presionar();
                break;
            case 2: {
                double aceleracion;

                printf("\nModificar aceleracion del cohete\n");

                aceleracion = leerReal(1.0, 50.0);

                printf("Aceleracion ingresada: %.2f m/s2\n", aceleracion);
                clean();
                break;
            } 
            case 3:
                printf("Mostrar resultados...\n");
                clean();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("ingrese una opcion valida");
        }
    } while (opcion != 4);

    return 0;
}
