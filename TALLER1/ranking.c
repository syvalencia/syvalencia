#include "ranking.h"

#include <stdio.h>

void inicializarRanking(Ranking *ranking)
{
    ranking->jugadores[0] = (Jugador){"ANA", 12000};
    ranking->jugadores[1] = (Jugador){"LEO", 9500};
    ranking->jugadores[2] = (Jugador){"YHU", 8000};
    ranking->cantidad = MAX_RANKING;
}

int insertarJugador(Ranking *ranking, Jugador jugador)
{
    int posicion;
    int indice;

    if (ranking->cantidad == MAX_RANKING &&
        jugador.puntaje <= ranking->jugadores[MAX_RANKING - 1].puntaje) {
        return 0;
    }

    posicion = ranking->cantidad;
    if (ranking->cantidad < MAX_RANKING) {
        ranking->cantidad++;
    } else {
        posicion = MAX_RANKING - 1;
    }

    for (indice = posicion; indice > 0 &&
         jugador.puntaje > ranking->jugadores[indice - 1].puntaje; indice--) {
        ranking->jugadores[indice] = ranking->jugadores[indice - 1];
    }
    ranking->jugadores[indice] = jugador;

    return 1;
}

void mostrarRanking(const Ranking *ranking)
{
    int indice;

    printf("\n+----------------------------------+\n");
    printf("|          TOP 3 HISTORICO         |\n");
    printf("+------+------------+--------------+\n");
    printf("| Puesto | Iniciales |   Puntaje    |\n");
    printf("+------+------------+--------------+\n");

    for (indice = 0; indice < ranking->cantidad; indice++) {
        printf("|   %d  |    %-3s     | %10d   |\n",
               indice + 1,
               ranking->jugadores[indice].iniciales,
               ranking->jugadores[indice].puntaje);
    }

    for (; indice < MAX_RANKING; indice++) {
        printf("|   %d  |    ---     |      ---     |\n", indice + 1);
    }
    printf("+------+------------+--------------+\n");
}