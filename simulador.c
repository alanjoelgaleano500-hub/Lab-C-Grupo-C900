#include <stdio.h>
#include <math.h>
#include "simulador.h"
#include "fisica.h"
#include "validaciones.h"

ParametrosMision mision = {
    20.0,     // aceleracion1
    12.5,     // aceleracion2
    120.0,    // tiempoSRB
    160000.0, // alturaObjetivo
    9.80      // gravedad
};

void actualizarParametro(int opcion, double nuevoValor) {
    switch (opcion) {
        case 1: mision.aceleracion1 = nuevoValor; break;
        case 2: mision.aceleracion2 = nuevoValor; break;
        case 3: mision.tiempoSRB = nuevoValor; break;
        case 4: mision.alturaObjetivo = nuevoValor; break;
        case 5: mision.gravedad = nuevoValor; break;
    }
    printf("Parametro actualizado con exito.\n");
}

// si ves los const Estad_nav * vi q es para mejor rendimiento por un tema de pasar a memoria y q no toque los datos originales

void regisEstad(Estad_nav *historial, int *cant, const Estad_nav *nuevo) {
    if (*cant < MAX_HISTORI) {
        *(historial + *cant) = *nuevo;
        (*cant)++;
    }
}

void mostrarResultados(Estad_nav estad1, Estad_nav estad2, double tiempoTotal, double gravedadRelativa) {
    printf("\n--- RESULTADOS DE LA MISION ---\n");
    printf("Fase 1 (Desacople) -> Altura: %.2f m | Velocidad: %.2f m/s\n", estad1.altura, estad1.velocidad);
    printf("Fase 2 (Apagado motores) -> Altura: %.2f m | Velocidad: %.2f m/s\n", estad2.altura, estad2.velocidad);
    printf("Tiempo total de vuelo: %.2f s\n", tiempoTotal);
    printf("Aceleracion relativa (Fase 1): %.2f g\n", gravedadRelativa);
}

void mostrarHistorial(const Estad_nav *historial, int cant) {
    printf("\nHistorial de estados:\n");
    printf("Tiempo(s)\tAltura(m)\tVelocidad(m/s)\tAceleracion(m/s2)\n");
    
    const Estad_nav *ptr = historial;
    for (int i = 0; i < cant; i++, ptr++) {
        printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", 
               ptr->tiempo, ptr->altura, ptr->velocidad, ptr->aceleracion);
    }
}

void iniciarSimulacion(void) {
    Estad_nav historial[MAX_HISTORI];
    int cant = 0;

    Estad_nav nave = {0.0, 0.0, 0.0, mision.aceleracion1};
    regisEstad(historial, &cant, &nave);

    printf("\nIniciando simulacion del cohete...\n");

    double tSRB = mision.tiempoSRB;
    double hSRB = calcuPosicionMRUV(0, 0, mision.aceleracion1, tSRB);
    double vSRB = calcuVelocidadMRUV(0, mision.aceleracion1, tSRB);

    Estad_nav estadoSRB;
    Estad_nav estadoMotor;
    double tiempoTotal = 0;

    // Verificar si la altura objetivo se alcanza ya durante la Fase 1
    if (hSRB >= mision.alturaObjetivo) {
        printf("\n[AVISO] La nave alcanzo la altura objetivo durante la Fase 1.\n");
        
        double tObjetivo = sqrt((2.0 * mision.alturaObjetivo) / mision.aceleracion1);
        double vObjetivo = calcuVelocidadMRUV(0, mision.aceleracion1, tObjetivo);

        nave.tiempo = tObjetivo;
        nave.altura = mision.alturaObjetivo;
        nave.velocidad = vObjetivo;
        nave.aceleracion = mision.aceleracion1;
        regisEstad(historial, &cant, &nave);

        estadoSRB = nave;
        estadoMotor = nave;
        tiempoTotal = tObjetivo;
    } else {
        // Fase 1
        nave.tiempo = tSRB;
        nave.altura = hSRB;
        nave.velocidad = vSRB;
        nave.aceleracion = mision.aceleracion1;
        regisEstad(historial, &cant, &nave);
        estadoSRB = nave;

        // Fase 2
        double distancia = mision.alturaObjetivo - hSRB;
        nave.aceleracion = mision.aceleracion2;
        nave.velocidad = calcuVelocidadSinTiempo(vSRB, nave.aceleracion, distancia);
        
        double tFase2 = (nave.velocidad - vSRB) / nave.aceleracion;
        nave.tiempo = tSRB + tFase2;
        nave.altura = mision.alturaObjetivo;
        
        regisEstad(historial, &cant, &nave);
        estadoMotor = nave;
        tiempoTotal = nave.tiempo;
    }

    double gRelativa = calcuMultiploGravedad(mision.aceleracion1, mision.gravedad);
    mostrarResultados(estadoSRB, estadoMotor, tiempoTotal, gRelativa);

    // Opcion de falla con registro en el historial
    printf("\nDesea simular una falla de motores al llegar arriba? (1: Si, 2: No): ");
    if (leerEntero(1, 2) == 1) {
        double hExtra = calcuAlturaMaxima(nave.velocidad, mision.gravedad);
        double tSubidaLibre = nave.velocidad / mision.gravedad;

        nave.tiempo += tSubidaLibre;
        nave.altura += hExtra;
        nave.velocidad = 0.0;            // en el pnto maximo la velocidad vertical es 0
        nave.aceleracion = -mision.gravedad; // para q solo actue la gravedad hacia abajo

        regisEstad(historial, &cant, &nave);

        printf("\n[FALLA] La nave entra en caida libre.\n");
        printf("Altura maxima alcanzada antes de caer: %.2f m (en t = %.2f s)\n", nave.altura, nave.tiempo);
    }

    mostrarHistorial(historial, cant);
}
