#ifndef RANKING_H
#define RANKING_H

#define MAX_RANKING 3

#include "jugador.h"

typedef struct {
    Jugador jugadores[MAX_RANKING];
    int cantidad;
} Ranking;

void inicializarRanking(Ranking *ranking);
int insertarJugador(Ranking *ranking, Jugador jugador);
void mostrarRanking(const Ranking *ranking);

#endif