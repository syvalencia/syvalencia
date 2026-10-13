#include "ordenamiento.h"

static void intercambiar(int *a, int *b) {
	int temporal = *a;
	*a = *b;
	*b = temporal;
}

void bubble_sort(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				intercambiar(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void selection_sort(int *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int indice_min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[indice_min]) {
				indice_min = j;
			}
		}
		if (indice_min != i) {
			intercambiar(&arr[i], &arr[indice_min]);
		}
	}
}

void insertion_sort(int *arr, int n) {
	for (int i = 1; i < n; i++) {
		int clave = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > clave) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = clave;
	}
}
