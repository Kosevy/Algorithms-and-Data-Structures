#include<iostream>

using namespace std;

#include "nodo.h"
#include "lista.h"
#include "punto.h"


int main() {
	Lista<Punto*> pLista;
	pLista.AgregaralInicio(new Punto(8, 1));
	pLista.AgregaralInicio(new Punto(7, 2));
	pLista.AgregaralInicio(new Punto(1, 3));
	pLista.AgregaralFinal(new Punto(14, 15));
	pLista.AgregaralInicio(new Punto(9, 4));
	pLista.AgregaralInicio(new Punto(4, 5));
	pLista.AgregarenPosicion(new Punto(40, 1),3);
	pLista.Mostrar();
	cin.get();
	return 0;
}