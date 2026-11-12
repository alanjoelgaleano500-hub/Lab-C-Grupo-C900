
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

double leerReal(double minimo, double maximo) {
    char entrada[100];
    char *fin;
    double numero;
    while (1) {
        printf("Ingrese un numero (%.2f a %.2f): ", minimo, maximo);
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
