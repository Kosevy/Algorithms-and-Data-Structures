#ifndef __BSTVentas_HPP__
#define __BSTVentas_HPP__
#include "Utilidades.h"

template<typename T>
class BSTVentas {
private:
    struct Nodo {
        T dato;
        Nodo* izq;
        Nodo* der;
        Nodo(const T& d) : dato(d), izq(nullptr), der(nullptr) {}
    };
    Nodo* raiz;

    void insertar(Nodo*& nodo, const T& dato) {
        if (!nodo) {
            nodo = new Nodo(dato);
        }
        else if (dato.getEdad() < nodo->dato.getEdad()) {
            insertar(nodo->izq, dato);
        }
        else {
            insertar(nodo->der, dato);
        }
    }

    void enOrden(Nodo* nodo) const {
        if (!nodo) return;
        enOrden(nodo->izq);
        std::cout << nodo->dato.toString();
        enOrden(nodo->der);
    }
public:
    BSTVentas() : raiz(nullptr) {}
    void insertar(const T& dato) { insertar(raiz, dato); }
    void enOrden() const { enOrden(raiz); }
};

#endif
