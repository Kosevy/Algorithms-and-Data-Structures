#include <iostream>
#include <algorithm> // Para std::swap

using namespace std;

// Ordenar un arreglo

template <typename T>
int particion(T arr[], int inicio, int fin) {
    T pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[fin]);
    return i + 1;
}

// Template para el algoritmo QuickSort
template <typename T>
void quickSort(T arr[], int inicio, int fin) {
    if (inicio < fin) {
        int indicePivote = particion(arr, inicio, fin);
        quickSort(arr, inicio, indicePivote - 1);
        quickSort(arr, indicePivote + 1, fin);
    }
}

// Función wrapper para facilitar el uso
template <typename T>
void ordenarArreglo(T arr[], int tamaño) {
    quickSort(arr, 0, tamaño - 1);
}

// Función para imprimir un arreglo
template <typename T>
void imprimirArreglo(const T arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Ejemplo con enteros
    int arregloEnteros[] = { 5, 2, 9, 1, 5, 6 };
    int tamañoEnteros = sizeof(arregloEnteros) / sizeof(arregloEnteros[0]);

    cout << "Arreglo original (enteros): ";
    imprimirArreglo(arregloEnteros, tamañoEnteros);

    ordenarArreglo(arregloEnteros, tamañoEnteros);

    cout << "Arreglo ordenado (enteros): ";
    imprimirArreglo(arregloEnteros, tamañoEnteros);

    // Ejemplo con caracteres
    char arregloChars[] = { 'z', 'a', 'm', 'b', 'k' };
    int tamañoChars = sizeof(arregloChars) / sizeof(arregloChars[0]);

    cout << "\nArreglo original (caracteres): ";
    imprimirArreglo(arregloChars, tamañoChars);

    ordenarArreglo(arregloChars, tamañoChars);

    cout << "Arreglo ordenado (caracteres): ";
    imprimirArreglo(arregloChars, tamañoChars);

    // Ejemplo con números de punto flotante
    double arregloDoubles[] = { 3.14, 1.59, 2.65, 0.79, 1.41 };
    int tamañoDoubles = sizeof(arregloDoubles) / sizeof(arregloDoubles[0]);

    cout << "\nArreglo original (doubles): ";
    imprimirArreglo(arregloDoubles, tamañoDoubles);

    ordenarArreglo(arregloDoubles, tamañoDoubles);

    cout << "Arreglo ordenado (doubles): ";
    imprimirArreglo(arregloDoubles, tamañoDoubles);

    system("pause>0");
    return 0;
}