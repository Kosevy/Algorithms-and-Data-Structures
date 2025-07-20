#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Template para encontrar la moda de un arreglo
template <typename T>
vector<T> encontrarModa(const T arr[], int tamaño) {
    unordered_map<T, int> frecuencia;
    vector<T> modas;
    int maxFrecuencia = 0;

    // Contar la frecuencia de cada elemento
    for (int i = 0; i < tamaño; ++i) {
        frecuencia[arr[i]]++;
        if (frecuencia[arr[i]] > maxFrecuencia) {
            maxFrecuencia = frecuencia[arr[i]];
        }
    }

    // Encontrar todos los elementos con la máxima frecuencia
    for (const auto& par : frecuencia) {
        if (par.second == maxFrecuencia) {
            modas.push_back(par.first);
        }
    }

    return modas;
}

int main() {
    // Ejemplo con enteros
    int arregloEnteros[] = { 1, 2, 2, 3, 4, 4, 4, 5 };
    int tamañoEnteros = sizeof(arregloEnteros) / sizeof(arregloEnteros[0]);

    vector<int> modasEnteros = encontrarModa(arregloEnteros, tamañoEnteros);

    cout << "Moda(s) en enteros: ";
    for (int moda : modasEnteros) {
        cout << moda << " ";
    }
    cout << endl;

    // Ejemplo con caracteres
    char arregloChars[] = { 'a', 'b', 'b', 'c', 'c', 'd' };
    int tamañoChars = sizeof(arregloChars) / sizeof(arregloChars[0]);

    vector<char> modasChars = encontrarModa(arregloChars, tamañoChars);

    cout << "Moda(s) en caracteres: ";
    for (char moda : modasChars) {
        cout << moda << " ";
    }
    cout << endl;

    system("pause>0");
    return 0;
}