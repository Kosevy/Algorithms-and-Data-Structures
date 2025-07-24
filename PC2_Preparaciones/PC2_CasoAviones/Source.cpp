#include "Utilidades.h"
#include "Gestor.h"

void menuPrincipal() {
	system("cls");
	cout << "\tMENU\t" << endl;
	cout << "1- Generar datos" << endl;
	cout << "2- Indexar en arbol binario de busqueda" << endl;
	cout << "3- Ordenar por ID VUELO " << endl;
	cout << "4- Hash Table" << endl;
	cout << "5- Salir" << endl;
	cout << "Ingrese una opcion: ";
}

int main() {

	vector<Vuelo> vuelos = generarDatos(datosCant);
	HashTable tablaHash;
	ArbolBinarioBusqueda arbol;

	for (const auto&vuelo : vuelos) {
		tablaHash.insertar(vuelo.registro, vuelo.idAerolinea, vuelo.matriculaStr);
		arbol.insertar(vuelo.idAerolinea);
	}

	srand(time(NULL));
	datosCant = 100 + rand() % (5000 - 100 + 1);

	int op;
	do {
		menuPrincipal();
		cin >> op;
		cin.ignore();
		switch (op) {
		case 1: {
			vector<Vuelo> vuelos = generarDatos(150);
			vector<Vuelo> vuelosOrdenados = vuelos;
			cout << "\n=== DATOS GENERADOS===\n";
			cout << "Nro. Registro\tID AEROLINEA\tID VUELO\tMatricula Avion\n";
			cout << "==============================================================" << endl;
			for (const auto& p : vuelosOrdenados) {
				cout << p.registro << "\t\t" << p.idAerolinea<< "\t\t"
					<< p.idVuelo << "\t\t" << p.matriculaStr << endl;
			}
			cin.ignore();
			break;
		}
		case 2: {
			cout << "\nRecorrido Post-Orden del arbol binario de busqueda (ID AEROLINEA):\n";
			vector<int> postOrden = arbol.postOrden();
			for (int id : postOrden) {
				cout << id << " ";
			}
			cout << "\nTotal de elementos: " << postOrden.size() / 120 << endl;
			cin.ignore();
			break;
		}
		case 3: {
			vector<Vuelo> vuelos = generarDatos(150);

			vector<Vuelo> vuelosOrdenados = vuelos;
			mergeSort<Vuelo>(vuelosOrdenados, 0, vuelosOrdenados.size() - 1,
				[](const Vuelo& a, const Vuelo& b) {
					return a.idVuelo < b.idVuelo;
				});

			cout << "\n=== Vuelos ordenados por ID===\n";
			cout << "ID Vuelo\tID Registro\tID Aerolinea\tMatricula Avion\n";
			cout << "==============================================================" << endl;
			for (const auto& p : vuelosOrdenados) {
				cout << p.idVuelo << "\t\t" << p.registro << "\t\t"
					<< p.idAerolinea << "\t\t" << p.matriculaStr << endl;
			}
			cin.ignore();
			break;
		}
		case 4:
			cout << "\n=== Clave: NRO. REGISTRO + AEROLINEA | Valor: VUELO ===\n";
			tablaHash.mostrar();
			cout << "============================================" << endl;
			cin.ignore();
			break;
		case 5:
			cout << "Saliendo del programa" << endl;
			break;
		default:
			cout << "Error, opcion no valida intente de nuevo" << endl;
			break;
		}
	} while (op != 5);

	system("pause>0");
	return 0;
}