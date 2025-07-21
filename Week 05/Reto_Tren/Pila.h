#pragma once
#include "Nodo.h"

template<class T>
class Pila {
private:
	Nodo<T>* tope;
public:
	Pila() : tope(nullptr) {} //forma estandar de usar constructor con pila

	void push(T valor) {
		tope = new Nodo<T>(valor, tope);
	}

	bool pop(T& valor) {
		if (tope == nullptr) return false;
		valor = tope->dato; //puntero entra a dato
		Nodo<T>* temp = tope;
		tope = tope->siguiente; //actualiza tope
		delete temp;
		return true; //libera memoria
	}

	bool estaVacia() { return tope == nullptr; } //si esta vacia retorna nullptr

	bool verTope(T& valor) {  //funcion peek
		if (estaVacia()) return false;
		valor = tope->dato;
		return true;
	}
};