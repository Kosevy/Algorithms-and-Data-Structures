#include "Utilidades.h"
#include "Exercise1.h"
#include "Exercise2.h"
#include "Exercise3.h"
#include "Exercise4.h"
#include "Exercise5.h"
#include "Exercise6.h"
#include "Exercise7.h"
#include "Exercise8.h"

//analisis de complejidad de un codigo
void funcion(int n) { //es una operación O(n^2) ya que recorre una lista dentro de otra lista n veces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Operación constante
        }
    }
}


int main() {
	int opmain;

	do {
		Console::Clear();
		cout << "=== Menu de Ejercicios ===" << endl;
		cout << "1. Ejercicio 1 - Comprobar Primos" << endl;
		cout << "2. Ejercicio 2 - Recopilacion Datos Estudiantes" << endl;
		cout << "3. Ejercicio 3 - Orden de Lista" << endl;
		cout << "4. Ejercicio 4 - Recursividad" << endl;
		cout << "5. Ejercicio 5 - Pilas" << endl;
		cout << "6. Ejercicio 6 - Colas" << endl;
		cout << "7. Ejercicio 7 - Listas Enlazadas" << endl;
		cout << "8. Ejercicio 8 - Busqueda" << endl;
		cout << "9. Salir" << endl;
		cout << "Seleccione una opcion: "; cin >> opmain;
		cin.ignore();
		switch (opmain) {
		case 1:
			pregunta1(); //comprobar primos
			break;
		case 2:
			pregunta2(); //recopilacion de datos de estudiantes
			break;
		case 3:
			pregunta3(); //orden de lista
			break;
		case 4:
			pregunta4(); //recursividad 
			break;
		case 5:
			pregunta5(); //pilas
			break;
		case 6:
			pregunta6(); //colas
			break;
		case 7:
			pregunta7(); //listas enlazadas
			break;
		case 8:
			pregunta8(); //Ordenamiento QuickSort
			break;
		case 9:
			//pregunta9(); //Busqueda
			break;
		default:
			cout << "Error, intente de nuevo." << endl;
			break;
		}
	} while (opmain != 9);

	system("pause>0");
	return 0;
}