#pragma once
#include "iostream";
using namespace std;

class Nodo
{
public:
	int dato;
	Nodo* siguiente;
	Nodo(int valor)
	{
		dato = valor;
		siguiente = nullptr;
	}
};

//lista
class ListaEnlazada {
private:
	Nodo* cabeza;
public:
	ListaEnlazada() {
		cabeza = nullptr;
	}
	//metodos
	void InsertarAlFinal(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (cabeza == nullptr) //lista vacia
		{
			cabeza = nuevo;
		}
		else
		{
			//define un nodo adicional 
			Nodo* actual = cabeza;
			//recorro la lista hasta llegar al final
			while (actual->siguiente != nullptr)
			{
				//avanza
				actual = actual->siguiente;
			}
			actual->siguiente = nuevo;
		}
		cout << endl << "Nodo " << valor << " ingresado al final";
	}

	void InsetarAlInicio(int valor) {
		Nodo* nuevo = new Nodo(valor);

		nuevo->siguiente = cabeza;
		cabeza = nuevo;

		cout << endl << "Nodo " << valor << " ingresado al inicio";
	}

	//metodo mostrar elementos
	void MostrarElementos()
	{
		if (cabeza == nullptr)
		{
			cout << endl << "LISTA VACIA";
		}
		else
		{
			Nodo* actual = cabeza;
			while (actual != nullptr)
			{
				cout << actual->dato << "->";//se imprime el dato
				actual = actual->siguiente;
			}
			cout << "null\n";
		}

	}

};