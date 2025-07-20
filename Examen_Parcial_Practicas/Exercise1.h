#pragma once
#include "Utilidades.h"


/*int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int sumaDigitos(int n) {
	if (n == 0) return 0;
	return (n % 10) + sumaDigitos(n / 10);
}

int potenciaNumero(int base, int expo) {
	if (expo == 0) return 1;
	if (expo == 1) return base;
	return base * potenciaNumero(base, expo - 1);
}

int calcularProducto(int n) {
	if (n == 0) return 1;
	return (n % 10) * calcularProducto(n / 10);
}

int Fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return Fibonacci(n - 2) + Fibonacci(n - 1); 
}

int SumaArreglo(int arr[], int n) {
	if (n == 0) return 0;
	return arr[0] + SumaArreglo(arr + 1, n - 1);
}

string invertirCadena(string arr) {
	if (arr.empty()) return "";
	if (arr.size() == 1) return arr;
	return arr.back() + invertirCadena(arr.substr(0, arr.size() - 1));
}*/


// PREGUNTA 1 - ingresar 34897 y retornar 37

bool esPrimo(int n) { 
	if (n <= 1) return false;
	if (n == 2) return true;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

string comprobarPrimos(int n) {
	if (n == 0) return "";
	int digito = n % 10;

	if (esPrimo(digito)) {
		return comprobarPrimos(n / 10) + to_string(digito);
	}
	return comprobarPrimos(n / 10);
}

void pregunta1() {
	cout << "\n Desarrollar un algoritmo que tenga funcion recursiva que permita" << endl;
	cout << " ingresar un numero entero y compruebe si los digitos del numero" << endl;
	cout << " son numeros primos." << endl;

	int n;

	cout << "\n Ingrese Numero Entero: "; cin >> n;

	string resultado = comprobarPrimos(n);

	cout << "\n Resultado: " << resultado << endl;
	cin.ignore();
	cout << "Presione enter para volver al menu" << endl;
	cin.ignore();
}

