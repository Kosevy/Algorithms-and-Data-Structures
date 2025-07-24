#pragma once
#include "Utilidades.h"

template <typename T>
struct Nodo {
    T valor;
    Nodo* siguiente;

    Nodo(const T& val) : valor(val), siguiente(nullptr) {}
};