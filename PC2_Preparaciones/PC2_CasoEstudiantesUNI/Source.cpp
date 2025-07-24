#include <iostream>
#include "Gestor.h"

using namespace std;

int main() {
	srand(time(NULL));
	int numEstudiantes = 150;

	ListaEnlazada<Estudiante> listaEstudiantes;

	for (int i = 0; i < numEstudiantes; i++) {
		Estudiante estudiante = generarEstudianteAleatorio();
		listaEstudiantes.agregar(estudiante);
	}

	cout << "Informacion aleatoria de " << numEstudiantes << " personas:" << endl;
	listaEstudiantes.mostrar();
	cout << "Presione Enter para continuar al menu..." << endl;
	cin.ignore();

	int op;

	do {
		system("cls");
		cout << "=== MENU PRINCIPAL ===" << endl;
		cout << "1. Mostrar orden por edad con QUICKSORT" << endl;
		cout << "2. Busqueda de programa con BS" << endl;
		cout << "3. Mostrar promedios con HASH TABLE" << endl;
		cout << "4. Mostrar IDs con valores pares con BST" << endl;
		cout << "5. Busqueda del mayor ID con BST" << endl;
		cout << "6. Eliminar nodo del arbol binario con BST" << endl;
		cout << "Ingrese una opcion: "; cin >> op;
		cin.ignore();
		switch (op) {
		case 1:
			listaEstudiantes.mostraOrdenPorEdad();
			cin.ignore();
			break;
		case 2:
			listaEstudiantes.buscarPrograma();
			cin.ignore();
			break;
		case 3:
			listaEstudiantes.mostrarPromedio();
			cin.ignore();
			break;
		case 4:
			listaEstudiantes.mostrarIDPares();
			cin.ignore();
			break;
		case 5:
			listaEstudiantes.mostrarMayorID();
			cin.ignore();
			break;
		case 6:
			listaEstudiantes.eliminarNodoPorID();
			cin.ignore();
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
			break;
		}
	} while (op != 7);
	cin.ignore();

	system("pause>0");
	return 0;
}