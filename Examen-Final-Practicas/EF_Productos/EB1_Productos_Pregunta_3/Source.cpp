#include "Grafos.h"

int main() {
	//Insercion de grafos
	RedLaboratorios grafo;

	int op;
	int valor_vertice;

	do {
		system("cls");
		cout << "Menu" << endl;
		cout << "1. Iniciar registro" << endl;
		cout << "2. Salir" << endl;
		cout << "Ingrese una opcion: "; cin >> op;
		switch (op) {
		case 1:
			cout << "Iniciando el registro aleatorio..." << endl;
			grafo.registro_aleatorio();
			cout << "==================================" << endl;
			cin.ignore();
			cin.get();
			break;
		}
	} while (op != 2);
}