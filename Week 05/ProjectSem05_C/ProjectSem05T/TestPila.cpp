#include <iostream>
#include "Pila.h"
#include "Punto.h"

using namespace std;

int main() {
	Pila<Punto*>* pila;
	pila = new Pila<Punto*>();

	pila->push(new Punto(5, 4));
	pila->push(new Punto(4, 4));
	pila->push(new Punto(5, 3));

	Punto* elem;

	do {
		elem = pila->pop();
		if(elem != NULL)
			cout << elem->toString() << endl;

	} while (elem!=NULL);

	cin.get();
	return 0;
}