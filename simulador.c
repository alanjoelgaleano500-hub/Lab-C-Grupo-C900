#include <stdio.h>
#include "simulador.h"
#include "fisica.h"
#include "validaciones.h"

void regisEstad(Estad_nav historial[], // el historial seria el arreglo
                int *cant,
                Estad_nav Nue_estad) {
  if (*cant < MAX_HISTORI) {
      historial[*cant] = Nue_estad;
      (*cant)++;
  }
}

void mostrarResultados(Estad_nav estad1, // es para mostrar los resultados gnrals
                       Estad_nav estad2,
                       double tiempTotal,
                       double gravedRelativa) {

    printf("\n========== RESULTADOS ==========\n");
    printf("FASE 1 - DESPRENDIMIENTO \n");
    printf("Altura: %.2f m\n", estad1.altura);
    printf("Velocidad: %.2f m/s\n", estad1.velocidad);
    printf("\nFASE 2 - APAGADO DE MOTORES\n");
    printf("Altura: %.2f m\n", estad2.altura);
    printf("Velocidad: %.2f m/s\n", estad2.velocidad);
    printf("\nTiempo total: %.2f segundos\n", tiempTotal);
    printf("Aceleracion relativa: %.2f g\n", gravedRelativa);
    printf("================================\n");
}

void iniciarSimulacion(void) { // ejecuta la simulacion completa

    ParametrosMision mision = {
        20.0,
        12.5,
        120.0,
        160000.0,
        9.80
    };

    Estad_nav historial[MAX_HISTORI]; // arreglo para los estados
    int cant = 0;

    Estad_nav nave;
    nave.tiempo = 0;
    nave.altura = 0;
    nave.velocidad = 0;
    nave.aceleracion = mision.aceleracion1;

    regisEstad(historial, &cant, nave);

    printf("\n========== INICIO DE MISION ==========\n");
    printf("Altura inicial: 0 metros\n");
    printf("Velocidad inicial: 0 m/s\n");
    printf("\n========== FASE 1 ==========\n");
    printf("Ascenso con cohetes\n");

    nave.velocidad = calcuVelocidadMRUV( 
        0,
        mision.aceleracion1,
        mision.tiempoSRB
    );

    nave.altura = calcuPosicionMRUV(
        0,
        0,
        mision.aceleracion1,
        mision.tiempoSRB
    );

    nave.tiempo = mision.tiempoSRB;

    regisEstad(historial, &cant, nave);

    printf("Tiempo: %.2f segundos\n", nave.tiempo);
    printf("Altura: %.2f metros\n", nave.altura);
    printf("Velocidad: %.2f m/s\n", nave.velocidad);

    Estad_nav estadoSRB = nave; // guarda el estado de la fase 1

    printf("\n>   DESPRENDIMIENTO    \n");
    printf("\n========== FASE 2 ==========\n");
    printf("Continua el ascenso con motor principal\n");

    nave.aceleracion = mision.aceleracion2;

    double distancia = mision.alturaObjetivo - nave.altura;


    nave.velocidad = calcuVelocidadSinTiempo(
        nave.velocidad,
        nave.aceleracion,
        distancia
    );

    double tiempoFase2 = (nave.velocidad - estadoSRB.velocidad) / nave.aceleracion;

    nave.tiempo = estadoSRB.tiempo + tiempoFase2;
    nave.altura = mision.alturaObjetivo;

    regisEstad(historial, &cant, nave);

    Estad_nav estadoMotor = nave; // guarda el estado final de propulsion
 
    printf("Altura alcanzada: %.2f metros\n", nave.altura);
    printf("Velocidad: %.2f m/s\n", nave.velocidad);
    printf("Tiempo de fase 2: %.2f segundos\n", tiempoFase2);

    printf("\n    APAGADO DE MOTORES    \n");

    double gravedadRelativa = calcuMultiploGravedad(mision.aceleracion1);

    mostrarResultados(
        estadoSRB,
        estadoMotor,
        nave.tiempo,
        gravedadRelativa
    );

    printf("\nQuieres simular una falla de motores? (1 = Si, 2 = No)\n");

    int respuesta = leerEntero(1, 2);

    if (respuesta == 1) {

        printf("\n    FALLA DE MOTORES    \n");
        printf("La nave va en caida libre.\n");

        double alturaExtra = calcuAlturaMaxima(
            nave.velocidad,
            mision.gravedad
        );
        double alturaMaxima = nave.altura + alturaExtra;

        printf("\n========== RESULTADO DE FALLA ==========\n");
        printf("Altura al momento de la falla: %.2f m\n", nave.altura);
        printf("Velocidad inicial de caida: %.2f m/s\n", nave.velocidad);
        printf("Altura maxima alcanzada: %.2f m\n", alturaMaxima);
        printf("La nave comienza a descender.\n");

    } else {
        printf("\nSimulacion finalizada sin falla.\n");
    }

    printf("\n========== HISTORIAL ==========\n");
    printf("Tiempo\tAltura\t\tVelocidad\n");

    for (int i = 0; i < cant; i++) {
        printf("%.2f\t%.2f\t%.2f\n",
               historial[i].tiempo,
               historial[i].altura,
               historial[i].velocidad);
    }

    printf("\n========== FIN DE MISION ==========\n");
}
