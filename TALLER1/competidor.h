#ifndef COMPETIDOR_H
#define COMPETIDOR_H

#define MAX_PUNTAJES 5

typedef struct {
	int id;
	char nombre[50];
	int puntajes[MAX_PUNTAJES];
	int cantidad_puntajes;
} Competidor;

void inicializar_competidor(Competidor *c, int id, const char *nombre);
void agregar_puntaje(Competidor *c, int puntaje);
void mostrar_competidor(const Competidor *c);

#endif
