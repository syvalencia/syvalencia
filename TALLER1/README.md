# Taller 1: Programacion modular en C

## Estructura

- `jugador.h` y `jugador.c`: datos y validacion de las iniciales y el puntaje.
- `ranking.h` y `ranking.c`: almacenamiento y orden descendente del Top 3.
- `juego.c`: menu de consola que conecta los dos modulos.
- `evidencias/`: capturas solicitadas para la entrega.

El ranking inicia con puntajes de ejemplo (ANA: 12000, LEO: 9500 y YHU: 8000) para probar la comparacion. Los cambios se conservan durante la ejecucion actual; al cerrar el programa se vuelve a esta tabla inicial.

## Compilacion separada con GCC

Desde esta carpeta, ejecuta:

```sh
gcc -std=c11 -Wall -Wextra -pedantic -c jugador.c -o jugador.o
gcc -std=c11 -Wall -Wextra -pedantic -c ranking.c -o ranking.o
gcc -std=c11 -Wall -Wextra -pedantic -c juego.c -o juego.o
gcc jugador.o ranking.o juego.o -o gta_ranking.exe
```

En Windows con GCC, ejecuta el programa con `./gta_ranking.exe`.

## Evidencias pendientes

Guarda en `evidencias/` capturas reales de: (1) los archivos y prototipos en el editor, (2) los cuatro comandos de compilacion sin errores y (3) una ejecucion donde un puntaje actualice el Top 3. No se incluyen imagenes generadas, para que las evidencias correspondan a tu propia ejecucion.