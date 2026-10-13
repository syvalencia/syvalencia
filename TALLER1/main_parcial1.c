#include <stdio.h>
#include "competidor.h"
#include "ordenamiento.h"

// Integrantes del Parcial1: Camilo Andres Mosquera Castrillon - Sara Yhuleiny Valencia Mina

void limpiar_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
	Competidor jugador;
	inicializar_competidor(&jugador, 2026, "Sara Yhuleiny Valencia Mina");
    
	agregar_puntaje(&jugador, 45);
	agregar_puntaje(&jugador, 92);
	agregar_puntaje(&jugador, 12);
	agregar_puntaje(&jugador, 78);
	agregar_puntaje(&jugador, 56);

	int opcion = 0;
	do {
		printf("\n*** EXAMEN PARCIAL 1 - CLASIFICACIONES ***\n");
		printf("1. Ver puntajes actuales\n");
		printf("2. Aplicar Bubble Sort\n");
		printf("3. Aplicar Selection Sort\n");
		printf("4. Aplicar Insertion Sort\n");
		printf("5. Salir del programa\n");
		printf("Seleccione una opcion: ");
        
		if (scanf("%d", &opcion) != 1) {
			printf("\n[Error]: Entrada invalida.\n");
			limpiar_buffer();
			continue;
		}
		limpiar_buffer();

		switch (opcion) {
			case 1:
				mostrar_competidor(&jugador);
				break;
			case 2:
				bubble_sort(jugador.puntajes, jugador.cantidad_puntajes);
				printf("\n[Ok]: Datos ordenados por Burbuja.\n");
				mostrar_competidor(&jugador);
				break;
			case 3:
				selection_sort(jugador.puntajes, jugador.cantidad_puntajes);
				printf("\n[Ok]: Datos ordenados por Seleccion.\n");
				mostrar_competidor(&jugador);
				break;
			case 4:
				insertion_sort(jugador.puntajes, jugador.cantidad_puntajes);
				printf("\n[Ok]: Datos ordenados por Insercion.\n");
				mostrar_competidor(&jugador);
				break;
			case 5:
				printf("\nCerrando simulacro de parcial...\n");
				break;
			default:
				printf("\n[Error]: Opcion fuera de rango.\n");
		}
	} while (opcion != 5);

	return 0;
}
