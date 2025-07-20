#pragma once
#include <iostream>
using namespace std;

const int MAX_ARBOL = 1000;

class Arbol {
private:
    int arbol[MAX_ARBOL];

    void insertar(int valor, int i);
    void postorden(int i);
    void rangoSumar(int i, int min, int max, int& suma, int& contador);
    void visualizar(int i, int nivel);

public:
    Arbol();

    void registrarPuntuacion(int valor);
    void listarPostorden();
    void calcularPromedioTop(int min, int max);
    void mostrarArbol();
};
