#include <iostream>
#include "nodo.h"
#include "lista.h"
#include "punto.h"

using namespace std;

int main() {
	Lista<Punto*> pLista;
	pLista.insertarInicio(new Punto(8, 1));
	pLista.insertarInicio(new Punto(7, 2));
	pLista.insertarInicio(new Punto(1, 3));
	pLista.insertarInicio(new Punto(9, 4));
	pLista.insertarInicio(new Punto(4, 5));
	pLista.mostrar();
	cin.get();
	return 0;
}