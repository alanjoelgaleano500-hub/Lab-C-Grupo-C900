# Simulador Artemis: Ascenso y propulsión con el SLS GRUPO C900

## Integrantes de Grupo

- Galeano, Alan Joel
- Ayala Gaggino, Enzo Lautaro
- Ledesma, Gustavo Alberto

**Comisión:** C (K1.3)

## Descripción general del sistema

El programa simula de forma simplificada el ascenso vertical de la nave Orion, impulsada por el cohete Space Launch System (SLS). El movimiento se divide en dos fases de aceleración constante: la primera termina al desprenderse los cohetes SRB y la segunda continúa hasta alcanzar la altura objetivo.

También se puede simular una falla de motores al llegar a esa altura. En ese caso, el programa calcula cuánto más asciende la nave por inercia, considerando únicamente la gravedad. No se calcula la caída posterior.

Los valores iniciales son aceleraciones de 20,0 m/s² y 12,5 m/s², un tiempo de desprendimiento de 120 s, una altura objetivo de 160.000 m y una gravedad de 9,80 m/s². Los parámetros se pueden modificar desde el menú.

## Instrucciones de ejecución

El programa ya está compilado. Para iniciarlo en Windows, abre PowerShell en la carpeta del proyecto y ejecuta:

```powershell
.\simulador.exe
```

También puedes abrir `simulador.exe` desde el Explorador de archivos. Se mostrará el menú principal:

1. **Iniciar simulación:** calcula las fases del ascenso y muestra los resultados. Cuando se pregunte, ingresa `1` para simular una falla de motores o `2` para continuar sin ella.
2. **Modificar parámetros:** elige el valor que quieres cambiar, escribe un número dentro del rango indicado y presiona Enter. Usa la opción `6` para volver al menú principal.
3. **Salir:** cierra el programa.

En cada menú, escribe el número de la opción y presiona Enter. Los parámetros admiten decimales con punto o coma. Si ingresas un valor inválido, el programa volverá a solicitarlo.
