#pragma once
#include "Utilidades.h"

template <typename T>
class ListaEnlazada {
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& d) : dato(d), siguiente(nullptr) {}
    };
    Nodo* cabeza;
    int tamano;
public:
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}
    ~ListaEnlazada() { limpiar(); }
    
    void insertar(const T& dato) { //O(n)
        Nodo* nuevo = new Nodo(dato);
        if (!cabeza) cabeza = nuevo;
        else {
            Nodo* tmp = cabeza;
            while (tmp->siguiente) tmp = tmp->siguiente;
            tmp->siguiente = nuevo;
        }
        tamano++;
    }
    // Buscar usando lambda
    T* buscar(function<bool(const T&)> criterio) { //O(n)
        Nodo* tmp = cabeza;
        while (tmp) {
            if (criterio(tmp->dato)) return &(tmp->dato);
            tmp = tmp->siguiente;
        }
        return nullptr;
    }
    // Eliminar usando lambda
    bool eliminar(function<bool(const T&)> criterio) { //O(n)
        Nodo* tmp = cabeza;
        Nodo* prev = nullptr;
        while (tmp) {
            if (criterio(tmp->dato)) {
                if (prev) prev->siguiente = tmp->siguiente;
                else cabeza = tmp->siguiente;
                delete tmp;
                tamano--;
                return true;
            }
            prev = tmp;
            tmp = tmp->siguiente;
        }
        return false;
    }
    // Ordenar por criterio (burbuja)
    void ordenar(function<bool(const T&, const T&)> comparar) { //O(n^2)
        if (!cabeza || !cabeza->siguiente) return;
        bool cambiado;
        do {
            cambiado = false;
            Nodo* actual = cabeza;
            while (actual->siguiente) {
                if (comparar(actual->siguiente->dato, actual->dato)) {
                    swap(actual->dato, actual->siguiente->dato);
                    cambiado = true;
                }
                actual = actual->siguiente;
            }
        } while (cambiado);
    }
    // Recorrer y aplicar function
    void recorrer(function<void(const T&)> accion) const { //O(n)
        Nodo* tmp = cabeza;
        while (tmp) {
            accion(tmp->dato);
            tmp = tmp->siguiente;
        }
    }
    void limpiar() { //O(n)
        Nodo* tmp = cabeza;
        while (tmp) {
            Nodo* borrar = tmp;
            tmp = tmp->siguiente;
            delete borrar;
        }
        cabeza = nullptr;
        tamano = 0;
    }
    int size() const { return tamano; }
};