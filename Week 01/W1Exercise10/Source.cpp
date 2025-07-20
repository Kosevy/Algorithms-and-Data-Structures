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

// Función para contar repeticiones de un elemento
template <typename T>
int contarRepeticiones(T arr[], int tamaño, T elemento) {
    int contador = 0;
    for (int i = 0; i < tamaño; i++) {
        if (arr[i] == elemento) {
            contador++;
        }
    }
    return contador;
}

// Función para buscar un elemento
template <typename T>
void buscarElemento(T arr[], int tamaño) {
    T elemento;
    cout << "Ingrese el elemento a buscar: ";
    cin >> elemento;

    int repeticiones = contarRepeticiones(arr, tamaño, elemento);

    if (repeticiones > 0) {
        cout << "El elemento " << elemento << " aparece " << repeticiones << " veces." << endl;
        cout << "Posiciones: ";
        for (int i = 0; i < tamaño; i++) {
            if (arr[i] == elemento) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    else {
        cout << "El elemento " << elemento << " no existe en el arreglo." << endl;
    }
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
        cout << "2. Contar repeticiones de elemento" << endl;
        cout << "3. Buscar posiciones de elemento" << endl;
        cout << "4. Eliminar elemento" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case '1':
            mostrarArreglo(datos, d);
            break;

        case '2': {
            int elemento;
            cout << "Ingrese el elemento a contar: ";
            cin >> elemento;
            int repeticiones = contarRepeticiones(datos, d, elemento);
            cout << "El elemento " << elemento << " aparece " << repeticiones << " veces." << endl;
            break;
        }

        case '3':
            buscarElemento(datos, d);
            break;

        case '4':
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

        case '5':
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida!" << endl;
        }
    } while (opcion != '5' && d > 0);

    delete[] datos;
    system("pause>0");
    return 0;
}