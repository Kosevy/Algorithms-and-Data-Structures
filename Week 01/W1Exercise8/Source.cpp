#include <iostream>
#include <stdexcept> // Para manejo de excepciones

using namespace std;

// Función para mostrar el arreglo
template <typename T>
void mostrarArreglo(T arr[], int tamaño) {
    cout << "\nArreglo actual:" << endl;
    cout << "[";
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i];
        if (i < tamaño - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Función para buscar un elemento
template <typename T>
void buscarElemento(T arr[], int tamaño) {
    T elemento;
    bool encontrado = false;

    cout << "Ingrese el elemento a buscar: ";
    cin >> elemento;

    cout << "El elemento " << elemento << " se encuentra en las posiciones: ";
    for (int i = 0; i < tamaño; i++) {
        if (arr[i] == elemento) {
            cout << i << " ";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontro el elemento";
    }
    cout << endl;
}

// Función para eliminar un elemento en una posición específica
template <typename T>
void eliminarElemento(T*& arr, int& tamaño, int posicion) {
    if (posicion < 0 || posicion >= tamaño) {
        throw out_of_range("Posicion fuera de rango");
    }

    T* nuevoArreglo = new T[tamaño - 1];

    for (int i = 0; i < posicion; i++) {
        nuevoArreglo[i] = arr[i];
    }

    for (int i = posicion; i < tamaño - 1; i++) {
        nuevoArreglo[i] = arr[i + 1];
    }

    delete[] arr;
    arr = nuevoArreglo;
    tamaño--;
}

int main() {
    int d;
    cout << "Ingresa la cantidad de datos numericos: ";
    cin >> d;

    int* datos = new int[d];

    cout << "\nIngrese datos numericos:" << endl;
    for (int i = 0; i < d; i++) {
        cout << "Dato nro. " << i + 1 << ": ";
        cin >> datos[i];
    }

    mostrarArreglo(datos, d);

    char opcion;
    do {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Mostrar arreglo" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Eliminar elemento" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            mostrarArreglo(datos, d);
            break;

        case '2':
            buscarElemento(datos, d);
            break;

        case '3':
            if (d == 0) {
                cout << "El arreglo esta vacio." << endl;
                break;
            }
            int posicion;
            cout << "Ingrese la posicion a eliminar (0-" << d - 1 << "): ";
            cin >> posicion;
            try {
                eliminarElemento(datos, d, posicion);
                mostrarArreglo(datos, d);
            }
            catch (const out_of_range& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;

        case '4':
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida!" << endl;
        }
    } while (opcion != '4' && d > 0);

    delete[] datos;
    system("pause>0");
    return 0;
}