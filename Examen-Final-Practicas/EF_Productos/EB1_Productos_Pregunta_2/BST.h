#pragma once
#include "Utilidades.h"

struct Nodo {
	int dato;
	Nodo* der;
	Nodo* izq;
};

struct Nodo* arbol = NULL;

class InventarioProductos {
private:
	Nodo* raiz;

	bool busqueda(Nodo* arbol, int n) {
		if (arbol == NULL) {
			return false;
		}
		else if (arbol->dato == n) {
			return true;
		}
		else if (n < arbol->dato) {
			return busqueda(arbol->izq, n);
		}
		else {
			return busqueda(arbol->der, n);
		}
	}

	Nodo* crearNodo(int n) {
		Nodo* nuevo_nodo = new Nodo();
		nuevo_nodo->dato = n;
		nuevo_nodo->der = NULL;
		nuevo_nodo->izq = NULL;

		return nuevo_nodo;
	}

	void insertarNodo(Nodo*& arbol, int n) {
		if (arbol == NULL) {
			Nodo* nuevo_nodo = crearNodo(n);
			arbol = nuevo_nodo;
		}
		else {
			if (busqueda(arbol, n) == false) {
				int valorRaiz = arbol->dato;
				if (n < valorRaiz) {
					insertarNodo(arbol->izq, n);
				}
				else {
					insertarNodo(arbol->der, n);
				}
			}
			else
				cout << "\nEl Dato ingresado ya existe, ingrese otro nuevo: ";
		}
	}

	void InOrder(Nodo* arbol) const {
		if (arbol == NULL) {
			return;
		}
		else {
			InOrder(arbol->izq);
			cout << " - " << arbol->dato;
			InOrder(arbol->der);
		}
	}

	Nodo* findMax(Nodo* nodo) const {
		if (nodo == nullptr)
			return nullptr;
		while (nodo->der != nullptr)
			nodo = nodo->der;
		return nodo;
	}

	Nodo* findMin(Nodo* nodo) const {
		if (nodo == nullptr)
			return nullptr;
		while (nodo->izq != nullptr)
			nodo = nodo->izq;
		return nodo;
	}

	void sumEnRango(Nodo* nodo, double valor, double& sum, double& count) const {
		if (nodo == nullptr)
			return;
		if (nodo->dato <= valor) {
			sum += nodo->dato;
			count++;
			sumEnRango(nodo->izq, valor, sum, count);
			sumEnRango(nodo->der, valor, sum, count);
		}
		else {
			sumEnRango(nodo->izq, valor, sum, count);
		}
	}

	void eliminarInventario(Nodo* nodo) {
		if (nodo != nullptr) {
			eliminarInventario(nodo->izq);
			eliminarInventario(nodo->der);
			delete nodo;
		}
	}

public:

	InventarioProductos() : raiz(nullptr) {}


	// Funcion Insertar Precio
	void insertarPrecio(int valor) {
		insertarNodo(raiz, valor);
	}

	// Funcion Promedio Intervalo
	double promedioIntervalo(double valor) {
		Nodo* minNodo = findMin(raiz);
		if (minNodo == nullptr || valor < minNodo->dato) {
			return 0.0;
		}

		double sum = 0;
		double count = 0;

		sumEnRango(raiz, valor, sum, count);
		return count > 0 ? static_cast<double>(sum) / count : 0.0;
	}

	// Funcion Mostrar Precios
	void mostrarPrecios() const {
		InOrder(raiz);
	}

	//Liberar memoria
	~InventarioProductos() {
		eliminarInventario(raiz);
	}
};