#pragma once
#include "Utilidades.h"


struct Nodo {
	int dato;
	Nodo* der;
	Nodo* izq;

};

struct Nodo* arbol = NULL;


class MiArbolBinario {
private:
	Nodo* root;

	bool busqueda(Nodo* arbol, int n) {
		if (arbol == NULL) {//si el arbol esta vacio
			return false;
		}
		else if (arbol->dato == n) {//si el nodo es igual al elemento buscado
			return true;
		}
		else if (n < arbol->dato) {
			return busqueda(arbol->izq, n);
		}
		else { // n>arbol->dato
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
		if (arbol == NULL) {//arbol vacio
			Nodo* nuevo_nodo = crearNodo(n);
			arbol = nuevo_nodo;//Nodo raiz
		}
		else {//el arbol ya tiene un nodo o mas
			if (busqueda(arbol, n) == false) {
				int valorRaiz = arbol->dato; //obtenemos el valor de la raiz
				if (n < valorRaiz) {//va al lado izquierdo pues es menor a la raiz
					insertarNodo(arbol->izq, n);//reemplazar esto sin recursividad
				}
				else {//Elemento es mayor a la raiz, se inserta en el lado derecho
					insertarNodo(arbol->der, n);//reemplazar esto sin recursividad
				}
			}
			else
				cout << "\nEl Dato ingresado ya existe";
		}
	}

	void InOrden(Nodo* arbol) const {
		if (arbol == NULL) {
			return;
		}
		else {
			InOrden(arbol->izq);
			cout << " - " << arbol->dato;
			InOrden(arbol->der);
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

	void sumEnRango(Nodo* nodo, int valor, int& sum, int& count) const {
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
public:
	MiArbolBinario() : root(nullptr) {}


	// Primera funcion
	void insertar(int valor) {
		insertarNodo(root, valor);
	}
	
	// Segunda funcion
	double promedio_rango(int valor) {
		Nodo* minNodo = findMin(root);
		if (minNodo == nullptr || valor < minNodo->dato) {
			return 0.0;
		}

		int sum = 0;
		int count = 0;

		sumEnRango(root, valor, sum, count);
		return count > 0 ? static_cast<double>(sum) / count : 0.0;
	}

	// Tercera funcion
	void enOrden() const {
		InOrden(root);
	}

	// Cuarta funcion
	int producto_digitos() const {
		Nodo* maxNodo = findMax(root);
		if (maxNodo == nullptr) {
			cout << "El arbol esta vacio" << endl;
		}

		int valor = maxNodo->dato;
		int producto = 1;
		
		while (valor > 0) {
			producto *= valor % 10;
			valor /= 10;
		}
		return producto;
	}

	//Liberar memoria
	~MiArbolBinario() {
		eliminarArbol(root);
	}

private:
	void eliminarArbol(Nodo* nodo) {
		if (nodo != nullptr) {
			eliminarArbol(nodo->izq);
			eliminarArbol(nodo->der);
			delete nodo;
		}
	}
};

// Se encuentra el nodo con el mayor valor dentro del arbol binario

//Funcion Insertar Iterativo Sin Recursividad.
/*void insertarIretativo(int x) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = x;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	if (arbol == NULL) {
		arbol = nuevo_nodo;//Nodo raiz
	}
	else {
		if (busquedaIterativo(arbol, x) == false) {
			struct Nodo* anterior, * reco;
			anterior = NULL;
			reco = arbol;
			while (reco != NULL) {
				anterior = reco;
				if (x < reco->dato)
					reco = reco->izq;
				else
					reco = reco->der;
			}
			if (x < anterior->dato)
				anterior->izq = nuevo_nodo;
			else
				anterior->der = nuevo_nodo;
		}
		else
			cout << "\nEl Dato ingresado ya existe";
	}
}*/

/*void mostrarArbol(Nodo* arbol, int cont) {//contador ayuda a separar un nodo del otro
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der, cont + 1);
		int i;
		for (i = 0; i < cont; i++) {
			printf("   ");
		}
		cout << "\n" << arbol->dato;
		mostrarArbol(arbol->izq, cont + 1);
	}
}*/

/*bool busquedaIterativo(Nodo* arbol, int x) {
	if (arbol == NULL)//si el arbol esta vacio
		return false;
	else {
		while (arbol != NULL && x != arbol->dato) {
			if (x < arbol->dato)
				arbol = arbol->izq;
			else
				arbol = arbol->der;
		}
		if (arbol != NULL)
			return true;
		else
			return false;
	}
}*/

//Recorrido en profundidad - PreOrden
void preOrden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {

		cout << " - " << arbol->dato;
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}


void PostOrden(Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		cout << " - " << arbol->dato;
	}
}

/*
void menu() {
	int dato, opcion, contador = 0;
	do {
		cout << "\n\t MENU";
		cout << "\n\t 1. Insertar Nuevo Nodo Iterativo";
		cout << "\n\t 2. Mostrar Arbol Completo";
		cout << "\n\t 3. Buscar Dato Iterativo";
		cout << "\n\t 4. Recorrer en PreOrden";
		cout << "\n\t 5. Recorrer en InOrden";
		cout << "\n\t 6. Recorrer en PostOrden";
		cout << "\n\t 7. Buscar Dato Recursivo";
		cout << "\n\t 8. Insertar Nuevo Nodo Recursivo";
		cout << "\n\t 9. Salir";
		cout << "\n\t Opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
		{
			cout << "\n\t Digite Numero: ";
			cin >> dato;
			//insertarNodo(arbol,dato);//insertamos un nuevo nodo
			insertarIretativo(dato);
			cout << endl;
			//	system("pause");
			break;
		}
		case 2:
		{
			cout << "\nMostrando Arbol Completo\n\n:";
			mostrarArbol(arbol, contador);
			cout << endl;
			system("pause");
			break;
		}
		case 3: {
			cout << "\nDigite el elemento a buscar:";
			cin >> dato;
			//printf("%d",busquedaIterativo(arbol,dato));
			if (busquedaIterativo(arbol, dato) == true)
				cout << "\nEl elemento " << dato << " ha sido encontrado en el arbol\n";
			else
				cout << "\nElemento no encontrado\n";
			break;
		}
		case 4: {
			cout << "\nRecorrido en PreOrden.";
			preOrden(arbol);
			cout << endl;
			break;
		}
		case 5: {
			cout << "\nRecorrer en InOrden";
			InOrden(arbol);
			cout << endl;
			break;
		}
		case 6: {
			cout << "\nRecorrer en PostOrden";
			PostOrden(arbol);
			cout << endl;
			break;
		}
		case 7: {
			cout << "\nDigite el elemento a buscar:";
			cin >> dato;
			if (busqueda(arbol, dato) == true)
				printf("\nEl elemento %d ha sido encontrado en el arbol\n", dato);
			else
				printf("\nElemento no encontrado\n");
			break;
		}
		case 8:
		{
			cout << "\n\t Digite Numero: ";
			cin >> dato;
			insertarNodo(arbol, dato);//insertamos un nuevo nodo
			//insertarIretativo(dato);
			cout << endl;
			//	system("pause");	
			break;
		}
		}//fin switch
	} while (opcion != 9);//fin do while
}
*/