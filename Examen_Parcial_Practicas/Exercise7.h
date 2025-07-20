#pragma once
#include "Utilidades.h"

template <typename T>
struct Nodo4 {
    T valor;
    Nodo4* siguiente;

    Nodo4(const T& val) : valor(val), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada2 {
private:
    Nodo4<T>* cabeza;
    Nodo4<T>* actual;
public:
    ListaEnlazada2() : cabeza(nullptr), actual(nullptr) {}
    ~ListaEnlazada2() {
        Nodo4<T>* temp = cabeza;
        while (temp != nullptr) {
            Nodo4<T>* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
    }

    void insertar(const T& val) {
        Nodo4<T>* nuevoNodo = new Nodo4<T>(val);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            actual = cabeza;
        }
        else {
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }
    }

    void mostrar() {
        Nodo4<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->siguiente;
        }
        cout << endl;
        cin.ignore();
    }

    void invertir() {
        if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

        Nodo4<T>* prev = nullptr;
        Nodo4<T>* current = cabeza;
        Nodo4<T>* next = nullptr;

        while (current != nullptr) {
            next = current->siguiente;
            current->siguiente = prev;
            prev = current;
            current = next;
        }
        cabeza = prev;
    }
};

void pregunta7() {
    ListaEnlazada2<int> lista;
    int n, valor;
    int op7;

    do {
        Console::Clear();
        cout << "\n=== Lista Enlazada ===" << endl;
        cout << "1. Insertar elementos" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Invertir lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op7;
		cin.ignore();
        switch (op7) {
            case 1:
                cout << "Ingrese la cantidad de elementos: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Valor " << i + 1 << ": ";
                    cin >> valor;
                    lista.insertar(valor);
                }
                break;
            case 2:
                cout << "Lista actual: ";
                lista.mostrar();
                break;
            case 3:
                lista.invertir();
                cout << "Lista invertida: ";
                lista.mostrar();
                break;
            case 4:
				cout << "Volviendo al menu principal..." << endl;
                cin.ignore();
                break;
            default:
                cout << "Error, intente de nuevo" << endl;
        }
    } while (op7 != 4);
}