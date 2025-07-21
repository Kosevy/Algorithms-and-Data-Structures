#pragma once
#include "Nodo.h"
#include "iostream"
using namespace std;

template<class T>
class Cola
{
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola() {
		this->inicio = nullptr;
		this->fin = nullptr;
	}
	void encolar(T valor);//enqueue
	T desencolar(); //dequeue
	bool estaVacia();

};//fin

//IMPLEMENTACION
template<class T>
bool Cola<T>::estaVacia()
{
	return (inicio == nullptr);
}

template<class T>
void Cola<T>::encolar(T valor)
{
	Nodo<T>* nuevoNodo = new Nodo<T>(valor);
	if (estaVacia())
	{
		inicio = nuevoNodo;
		fin = inicio;
	}
	else
	{
		fin->siguiente = nuevoNodo;
		fin = nuevoNodo;
	}
	nuevoNodo = nullptr;
}

template<class T>
T Cola<T>::desencolar()
{
	T dato = inicio->dato;
	if (inicio == fin)
	{
		inicio = nullptr;
		fin = nullptr;
	}
	else
	{
		inicio = inicio->siguiente;
	}
	return dato;
}