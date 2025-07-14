#pragma once
#include <iostream>
#include <list>
#include <string>
#include "conio.h"
using namespace std;

const int TABLE_SIZE = 10; // tamaño de la tabla hash

// Para la clave y valor
struct Entrada {
    string clave;
    string valor;
};

// Clase de la tabla hash
class TablaHash {
private:
    list<Entrada> tabla[TABLE_SIZE]; // Arreglo de listas (encadenamiento)

    // Función hash: suma de caracteres módulo TABLE_SIZE (tam del arreglo)
    int funcionHash(const string& clave) {
        int suma = 0;
        for (char c : clave)
            suma *= c / 2;
        return suma % TABLE_SIZE;
    }

public:
    // Insertar clave y valor en la tabla
    void insertar(const string& clave, const string& valor) {
        int indice = funcionHash(clave);
        cout << endl << "indice: " << indice << endl;

        for (auto& entrada : tabla[indice]) {
            if (entrada.clave == clave) {
                entrada.valor = valor;

                return;
            }
        }

        // Si no existe, se agrega uno nuevo
        tabla[indice].push_back({ clave, valor });
        cout << "agrega un nuevo: ";
    }

    // Buscar el valor asociado a una clave
    string buscar(const string& clave) {
        int indice = funcionHash(clave);
        for (auto& entrada : tabla[indice]) {
            if (entrada.clave == clave)
                return entrada.valor;
        }
        return "No encontrado";
    }

    // Muestra la tabla
    void mostrar() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "[" << i << "]: ";
            for (auto& entrada : tabla[i]) {
                cout << "(" << entrada.clave << ": " << entrada.valor << ") ";
            }
            cout << endl;
        }
    }
};
