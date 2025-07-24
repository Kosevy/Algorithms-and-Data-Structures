#include <iostream>
#include <algorithm>
using namespace std;

class AVL {
private:
    struct Nodo {
        int dato;
        Nodo* izquierdo;
        Nodo* derecho;
        int altura;

        Nodo(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr), altura(1) {}
    };

    Nodo* raiz;

    // FUNCTION auxiliar para obtener altura
    int obtenerAltura(Nodo* nodo) {
        return nodo ? nodo->altura : 0;
    }

    // FUNCTION para calcular factor de balance
    int factorBalance(Nodo* nodo) {
        return nodo ? obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho) : 0;
    }

    // Actualizar altura de un nodo
    void actualizarAltura(Nodo* nodo) {
        if (nodo) {
            nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo),
                obtenerAltura(nodo->derecho));
        }
    }

    // ROTAR simple a la derecha
    Nodo* rotacionDerecha(Nodo* y) {
        Nodo* x = y->izquierdo;
        Nodo* T2 = x->derecho;

        x->derecho = y;
        y->izquierdo = T2;

        actualizarAltura(y);
        actualizarAltura(x);

        return x;
    }

    // ROTAR simple a la izquierda
    Nodo* rotacionIzquierda(Nodo* x) {
        Nodo* y = x->derecho;
        Nodo* T2 = y->izquierdo;

        y->izquierdo = x;
        x->derecho = T2;

        actualizarAltura(x);
        actualizarAltura(y);

        return y;
    }

    // Insertar nodo ( auxiliar recursiva)
    Nodo* insertar(Nodo* nodo, int dato) {
        if (!nodo) return new Nodo(dato);

        if (dato < nodo->dato) {
            nodo->izquierdo = insertar(nodo->izquierdo, dato);
        }
        else if (dato > nodo->dato) {
            nodo->derecho = insertar(nodo->derecho, dato);
        }
        else {
            return nodo; // No se permiten duplicados
        }

        actualizarAltura(nodo);

        int balance = factorBalance(nodo);

        // Casos de desbalance
        // Izquierda Izquierda
        if (balance > 1 && dato < nodo->izquierdo->dato) {
            return rotacionDerecha(nodo);
        }

        // Derecha Derecha
        if (balance < -1 && dato > nodo->derecho->dato) {
            return rotacionIzquierda(nodo);
        }

        // Izquierda Derecha
        if (balance > 1 && dato > nodo->izquierdo->dato) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            return rotacionDerecha(nodo);
        }

        // Derecha Izquierda
        if (balance < -1 && dato < nodo->derecho->dato) {
            nodo->derecho = rotacionDerecha(nodo->derecho);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    // recorrido inorden (datos)
    void inorden(Nodo* nodo) {
        if (nodo) {
            inorden(nodo->izquierdo);
            cout << nodo->dato << " ";
            inorden(nodo->derecho);
        }
    }

    //  recorrido inorden (alturas)
    void inordenAlturas(Nodo* nodo) {
        if (nodo) {
            inordenAlturas(nodo->izquierdo);
            cout << "Dato: " << nodo->dato << " | Altura: " << nodo->altura << endl;
            inordenAlturas(nodo->derecho);
        }
    }

    void mostrarEstructura(Nodo* nodo, int espacio = 0) {
        const int ESPACIADO = 4;
        if (!nodo) return;

        espacio += ESPACIADO;

        mostrarEstructura(nodo->derecho, espacio);

        cout << endl;
        for (int i = ESPACIADO; i < espacio; i++)
            cout << " ";
        cout << nodo->dato << "(" << nodo->altura << ")";

        mostrarEstructura(nodo->izquierdo, espacio);
    }

public:
    AVL() : raiz(nullptr) {}

    // Insertar valor (interfaz )
    void insertar(int dato) {
        raiz = insertar(raiz, dato);
    }

    // Recorrido inorden (interfaz )
    void imprimirInorden() {
        cout << "orden (valores): ";
        inorden(raiz);
        cout << endl;
    }

    // Recorrido inorden mostrando alturas (interfaz )
    void imprimirAlturas() {
        cout << " Inorden (alturas): " << endl;
        inordenAlturas(raiz);
    }


    void imprimirEstructura() {
        cout << "\nEstructura del arbol (dato(altura)):\n";
        mostrarEstructura(raiz);
        cout << endl;
    }
};

int main() {
    AVL arbol;

    // Insertar los datos proporcionados
    int datos[] = { 15, 20, 24, 10, 13, 7, 30, 36, 25 };
    int n = sizeof(datos) / sizeof(datos[0]);

    for (int i = 0; i < n; i++) {
        arbol.insertar(datos[i]);
        arbol.imprimirEstructura();
    }

    // Mostrar recorridos
    arbol.imprimirInorden();
    cout << endl;
    arbol.imprimirAlturas();

    system("pause>0");
    return 0;
}