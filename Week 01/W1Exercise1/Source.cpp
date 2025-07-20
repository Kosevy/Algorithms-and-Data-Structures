#include <iostream>

using namespace System;
using namespace std;

//Suma y Promedio de notas:

void operaciones(int A[], int n) {
	int sum = 0;
	double prom = 0.0;

	for (int i = 0; i < n; i++) {
		sum = sum + A[i];
	}
	prom = sum / (double)n;

	cout << endl << "La suma de las notas es: " << sum;
	cout << endl << "El promedio de las notas es: " << prom;
}

int main() {
	int n;

	cout << endl << "Ingrese una cantidad de notas: "; cin >> n;
	int* notas = new int[n]; //creacion de arreglo dinamico para pasarselo a operaciones

	cout << endl << "Ingrese nota(s) " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Nota " << i + 1 << ": ";
		cin >> notas[i];
	}

	operaciones(notas, n);

	delete[] notas;
	system("pause>0");
	return 0;
}
