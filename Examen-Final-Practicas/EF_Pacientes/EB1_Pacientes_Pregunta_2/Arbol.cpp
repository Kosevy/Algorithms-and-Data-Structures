#include "Arbol.h"

Arbol::Arbol() {
    for (int i = 0; i < MAX_ARBOL; i++) {
        arbol[i] = -1;
    }
}

void Arbol::insertar(int valor, int i) {
    if (i >= MAX_ARBOL) {
        cout << "No hay espacio para insertar.\n";
        return;
    }
    if (arbol[i] == -1) {
        arbol[i] = valor;
    }
    else if (valor < arbol[i]) {
        insertar(valor, 2 * i + 1);
    }
    else if (valor > arbol[i]) {
        insertar(valor, 2 * i + 2);
    }
    else {
        cout << "Valor repetido, no se inserta.\n";
    }
}

void Arbol::postorden(int i) {
    if (i >= MAX_ARBOL || arbol[i] == -1) return;
    postorden(2 * i + 1);
    postorden(2 * i + 2);
    cout << arbol[i] << " ";
}

void Arbol::rangoSumar(int i, int min, int max, int& suma, int& contador) {
    if (i >= MAX_ARBOL || arbol[i] == -1) return;
    rangoSumar(2 * i + 1, min, max, suma, contador);
    if (arbol[i] >= min && arbol[i] <= max) {
        suma += arbol[i];
        contador++;
    }
    rangoSumar(2 * i + 2, min, max, suma, contador);
}

void Arbol::visualizar(int i, int nivel) {
    if (i >= MAX_ARBOL || arbol[i] == -1) return;
    visualizar(2 * i + 1, nivel + 1);
    for (int j = 0; j < nivel; j++) cout << "  ";
    cout << "/ " << arbol[i] << "\n";
    visualizar(2 * i + 2, nivel + 1);
}

void Arbol::registrarPuntuacion(int valor) {
    if (valor <= 0 || valor >= 1000) {
        cout << "Puntuacion invalida, debe ser 1 a 999.\n";
        return;
    }
    insertar(valor, 0);
    cout << "Puntuacion registrada con exito.\n";
}

void Arbol::listarPostorden() {
    cout << "Puntuaciones (postorden): ";
    postorden(0);
    cout << "\n";
}

void Arbol::calcularPromedioTop(int min, int max) {
    int suma = 0, contador = 0;
    rangoSumar(0, min, max, suma, contador);
    if (contador == 0) {
        cout << "No hay puntuaciones en el rango.\n";
    }
    else {
        cout << "Promedio en rango [" << min << ", " << max << "] es: "
            << (double)suma / contador << "\n";
    }
}

void Arbol::mostrarArbol() {
    cout << "Estructura del arbol:\n";
    visualizar(0, 0);
}
