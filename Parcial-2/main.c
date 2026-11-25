#include <stdio.h>
#include <stdlib.h>

struct Contenedor {
    int id;
    float pesoVacio;
    float pesoCarga;
    float pesoTotal;
    float precio;
    struct Contenedor *anterior;
    struct Contenedor *siguiente;
};

struct Registro {
    struct Contenedor *inicio;
    struct Contenedor *fin;
    int siguienteId;
};

static void limpiarEntrada(void) {
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF) {}
}

static struct Contenedor *buscarPorId(struct Registro *registro, int id) {
    struct Contenedor *actual = registro->inicio;

    while (actual != NULL) {
        if (actual->id == id) {
            return actual;
        }
        actual = actual->siguiente; 
    }
    return NULL;
}

static void mostrarContenedor(const struct Contenedor *contenedor) {
    printf("\nID: %d\n", contenedor->id);
    printf("Peso vacio (tara): %.2f\n", contenedor->pesoVacio);
    printf("Peso de carga: %.2f\n", contenedor->pesoCarga);
    printf("Peso total: %.2f\n", contenedor->pesoTotal);
    printf("Precio o costo: %.2f\n", contenedor->precio);
}

static void insertar(struct Registro *registro) {
    struct Contenedor *nuevo = (struct Contenedor *)malloc(sizeof(struct Contenedor));

    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    printf("Peso vacio (tara): ");
    if (scanf("%f", &nuevo->pesoVacio) != 1) {
        limpiarEntrada();
        printf("Error: dato invalido.\n");
        free(nuevo);
        return;
    }

    printf("Peso de carga: ");
    if (scanf("%f", &nuevo->pesoCarga) != 1) {
        limpiarEntrada();
        printf("Error: dato invalido.\n");
        free(nuevo);
        return;
    }

    printf("Precio o costo: ");
    if (scanf("%f", &nuevo->precio) != 1) {
        limpiarEntrada();
        printf("Error: dato invalido.\n");
        free(nuevo);
        return;
    }

    if (nuevo->pesoVacio < 0 || nuevo->pesoCarga < 0 || nuevo->precio < 0) {
        printf("Error: los valores deben ser no negativos.\n");
        free(nuevo);
        return;
    }

    nuevo->id = registro->siguienteId++;
    nuevo->pesoTotal = nuevo->pesoVacio + nuevo->pesoCarga;
    nuevo->anterior = registro->fin;
    nuevo->siguiente = NULL;

    if (registro->fin == NULL) {
        registro->inicio = nuevo;
    } else {
        registro->fin->siguiente = nuevo;
    }
    registro->fin = nuevo;

    printf("Contenedor registrado con ID %d.\n", nuevo->id);
}

static void buscar(struct Registro *registro) {
    int id;
    struct Contenedor *contenedor;

    printf("Ingrese el ID del contenedor: ");
    if (scanf("%d", &id) != 1) {
        limpiarEntrada();
        printf("Error: ID invalido.\n");
        return;
    }

    contenedor = buscarPorId(registro, id);
    if (contenedor == NULL) {
        printf("Contenedor no encontrado.\n");
    } else {
        mostrarContenedor(contenedor);
    }
}

