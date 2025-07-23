#include <iostream>
#include "Cola.h"
#include "Punto.h"

using namespace std;

int main() {
	Cola<Punto*>* cola;
	cola = new Cola<Punto*>();
	
	cola->enqueue(new Punto(5, 4));
	cola->enqueue(new Punto(4, 4));
	cola->enqueue(new Punto(3, 3));

	Punto* elem;

	do {
		elem = cola->dequeue();
		cout << elem->toString() << endl;

	} while (!cola->esVacia());

	cin.get();
	return 0;
}