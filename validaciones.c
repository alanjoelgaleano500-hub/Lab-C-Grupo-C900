#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>      

int leerEntero(int minimo, int maximo) {
    char entrada[100];
    char *fin;
    long numero;
    while (1) {
        printf("Ingrese un numero (%d a %d): ", minimo, maximo);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            exit(EXIT_FAILURE);
        }
        if (strchr(entrada, '\n') == NULL && !feof(stdin)) {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF) {
            }
            printf("Error, ingresaste demasiados caracteres\n");
            continue;
        }   
        errno = 0;
        numero = strtol(entrada, &fin, 10);
        if (fin == entrada || (*fin != '\n' && *fin != '\0') ||
            errno == ERANGE || numero < minimo || numero > maximo) {                         
            printf("Error, ingrese un numero entero valido!\n");
        } else {
            return (int) numero;   
        }
    }
}


double leerRealConMensaje(const char *mensaje, double minimo, double maximo) {
    char entrada[100];
    char *fin;
    double numero;
    while (1) {
        printf("Ingrese %s (%.2f a %.2f): ", mensaje, minimo, maximo);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            exit(EXIT_FAILURE);
        }
        if (strchr(entrada, '\n') == NULL && !feof(stdin)) {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF) {
            }
            printf("Error, ingresaste demasiados caracteres.\n");
            continue;
        }
        for (int i = 0; entrada[i] != '\0'; i++) {
            if (entrada[i] == ',') {
                entrada[i] = '.';
            }
        }
        numero = strtod(entrada, &fin);
        if (fin == entrada || (*fin != '\n' && *fin != '\0') ||
            !isfinite(numero) || numero < minimo || numero > maximo) {
            printf("Error, ingrese un numero valido dentro del rango.\n");
        } else {
            return numero;
        }
    }
}


double leerReal(double minimo, double maximo) {
    return leerRealConMensaje("un numero", minimo, maximo);
}

double leerParametroMision(int opcion) {

    const char *nombres[] = {
        "", 
        "la Aceleracion Fase 1 (m/s2)", 
        "la Aceleracion Fase 2 (m/s2)", 
        "el Tiempo de desprendimiento (s)", 
        "la Altura objetivo (m)", 
        "la Gravedad (m/s2)"
    };
    
    double limites[][2] = {
        {0.0, 0.0},
        {1.0, 100.0},    // Opcion 1
        {1.0, 100.0},    // Opcion 2
        {10.0, 500.0},   // Opcion 3
        {1000.0, 1000000.0}, // Opci 4
        {1.0, 30.0}      // Opci 5
    };

    if (opcion < 1 || opcion > 5) {
        return 0.0;
    }


    return leerRealConMensaje(nombres[opcion], limites[opcion][0], limites[opcion][1]);
}