static void actualizar(struct Registro *registro) {
    int id;
    float pesoVacio;
    float pesoCarga;
    float precio;
    struct Contenedor *contenedor;

    printf("Ingrese el ID del contenedor a actualizar: ");
    if (scanf("%d", &id) != 1) {
        limpiarEntrada();
        printf("Error: ID invalido.\n");
        return;
    }

    contenedor = buscarPorId(registro, id);
    if (contenedor == NULL) {
        printf("Contenedor no encontrado.\n");
        return;
    }

    printf("Nuevo peso vacio (tara): ");
    if (scanf("%f", &pesoVacio) != 1) {
        limpiarEntrada();
        printf("Error: dato invalido.\n");
        return;
    }

    printf("Nuevo peso de carga: ");
    if (scanf("%f", &pesoCarga) != 1) {
        limpiarEntrada();
        printf("Error: dato invalido.\n");
        return;
    }

    printf("Nuevo precio o costo: ");
    if (scanf("%f", &precio) != 1) {
        limpiarEntrada();
        printf("Error: dato invalido.\n");
        return;
    }

    if (pesoVacio < 0 || pesoCarga < 0 || precio < 0) {
        printf("Error: los valores deben ser no negativos.\n");
        return;
    }

    contenedor->pesoVacio = pesoVacio;
    contenedor->pesoCarga = pesoCarga;
    contenedor->pesoTotal = pesoVacio + pesoCarga;
    contenedor->precio = precio;

    printf("Contenedor actualizado.\n");
    mostrarContenedor(contenedor);
}

static void eliminar(struct Registro *registro) {
    int id;
    struct Contenedor *eliminar;

    printf("Ingrese el ID del contenedor a eliminar: ");
    if (scanf("%d", &id) != 1) {
        limpiarEntrada();
        printf("Error: ID invalido.\n");
        return;
    }

    eliminar = buscarPorId(registro, id);
    if (eliminar == NULL) {
        printf("Contenedor no encontrado.\n");
        return;
    }

    if (eliminar->anterior == NULL) {
        registro->inicio = eliminar->siguiente;
    } else {
        eliminar->anterior->siguiente = eliminar->siguiente;
    }

    if (eliminar->siguiente == NULL) {
        registro->fin = eliminar->anterior;
    } else {
        eliminar->siguiente->anterior = eliminar->anterior;
    }

    printf("Contenedor con ID %d eliminado.\n", eliminar->id);
    free(eliminar);
}

static void recorrerAdelante(const struct Registro *registro) {
    const struct Contenedor *actual;

    if (registro->inicio == NULL) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    printf("\nRecorrido desde el inicio:\n");
    actual = registro->inicio;
    while (actual != NULL) {
        mostrarContenedor(actual);
        actual = actual->siguiente;
    }
}

static void recorrerAtras(const struct Registro *registro) {
    const struct Contenedor *actual;

    if (registro->fin == NULL) {
        printf("No hay contenedores registrados.\n");
        return;
    }

    printf("\nRecorrido desde el final:\n");
    actual = registro->fin;
    while (actual != NULL) {
        mostrarContenedor(actual);
        actual = actual->anterior;
    }
}

static void liberarRegistro(struct Registro *registro) {
    struct Contenedor *actual = registro->inicio;

    while (actual != NULL) {
        struct Contenedor *eliminar = actual;
        actual = actual->siguiente;
        free(eliminar);
    }

    registro->inicio = NULL;
    registro->fin = NULL;
}

static int leerOpcion(void) {
    int opcion;

    if (scanf("%d", &opcion) != 1) {
        limpiarEntrada();
        return -1;
    }
    return opcion;
}

int main(void) {
    struct Registro registro = {NULL, NULL, 1};
    int opcion;

    do {
        printf("\n=== SISTEMA DE GESTION DE CONTENEDORES ===\n");
        printf("1. Insertar contenedor\n");
        printf("2. Buscar contenedor\n");
        printf("3. Actualizar contenedor\n");
        printf("4. Eliminar contenedor\n");
        printf("5. Recorrer hacia adelante\n");
        printf("6. Recorrer hacia atras\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");

        opcion = leerOpcion();

        switch (opcion) {
            case 1:
                insertar(&registro);
                break;
            case 2:
                buscar(&registro);
                break;
            case 3:
                actualizar(&registro);
                break;
            case 4:
                eliminar(&registro);
                break;
            case 5:
                recorrerAdelante(&registro);
                break;
            case 6:
                recorrerAtras(&registro);
                break;
            case 0:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 0);

    liberarRegistro(&registro);
    return 0;
}
