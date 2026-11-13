#ifndef FISICA_H
#define FISICA_H

double calcuVelocidadMRUV(double velocidadInicial, double aceleracion, double tiempo);
double calcuPosicionMRUV(double posicionInicial, double velocidadInicial, double aceleracion, double tiempo);
double calcuVelocidadSinTiempo(double velocidadInicial, double aceleracion, double desplazamiento);
double calcuAlturaMaxima(double velocidadInicial, double gravedad);
double calcuMultiploGravedad(double aceleracion, double gravedad);

#endif