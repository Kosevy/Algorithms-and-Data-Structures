// ArbolBinario.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "iostream"

using namespace System;
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Nodo {
	int dato;
	Nodo *der;
	Nodo *izq;
};
struct Nodo *arbol = NULL;

void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void insertarIretativo(int);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
bool busquedaIterativo(Nodo *, int);
void preOrden(Nodo *);
void InOrden(Nodo *);
void PostOrden(Nodo *);

int main() {
	/*
	insertarNodo(arbol,8);// Insertar Recursivo
	insertarNodo(arbol,3);
	insertarNodo(arbol,10);
	insertarNodo(arbol,1);
	insertarNodo(arbol,6);
	insertarNodo(arbol,4);
	insertarNodo(arbol,7);
	insertarNodo(arbol,14);
	insertarNodo(arbol,13); */
	insertarIretativo(8);//Funcion Iterativa
	insertarIretativo(3);
	insertarIretativo(10);
	insertarIretativo(1);
	insertarIretativo(6);
	insertarIretativo(4);
	insertarIretativo(7);
	insertarIretativo(14);
	insertarIretativo(13);
	menu();
	//getch();
	return 0;
}

void menu() {
	int dato, opcion, contador = 0;
	do {
		printf("\n\t MENU");
		printf("\n\t 1. Insertar Nuevo Nodo Iterativo");
		printf("\n\t 2. Mostrar Arbol Completo");
		printf("\n\t 3. Buscar Dato Iterativo");
		printf("\n\t 4. Recorrer en PreOrden");
		printf("\n\t 5. Recorrer en InOrden");
		printf("\n\t 6. Recorrer en PostOrden");
		printf("\n\t 7. Buscar Dato Recursivo");
		printf("\n\t 8. Insertar Nuevo Nodo Recursivo");
		printf("\n\t 9. Salir");
		printf("\n\t Opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
		{
			printf("\n\t Digite Numero: ");
			scanf("%d", &dato);
			//insertarNodo(arbol,dato);//insertamos un nuevo nodo
			insertarIretativo(dato);
			printf("\n");
			//	system("pause");
			break;
		}
		case 2:
		{
			printf("\nMostrando Arbol Completo\n\n:");
			mostrarArbol(arbol, contador);
			printf("\n");
			system("pause");
			break;
		}
		case 3: {
			printf("\nDigite el elemento a buscar:");
			scanf("%d", &dato);
			//printf("%d",busquedaIterativo(arbol,dato));
			if (busquedaIterativo(arbol, dato) == true)
				printf("\nEl elemento %d ha sido encontrado en el arbol\n", dato);
			else
				printf("\nElemento no encontrado\n");
			break;
		}
		case 4: {
			printf("\nRecorrido en PreOrden.");
			preOrden(arbol);
			printf("\n");
			break;
		}
		case 5: {
			printf("\nRecorrer en InOrden");
			InOrden(arbol);
			printf("\n");
			break;
		}
		case 6: {
			printf("\nRecorrer en PostOrden");
			PostOrden(arbol);
			printf("\n");
			break;
		}
		case 7: {
			printf("\nDigite el elemento a buscar:");
			scanf("%d", &dato);
			if (busqueda(arbol, dato) == true)
				printf("\nEl elemento %d ha sido encontrado en el arbol\n", dato);
			else
				printf("\nElemento no encontrado\n");
			break;
		}
		case 8:
		{
			printf("\n\t Digite Numero: ");
			scanf("%d", &dato);
			insertarNodo(arbol, dato);//insertamos un nuevo nodo
									  //insertarIretativo(dato);
			printf("\n");
			//	system("pause");	
			break;
		}
		}//fin switch
	} while (opcion != 9);//fin do while
}

Nodo *crearNodo(int n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n) {
	if (arbol == NULL) {//arbol vacio
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;//Nodo raiz
	}
	else {//el arbol ya tiene un nodo o mas
		if (busqueda(arbol, n) == false) {
			int valorRaiz = arbol->dato; //obtenemos el valor de la raiz
			if (n<valorRaiz) {//va al lado izquierdo pues es menor a la raiz
				insertarNodo(arbol->izq, n);//reemplazar esto sin recursividad
			}
			else {//Elemento es mayor a la raiz, se inserta en el lado derecho
				insertarNodo(arbol->der, n);//reemplazar esto sin recursividad
			}
		}
		else
			printf("\nEl Dato ingresado ya existe");
	}
}
//Funcion Insertar Iterativo Sin Recursividad.
void insertarIretativo(int x) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = x;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	if (arbol == NULL) {
		arbol = nuevo_nodo;//Nodo raiz
	}
	else {
		if (busquedaIterativo(arbol, x) == false) {
			struct Nodo *anterior, *reco;
			anterior = NULL;
			reco = arbol;
			while (reco != NULL) {
				anterior = reco;
				if (x<reco->dato)
					reco = reco->izq;
				else
					reco = reco->der;
			}
			if (x<anterior->dato)
				anterior->izq = nuevo_nodo;
			else
				anterior->der = nuevo_nodo;
		}
		else
			printf("\nEl Dato ingresado ya existe");
	}
}

void mostrarArbol(Nodo *arbol, int cont) {//contador ayuda a separar un nodo del otro
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der, cont + 1);
		int i;
		for (i = 0; i<cont; i++) {
			printf("   ");
		}
		printf("%d\n", arbol->dato);
		mostrarArbol(arbol->izq, cont + 1);
	}
}

bool busqueda(Nodo *arbol, int n) {
	if (arbol == NULL) {//si el arbol esta vacio
		return false;
	}
	else if (arbol->dato == n) {//si el nodo es igual al elemento buscado
		return true;
	}
	else if (n<arbol->dato) {
		return busqueda(arbol->izq, n);
	}
	else { // n>arbol->dato
		return busqueda(arbol->der, n);
	}
}

bool busquedaIterativo(Nodo *arbol, int x) {
	if (arbol == NULL)//si el arbol esta vacio
		return false;
	else {
		while (arbol != NULL && x != arbol->dato) {
			if (x<arbol->dato)
				arbol = arbol->izq;
			else
				arbol = arbol->der;
		}
		if (arbol != NULL)
			return true;
		else
			return false;
	}
}

//Recorrido en profundidad - PreOrden
void preOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		printf(" %d - ", arbol->dato);
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void InOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		InOrden(arbol->izq);
		printf(" %d - ", arbol->dato);
		InOrden(arbol->der);
	}
}

void PostOrden(Nodo *arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		printf(" %d - ", arbol->dato);
	}
}