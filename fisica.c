#include "fisica.h"

#include <math.h>

// MRUV: v = v0 + a * t
double calcuVelocidadMRUV(double velocidadInicial, double aceleracion, double tiempo) {
    return velocidadInicial + aceleracion * tiempo;
}

// MRUV: x = x0 + v0 * t + (1/2) * a * t^2
double calcuPosicionMRUV(double posicionInicial, double velocidadInicial, double aceleracion, double tiempo) {
    return posicionInicial + (velocidadInicial * tiempo) + (0.5 * aceleracion * tiempo * tiempo);
}

// MRUV sin tiempo: v^2 = v0^2 + 2 * a * Δx
double calcuVelocidadSinTiempo(double velocidadInicial, double aceleracion, double desplazamiento) {
    double velocidadFinalCuadrado = (velocidadInicial * velocidadInicial) + (2.0 * aceleracion * desplazamiento);

    if (velocidadFinalCuadrado < 0.0) {
        return 0.0;
    }

    return sqrt(velocidadFinalCuadrado);
}

// Altura máxima en lanzamiento vertical: h_max = v0^2 / (2 * g)
double calcuAlturaMaxima(double velocidadInicial, double gravedad) {
    return (velocidadInicial * velocidadInicial) / (2.0 * gravedad);
}

// Múltiplo de la gravedad terrestre: g_local / g_tierra
double calcuMultiploGravedad(double gravedadLocal) {
    return gravedadLocal / GRAVEDAD_TIERRA;
}
