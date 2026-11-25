#include <stdio.h>
#include <string.h>
#include "competidor.h"

void inicializar_competidor(Competidor *c, int id, const char *nombre) {
	c->id = id;
    
	strncpy(c->nombre, nombre, sizeof(c->nombre) - 1);
	c->nombre[sizeof(c->nombre) - 1] = '\0';
	c->cantidad_puntajes = 0;
}

void agregar_puntaje(Competidor *c, int puntaje) {
	if (c->cantidad_puntajes < MAX_PUNTAJES) {
		c->puntajes[c->cantidad_puntajes] = puntaje;
		c->cantidad_puntajes++;
	} else {
		printf("[Aviso]: Arreglo lleno para el competidor %s.\n", c->nombre);
	}
}

void mostrar_competidor(const Competidor *c) {
	printf("\n===================================\n");
	printf(" COMPETIDOR [%d]: %s\n", c->id, c->nombre);
	printf("===================================\n");
	printf("Puntajes: ");
	for (int i = 0; i < c->cantidad_puntajes; i++) {
		printf("[%d] ", c->puntajes[i]);
	}
	printf("\n===================================\n");
}
