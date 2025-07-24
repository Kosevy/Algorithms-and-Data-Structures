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
            suma += c;
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

int main() {
    TablaHash agenda;

    // Insertamos contactos
    agenda.insertar("Carlos", "1234");
    agenda.insertar("Ana", "5678");
    agenda.insertar("Luis", "9101");
    agenda.insertar("Lucia", "1122");
    agenda.insertar("Edson", "4564");
    agenda.insertar("Lucas", "1254");
    agenda.insertar("Jorge", "9874");
    agenda.insertar("Pedro", "3846");
    agenda.insertar("Virginia", "1648");
    agenda.insertar("Carmen", "9748");
    agenda.insertar("Piero", "1936");
    agenda.insertar("Lupe", "9753");
    agenda.insertar("Mary", "4613");



    // muestra toda la tabla
    cout << "\nContenido de la tabla hash:\n";
    agenda.mostrar();

    //Se busca algun contacto
    cout << "Número de Ana: " << agenda.buscar("Ana") << endl;
    cout << "Número de Luis: " << agenda.buscar("Luis") << endl;
    cout << "Número de Lucas: " << agenda.buscar("Peter") << endl; // no existe

    system("pause>0");
    return 0;
}
