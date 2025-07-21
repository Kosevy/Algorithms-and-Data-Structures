#pragma once
#include <iostream>
using namespace std;

int menu()
{
	short op;
	cout << "\t MENU" << endl;
	cout << " 1- Listar elementos" << endl;
	cout << " 2- Insertar al final" << endl;
	cout << " 3- Insertar al inicio" << endl;

	cout << " Ingrese una opcion: "; cin >> op;

	return op;
}