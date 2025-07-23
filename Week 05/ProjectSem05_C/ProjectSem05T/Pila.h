#ifndef __PILA_H__
#define __PILA_H__
#include "Nodo.h"
using namespace std;

template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = NULL; };
	void push(T v);
	T pop();
	bool estaVacia();
};

template<class T>
void Pila<T>::push(T v) {
	if (estaVacia()) {
		tope = new Nodo<T>(v);
	}
	else {
		tope = new Nodo<T>(v, tope);
	}
}
template<class T>
T Pila<T>::pop() {
	if (estaVacia()) {
		//throw "Error, pila vacía";
		return NULL;
	}
	else {
		T elemento = (T)(tope->dato);
		tope = (Nodo<T>*) tope->siguiente;
		return elemento;
	}
}

template<class T>
bool Pila<T>::estaVacia() {
	return (tope == NULL);
}



#endif
