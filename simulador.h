#ifndef SIMULADOR_H
#define SIMULADOR_H
#define MAX_HISTORI 20

typedef struct {
    double tiempo;
    double altura;
    double velocidad;
    double aceleracion;
} Estad_nav;

typedef struct {
    double aceleracion1;
    double aceleracion2;
    double tiempoSRB;
    double alturaObjetivo;
    double gravedad;
} ParametrosMision;

void iniciarSimulacion(void);
void actualizarParametro(int opcion, double nuevoValor);
void mostrarResultados(Estad_nav estad1, Estad_nav estad2, double tiempoTotal, double gravedadRelativa);
void regisEstad(Estad_nav *historial, int *cant, const Estad_nav *nuevoEstado);
void mostrarHistorial(const Estad_nav *historial, int cant);

#endif
