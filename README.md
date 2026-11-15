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

La inteligencia artificial se utilizo como herramienta para resolver problemas como dudas que tengamos sobre C o bugs que no encontramos y como evitarlos, pero mas que nada para ayudar al tener errores al momento de compilar debido a que no entendiamos mensajes como 
PS C:\Users\gusta\Downloads\Laboratorio de C k 1.3 C900> gcc main.c simulador.c fisica.c validaciones.c -o simulador.exe -lm                             
c:/mingw/bin/../lib/gcc/mingw32/6.3.0/../../../../mingw32/bin/ld.exe: cannot open output file simulador.exe: Permission denied
collect2.exe: error: ld returned 1 exit status
PS C:\Users\gusta\Downloads\Laboratorio de C k 1.3 C900>
Que al momento de preguntar a Gemini con el prompt "A que hace referencia este mensaje de error al intentar compilar mi codigo en C nuevamente...." nos respondio "ste error (Permission denied) ocurre porque el sistema operativo Windows está bloqueando el archivo simulador.exe, lo que impide que gcc pueda sobrescribirlo durante la compilación. Generalmente se debe a que el programa quedó abierto o ejecutándose en segundo plano." junto a una serie de instrucciones de que hacer para solucionarlo
Tambien se le pidio consejos a chat gpt al escribir validaciones, al ingresar el prompt "Que recomendaciones nos darias para el codigo de validaciones" nos respondio: "Te recomiendo usar fgets() en tu código porque tu proyecto tiene un menú interactivo y necesita validar los datos que ingresa el usuario.
La idea es evitar que el programa se rompa o trabaje con valores incorrectos cuando alguien ingresa algo que no corresponde. Si utilizás scanf("%d", &opcion), la lectura falla porque hola no es un número entero. Además, puede quedar texto pendiente en el búfer de entrada y provocar problemas en las siguientes lecturas." y otras consultas mientras íbamos desarrollando el codigo.
