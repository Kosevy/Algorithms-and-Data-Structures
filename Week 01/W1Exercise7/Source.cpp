#include <iostream>
#include <stdexcept> // Para manejo de excepciones

using namespace std;

// Función para mostrar el arreglo
template <typename T>
void mostrarArreglo(T arr[], int tamaño) {
    cout << "\nArreglo ingresado:" << endl;
    cout << "[";
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i];
        if (i < tamaño - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Función para eliminar un elemento en una posición específica
template <typename T>
void eliminarElemento(T*& arr, int& tamaño, int posicion) {
    // Validar posición
    if (posicion < 0 || posicion >= tamaño) {
        throw out_of_range("Posicion fuera de rango");
    }

    // Crear nuevo arreglo con tamaño reducido
    T* nuevoArreglo = new T[tamaño - 1];

    // Copiar elementos antes de la posición
    for (int i = 0; i < posicion; i++) {
        nuevoArreglo[i] = arr[i];
    }

    // Copiar elementos después de la posición
    for (int i = posicion; i < tamaño - 1; i++) {
        nuevoArreglo[i] = arr[i + 1];
    }

    // Liberar memoria del arreglo antiguo
    delete[] arr;

    // Actualizar arreglo y tamaño
    arr = nuevoArreglo;
    tamaño--;
}

int main() {
    int d;
    cout << "Ingresa la cantidad de datos numericos: ";
    cin >> d;

    int* datos = new int[d]; // Creación de arreglo dinámico

    cout << "\nIngrese datos numericos:" << endl;
    for (int i = 0; i < d; i++) {
        cout << "Dato nro. " << i + 1 << ": ";
        cin >> datos[i];
    }

    // Mostrar el arreglo completo
    mostrarArreglo(datos, d);

    // Opción para eliminar elementos
    char opcion;
    do {
        cout << "\nDesea eliminar un elemento? (s/n): ";
        cin >> opcion;

        if (tolower(opcion) == 's') {
            int posicion;
            cout << "Ingrese la posicion a eliminar (0-" << d - 1 << "): ";
            cin >> posicion;

            try {
                eliminarElemento(datos, d, posicion);

                // Mostrar arreglo actualizado
                mostrarArreglo(datos, d);
            }
            catch (const out_of_range& e) {
                cerr << "\nError: " << e.what() << endl;
            }
        }
    } while (tolower(opcion) == 's' && d > 0);

    if (d == 0) {
        cout << "\nEl arreglo esta vacio." << endl;
    }

    delete[] datos;
    system("pause>0");
    return 0;
}