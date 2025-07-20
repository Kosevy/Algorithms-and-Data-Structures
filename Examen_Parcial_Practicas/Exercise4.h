#pragma once
#include "Utilidades.h"

int recursividad(int n) {
	if (n == 0) return 0;
	int digito = n % 10;

	return digito + recursividad(n / 10);
}

void pregunta4() {
	int n;
	cout << "Ingrese un numero: ";
	cin >> n;

	int resultado = recursividad(n);
	cout << "La suma de los digitos es: " << resultado << endl;
	cout << endl << "Presione enter para volver al menu";
	cin.get();
	cin.ignore();
}