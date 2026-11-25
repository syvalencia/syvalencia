#include "jugador.h"
#include "ranking.h"

#include <stdio.h>
#include <string.h>

int main(void)
{
    Ranking ranking;
    Jugador jugador;
    char opcion[20];

    inicializarRanking(&ranking);
    printf("======================================\n");
    printf("       RETO ARCADE - GTA RANKING      \n");
    printf("======================================\n");

    for (;;) {
        printf("\n1. Registrar puntaje\n");
        printf("2. Ver Top 3\n");
        printf("0. Salir\n");
        printf("Elige una opcion: ");

        if (fgets(opcion, sizeof(opcion), stdin) == NULL) {
            printf("\nFin de la entrada. Hasta luego.\n");
            break;
        }
        opcion[strcspn(opcion, "\n")] = '\0';

        if (strcmp(opcion, "1") == 0) {
            if (!leerJugador(&jugador)) {
                printf("\nFin de la entrada. Hasta luego.\n");
                break;
            }

            if (insertarJugador(&ranking, jugador)) {
                printf("\nBuen juego, %s. Entraste al Top 3.\n", jugador.iniciales);
            } else {
                printf("\nBuen intento, %s. El puntaje no supera el tercer puesto.\n",
                       jugador.iniciales);
            }
            mostrarRanking(&ranking);
        } else if (strcmp(opcion, "2") == 0) {
            mostrarRanking(&ranking);
        } else if (strcmp(opcion, "0") == 0) {
            printf("Gracias por jugar. Los puntajes de esta sesion se han cerrado.\n");
            break;
        } else {
            printf("Opcion no valida. Elige 1, 2 o 0.\n");
        }
    }

    return 0;
}