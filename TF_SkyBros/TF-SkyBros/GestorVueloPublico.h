#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Estructura de vuelo para vista pública
struct VueloPublico {
    string origen;
    string destino;
    string aerolinea;
    double precio;
    string fecha;
    string hora;

    VueloPublico() {}
    VueloPublico(string o, string d, string a, double p, string f, string h)
        : origen(o), destino(d), aerolinea(a), precio(p), fecha(f), hora(h) {}

    // Ordenar por fecha y luego por origen
    bool operator<(const VueloPublico& otro) const {
        if (fecha != otro.fecha) return fecha < otro.fecha;
        return origen < otro.origen;
    }
    bool operator>(const VueloPublico& otro) const {
        if (fecha != otro.fecha) return fecha > otro.fecha;
        return origen > otro.origen;
    }
};

// Nodo AVL
struct NodoAVLVueloPublico {
    VueloPublico vuelo;
    NodoAVLVueloPublico* izq;
    NodoAVLVueloPublico* der;
    int altura;
    NodoAVLVueloPublico(const VueloPublico& v) : vuelo(v), izq(nullptr), der(nullptr), altura(1) {}
};

// Árbol AVL para vuelos públicos
class AVLVuelosPublicos {
private:
    NodoAVLVueloPublico* raiz;

    int altura(NodoAVLVueloPublico* n) { return n ? n->altura : 0; }
    int balance(NodoAVLVueloPublico* n) { return n ? altura(n->izq) - altura(n->der) : 0; }
    void actualizarAltura(NodoAVLVueloPublico* n) {
        n->altura = 1 + max(altura(n->izq), altura(n->der));
    }
    NodoAVLVueloPublico* rotarDerecha(NodoAVLVueloPublico* y) {
        NodoAVLVueloPublico* x = y->izq;
        NodoAVLVueloPublico* T2 = x->der;
        x->der = y;
        y->izq = T2;
        actualizarAltura(y);
        actualizarAltura(x);
        return x;
    }
    NodoAVLVueloPublico* rotarIzquierda(NodoAVLVueloPublico* x) {
        NodoAVLVueloPublico* y = x->der;
        NodoAVLVueloPublico* T2 = y->izq;
        y->izq = x;
        x->der = T2;
        actualizarAltura(x);
        actualizarAltura(y);
        return y;
    }
    NodoAVLVueloPublico* insertar(NodoAVLVueloPublico* nodo, const VueloPublico& vuelo) {
        if (!nodo) return new NodoAVLVueloPublico(vuelo);
        if (vuelo < nodo->vuelo)
            nodo->izq = insertar(nodo->izq, vuelo);
        else if (vuelo > nodo->vuelo)
            nodo->der = insertar(nodo->der, vuelo);
        else
            return nodo;
        actualizarAltura(nodo);
        int bal = balance(nodo);
        if (bal > 1 && vuelo < nodo->izq->vuelo)
            return rotarDerecha(nodo);
        if (bal < -1 && vuelo > nodo->der->vuelo)
            return rotarIzquierda(nodo);
        if (bal > 1 && vuelo > nodo->izq->vuelo) {
            nodo->izq = rotarIzquierda(nodo->izq);
            return rotarDerecha(nodo);
        }
        if (bal < -1 && vuelo < nodo->der->vuelo) {
            nodo->der = rotarDerecha(nodo->der);
            return rotarIzquierda(nodo);
        }
        return nodo;
    }
    void inorden(NodoAVLVueloPublico* nodo, vector<VueloPublico>& vuelos) {
        if (!nodo) return;
        inorden(nodo->izq, vuelos);
        vuelos.push_back(nodo->vuelo);
        inorden(nodo->der, vuelos);
    }
public:
    AVLVuelosPublicos() : raiz(nullptr) {}

    void agregarVuelo(const VueloPublico& vuelo) {
        raiz = insertar(raiz, vuelo);
    }

    vector<VueloPublico> obtenerVuelos() {
        vector<VueloPublico> vuelos;
        inorden(raiz, vuelos);
        return vuelos;
    }

    void mostrarVuelos() {
        Console::Clear();
		Console::SetCursorPosition(35, 2);
        vector<VueloPublico> vuelos = obtenerVuelos();
        cout << "=== LISTA DE VUELOS DISPONIBLES ===" << endl;
        cout << "-----------------------------------" << endl;
        for (size_t i = 0; i < vuelos.size(); ++i) {
            cout << (i + 1) << ". " << vuelos[i].origen << " -> " << vuelos[i].destino
                << " | " << vuelos[i].aerolinea << " | $" << vuelos[i].precio
                << " | " << vuelos[i].fecha << " " << vuelos[i].hora << endl;
        }
        if (vuelos.empty()) {
            cout << "No hay vuelos disponibles." << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};