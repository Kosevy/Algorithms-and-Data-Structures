#include <iostream>

using namespace std;
using namespace System;

int Factorial(int n) {
	if (n == 1)
		return 1;
	else
		return Factorial(n - 1) * n;
}

int InvertirNum(int numero, int potencia = 0) {
	if (numero < 10) {
		return numero;
	}
	else {
		int ultimoDigito = numero % 10;
		int restoNumero = numero / 10;
		return ultimoDigito * pow(10, (int)log10(restoNumero) + 1) + InvertirNum(restoNumero);
	}
}

int simulador(int meses) {
	if (meses == 0) return 0;
	if (meses == 1) return 1;
	return simulador(meses - 1) + simulador(meses - 2);
}


void mostrarMenu() {
	cout << "\n=== MENU DE EJERCICIOS CON TEMPLATES ===" << endl;
	cout << "1. Calcular el factorial de un numero" << endl;
	cout << "2. Invertir el orden de un numero entero positivo" << endl;
	cout << "3. Simulador de reproduccion de conejos" << endl;
	cout << "4. Codigo de Bisecar" << endl;
	cout << "5. Calcular area de rectangulo" << endl;
	cout << "6. Registro de notas estudiantiles" << endl;
	cout << "7. Salir" << endl;
	cout << "Seleccione una opcion: ";
}


int main() {
	int opcion;

	do {
		mostrarMenu();
		cin >> opcion;
		int n;
		switch (opcion) {
		case 1:

			cout << "Ingresa un numero: "; cin >> n;

			cout << "El factorial es: " << Factorial(n) << endl;
			break;
		case 2:
			cout << "Ingresa un numero entero positivo: "; cin >> n;

			cout << "El numero invertido es: " << InvertirNum(n) << endl;
			break;
		case 3:
			int meses = 12;
			cout << "Despues de " << meses << " meses, habra " << simulador(meses + 1)
				<< " pares de conejos" << endl ;
			break;
		case 4:
			cout << "";
		}

	} while (opcion != 7);
	

	system("pause>0");
	return 0;
}