#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Contenedor {
    int id;
    float pesoVacio;
    float pesoCarga;
    float pesoTotal;
    float precio;
    Contenedor* anterior;
    Contenedor* siguiente;
};

class RegistroContenedores {
private:
    Contenedor* inicio;
    Contenedor* fin;
    int siguienteId;

    Contenedor* buscarPorId(int id) const {
        Contenedor* actual = inicio;
        while (actual != nullptr) {
            if (actual->id == id) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

    void mostrarContenedor(const Contenedor* contenedor) const {
        cout << "\nID: " << contenedor->id << '\n';
        cout << "Peso vacio (tara): " << contenedor->pesoVacio << '\n';
        cout << "Peso de carga: " << contenedor->pesoCarga << '\n';
        cout << "Peso total: " << contenedor->pesoTotal << '\n';
        cout << "Precio/costo: " << contenedor->precio << '\n';
    }

public:
    RegistroContenedores() : inicio(nullptr), fin(nullptr), siguienteId(1) {}

    ~RegistroContenedores() {
        Contenedor* actual = inicio;
        while (actual != nullptr) {
            Contenedor* eliminar = actual;
            actual = actual->siguiente;
            delete eliminar;
        }
    }

    void insertar() {
        float pesoVacio;
        float pesoCarga;
        float precio;

        cout << "Peso vacio (tara): ";
        cin >> pesoVacio;
        cout << "Peso de carga: ";
        cin >> pesoCarga;
        cout << "Precio/costo: ";
        cin >> precio;

        if (cin.fail() || pesoVacio < 0.0f || pesoCarga < 0.0f || precio < 0.0f) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: los valores deben ser numeros no negativos.\n";
            return;
        }

        Contenedor* nuevo = new Contenedor{
            siguienteId++, pesoVacio, pesoCarga,
            pesoVacio + pesoCarga, precio, fin, nullptr
        };

        if (fin == nullptr) {
            inicio = nuevo;
        } else {
            fin->siguiente = nuevo;
        }
        fin = nuevo;

        cout << "Contenedor registrado con ID " << nuevo->id << ".\n";
    }

    void buscar() const {
        int id;
        cout << "Ingrese el ID del contenedor: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ID invalido.\n";
            return;
        }

        Contenedor* contenedor = buscarPorId(id);
        if (contenedor == nullptr) {
            cout << "Contenedor no encontrado.\n";
            return;
        }

        mostrarContenedor(contenedor);
    }

    void actualizar() {
        int id;
        cout << "Ingrese el ID del contenedor a actualizar: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ID invalido.\n";
            return;
        }

        Contenedor* contenedor = buscarPorId(id);
        if (contenedor == nullptr) {
            cout << "Contenedor no encontrado.\n";
            return;
        }

        float pesoVacio;
        float pesoCarga;
        float precio;

        cout << "Nuevo peso vacio (tara): ";
        cin >> pesoVacio;
        cout << "Nuevo peso de carga: ";
        cin >> pesoCarga;
        cout << "Nuevo precio/costo: ";
        cin >> precio;

        if (cin.fail() || pesoVacio < 0.0f || pesoCarga < 0.0f || precio < 0.0f) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: los valores deben ser numeros no negativos.\n";
            return;
        }

        contenedor->pesoVacio = pesoVacio;
        contenedor->pesoCarga = pesoCarga;
        contenedor->pesoTotal = pesoVacio + pesoCarga;
        contenedor->precio = precio;

        cout << "Contenedor actualizado.\n";
        mostrarContenedor(contenedor);
    }

    void eliminar() {
        int id;
        cout << "Ingrese el ID del contenedor a eliminar: ";
        cin >> id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: ID invalido.\n";
            return;
        }

        Contenedor* eliminar = buscarPorId(id);
        if (eliminar == nullptr) {
            cout << "Contenedor no encontrado.\n";
            return;
        }

        if (eliminar->anterior != nullptr) {
            eliminar->anterior->siguiente = eliminar->siguiente;
        } else {
            inicio = eliminar->siguiente;
        }

        if (eliminar->siguiente != nullptr) {
            eliminar->siguiente->anterior = eliminar->anterior;
        } else {
            fin = eliminar->anterior;
        }

        cout << "Contenedor con ID " << eliminar->id << " eliminado.\n";
        delete eliminar;
    }

    void recorrerHaciaAdelante() const {
        if (inicio == nullptr) {
            cout << "No hay contenedores registrados.\n";
            return;
        }

        cout << "\nRecorrido desde el inicio:\n";
        for (Contenedor* actual = inicio; actual != nullptr; actual = actual->siguiente) {
            mostrarContenedor(actual);
        }
    }

    void recorrerHaciaAtras() const {
        if (fin == nullptr) {
            cout << "No hay contenedores registrados.\n";
            return;
        }

        cout << "\nRecorrido desde el final:\n";
        for (Contenedor* actual = fin; actual != nullptr; actual = actual->anterior) {
            mostrarContenedor(actual);
        }
    }
};

int leerOpcion() {
    int opcion;
    cin >> opcion;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return opcion;
}

int main() {
    RegistroContenedores registro;
    int opcion;

    do {
        cout << "\n=== SISTEMA DE GESTION DE CONTENEDORES ===\n";
        cout << "1. Insertar contenedor\n";
        cout << "2. Buscar contenedor\n";
        cout << "3. Actualizar contenedor\n";
        cout << "4. Eliminar contenedor\n";
        cout << "5. Recorrer hacia adelante\n";
        cout << "6. Recorrer hacia atras\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        opcion = leerOpcion();

        switch (opcion) {
            case 1: registro.insertar(); break;
            case 2: registro.buscar(); break;
            case 3: registro.actualizar(); break;
            case 4: registro.eliminar(); break;
            case 5: registro.recorrerHaciaAdelante(); break;
            case 6: registro.recorrerHaciaAtras(); break;
            case 0: cout << "Programa finalizado.\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);

    return 0;
}
