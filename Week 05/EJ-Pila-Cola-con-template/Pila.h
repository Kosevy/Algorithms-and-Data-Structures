#pragma once
#include "Nodo.h"
using namespace std;

template<class T>
class Pila
{
private:
	Nodo<T>* tope;
public:
	//constructor
	Pila() { tope = nullptr; }
	
	void push(T valor); //metodo push para agregar
	T pop();//metodo push para obtener
	bool estaVacia();  

};//FIN

//IMPLEMENTACION
template<class T>
void Pila<T>::push(T valor)
{
	if (estaVacia())
	{
		tope = new Nodo<T>(valor);
	}
	else
	{
		tope = new Nodo<T>(valor, tope);
	}
}

template<class T>
T Pila<T>::pop()
{
	if (estaVacia())
	{
		return nullptr;
	}
	else
	{
		T elemento = (T)tope->dato; //casting
		tope = (Nodo<T>*) tope->siguiente;
		return elemento;
	}
}

template<class T>
bool Pila<T>::estaVacia()
{
	return (tope == nullptr);
}