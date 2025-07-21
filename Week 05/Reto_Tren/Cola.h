#pragma once
#include "Nodo.h"

template<class T>
class Cola {
private:
    Nodo<T>* frente;
    Nodo<T>* final;
public:
    Cola() : frente(nullptr), final(nullptr) {}

    void encolar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (estaVacia()) frente = final = nuevo;
        else final->siguiente = nuevo, final = nuevo;
    }

    bool desencolar(T & valor) {
        if (estaVacia()) return false;
        valor = frente->dato;
        Nodo<T>* temp = frente;
        frente = frente->siguiente;
        delete temp;
        if (frente == nullptr) final = nullptr;
        return true;
    }

    bool estaVacia() { return frente == nullptr; }

    bool verFrente(T& valor) {
        if (estaVacia()) return false;
        valor = frente->dato;
        return true;
    }
};