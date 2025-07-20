#pragma once
#include "NodoPilasColas.h"

template <typename T>
class ColaPilasColas {
private:
    NodoPilasColas<T>* inicio;
    NodoPilasColas<T>* fin;

public:
    ColaPilasColas() {
        inicio = nullptr;
        fin = nullptr;
    }

    ~ColaPilasColas() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    bool estaVacia() {
        return (inicio == nullptr);
    }

    void encolar(T valor) {
        NodoPilasColas<T>* nuevoNodo = new NodoPilasColas<T>(valor);
        if (estaVacia()) {
            inicio = nuevoNodo;
            fin = nuevoNodo;
        }
        else {
            fin->siguiente = nuevoNodo;
            fin = nuevoNodo;
        }
    }

    T desencolar() {
        if (estaVacia()) {
            return T(); // Retorna un valor por defecto para el tipo T
        }
        T dato = inicio->dato;
        NodoPilasColas<T>* temp = inicio;
        if (inicio == fin) {
            inicio = nullptr;
            fin = nullptr;
        }
        else {
            inicio = inicio->siguiente;
        }
        delete temp;
        return dato;
    }
};