#include "ArbolB.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void imprimir(int e) {
	cout << " " << e;
}

int main() {
	//srand(time(0));
	ArbolB<int>* arbol = new ArbolB<int>(imprimir);
	/*
	for (int i = 0; i < 30; ++i) {
		arbol->insertar(rand() % 100);
	}*/

	//***Pruebas***
	//Ingreso manual
	//Caso 1:
	//arbol->insertar(6);
	//arbol->insertar(16);
	//arbol->insertar(26);

	//Caso 2:
	arbol->insertar(10);
	arbol->insertar(6);
	arbol->insertar(26);
	arbol->insertar(30);


	cout << "EnOrden";
	arbol->enOrden();
	cout << endl;

	cout << "PreOrden";
	arbol->preOrden();
	cout << endl;

	cout << "PostOrden";
	arbol->postOrden();
	cout << endl;

	cout << "Altura: " << arbol->altura() << endl;
	cout << "Cantidad: " << arbol->cantidad() << endl;

	cin.get();

	return 0;
}