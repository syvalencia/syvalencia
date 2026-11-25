#ifndef JUGADOR_H
#define JUGADOR_H

typedef struct {
    char iniciales[4];
    int puntaje;
} Jugador;

int leerJugador(Jugador *jugador);

#endif