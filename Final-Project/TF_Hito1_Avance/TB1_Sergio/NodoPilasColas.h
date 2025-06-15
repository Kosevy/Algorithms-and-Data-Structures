#pragma once

template <typename T>
class NodoPilasColas {
public:
    T dato;
    NodoPilasColas<T>* siguiente;

    // Constructor
    NodoPilasColas(T valor, NodoPilasColas<T>* sig = nullptr) {
        dato = valor;
        siguiente = sig;
    }
};