#include <iostream>

using namespace System;
using namespace std;

//encontrar el numero MAYOR en un arreglo de enteros

template <typename T>


T Operacion(T arr[], int tamaño) {
	T pos = 0;

	for (int i = 0; i < tamaño; i++) {
		if (arr[i] > arr[pos])
			pos = i;
	}

	cout << endl << "El numero mayor del arreglo es: " << arr[pos];
	return pos;
}


int main() {
	int d;
	cout << endl << "Ingresa la cantidad de datos numericos: "; cin >> d;
	int* datos = new int[d]; //creacion de arreglo dinamico
	cout << endl << "Ingrese datos numericos " << endl;
	for (int i = 0; i < d; i++) {
		cout << "Dato nro. " << i + 1 << ": ";
		cin >> datos[i];
	}

	Operacion(datos, d);

	delete[] datos;
	system("pause>0");
	return 0;
}