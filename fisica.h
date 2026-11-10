#ifndef FISICA_H
#define FISICA_H
#define GRAVEDAD_TIERRA 9.81

double calcularVelocidadMRUV(double velocidadInicial, double aceleracion, double tiempo);
double calcularPosicionMRUV(double posicionInicial, double velocidadInicial, double aceleracion, double tiempo);
double calcularVelocidadSinTiempo(double velocidadInicial, double aceleracion, double desplazamiento);
double calcularAlturaMaxima(double velocidadInicial, double gravedad);
double calcularMultiploGravedad(double gravedadLocal);

#endif
