#include "jugador.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int leerLinea(const char *mensaje, char *texto, size_t capacidad)
{
    size_t longitud;

    printf("%s", mensaje);
    if (fgets(texto, (int)capacidad, stdin) == NULL) {
        return 0;
    }

    longitud = strcspn(texto, "\n");
    if (texto[longitud] == '\n') {
        texto[longitud] = '\0';
    } else {
        int caracter;
        while ((caracter = getchar()) != '\n' && caracter != EOF) {
        }
    }

    return 1;
}

int leerJugador(Jugador *jugador)
{
    char entrada[100];
    char *fin;
    long puntaje;
    size_t longitud;
    size_t indice;

    for (;;) {
        if (!leerLinea("Iniciales del jugador (3 letras): ", entrada, sizeof(entrada))) {
            return 0;
        }

        longitud = strlen(entrada);
        if (longitud == 3) {
            for (indice = 0; indice < longitud; indice++) {
                if (!isalpha((unsigned char)entrada[indice])) {
                    break;
                }
            }
            if (indice == longitud) {
                for (indice = 0; indice < longitud; indice++) {
                    jugador->iniciales[indice] = (char)toupper((unsigned char)entrada[indice]);
                }
                jugador->iniciales[3] = '\0';
                break;
            }
        }
        printf("Ingresa exactamente tres letras, por ejemplo: ANA.\n");
    }

    for (;;) {
        if (!leerLinea("Puntaje (numero entero positivo o cero): ", entrada, sizeof(entrada))) {
            return 0;
        }

        errno = 0;
        puntaje = strtol(entrada, &fin, 10);
        while (isspace((unsigned char)*fin)) {
            fin++;
        }

        if (entrada[0] != '\0' && *fin == '\0' && errno != ERANGE &&
            puntaje >= 0 && puntaje <= INT_MAX) {
            jugador->puntaje = (int)puntaje;
            return 1;
        }
        printf("El puntaje debe ser un entero entre 0 y %d.\n", INT_MAX);
    }
}