#pragma once
#include "NodoPilasColas.h"

template <typename T>
class PilaPilasColas {
private:
    NodoPilasColas<T>* tope;

public:
    PilaPilasColas() {
        tope = nullptr;
    }

    ~PilaPilasColas() {
        while (!estaVacia()) {
            pop();
        }
    }

    bool estaVacia() {
        return (tope == nullptr);
    }

    void push(T valor) {
        if (estaVacia()) {
            tope = new NodoPilasColas<T>(valor);
        }
        else {
            tope = new NodoPilasColas<T>(valor, tope);
        }
    }

    T pop() {
        if (estaVacia()) {
            return T();
        }
        else {
            T elemento = tope->dato;
            NodoPilasColas<T>* temp = tope;
            tope = tope->siguiente;
            delete temp;
            return elemento;
        }
    }
};