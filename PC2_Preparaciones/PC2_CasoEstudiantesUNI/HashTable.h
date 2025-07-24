#pragma once
#include "Utilidades.h"

const int TABLE_SIZE = 151; // tamano de la tabla hash

// Para las claves y valor
struct Entrada {
    int clave1;
    int clave2;
    int valor;
};

// Clase de la tabla hash
class TablaHash {
private:
    list<Entrada> tabla[TABLE_SIZE]; // Arreglo de listas (encadenamiento)

    // Funcion hash: multiplicacion de claves con numeros primos TABLE_SIZE (tam del arreglo)
    int funcionHash(int clave1, int clave2) {
        return (clave1 * 31 + clave2 * 17) % TABLE_SIZE;
    }

public:
    // Insertar claves y valor en la tabla
    void insertar(int clave1, int clave2, int valor) {
        int indice = funcionHash(clave1, clave2);

        for (auto& entrada : tabla[indice]) {
            if (entrada.clave1 == clave1 && entrada.clave2 == clave2) {
                entrada.valor = valor;
                return;
            }
        }

        tabla[indice].push_back({ clave1, clave2, valor });
    }


    // Buscar el valor asociado a una clave
    int buscar(int clave1, int clave2) {
        int indice = funcionHash(clave1, clave2);
        for (auto& entrada : tabla[indice]) {
            if (entrada.clave1 == clave2 || entrada.clave2 == clave2)
                return entrada.valor;
        }
        return -1;
    }

    // Muestra la tabla
    void mostrar() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "[" << i << "]: ";
            for (auto& entrada : tabla[i]) {
                cout << "(" << entrada.clave1 << " " << entrada.clave2 << ": " << entrada.valor << ") ";
            }
            cout << endl;
        }
    }
};

/*int main() {

    //Se busca algun contacto
    cout << "Numero de Ana: " << agenda.buscar("Ana") << endl;
    cout << "Numero de Luis: " << agenda.buscar("Luis") << endl;
    cout << "Numero de Lucas: " << agenda.buscar("Peter") << endl; // no existe

    system("pause>0");
    return 0;
}
*/