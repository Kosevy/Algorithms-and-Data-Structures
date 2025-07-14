#include "Gestor.h"
#include "BST.h"
#include "Grafos.h"

Vehiculo v;

// se crea un vector para almacenar los datos de cada vehiculo generado
vector<Vehiculo> vehiculos;

// agregar menu
void menu() {
	cout << "=== MENU PRINCIPAL ===" << endl;
	cout << "1. QuickSort" << endl;
	cout << "2. Busqueda Binaria" << endl;
	cout << "3. Insertar un valor - BST" << endl;
	cout << "4. Mostrar elementos en orden - BST" << endl;
	cout << "5. Calcular promedio en un rango - BST" << endl;
	cout << "6. Calcular producto de los digitos del mayor valor - BST" << endl;
	cout << "7. Funciones de Grafos" << endl;
	cout << "8. Salir" << endl;
	cout << "Ingrese una opcion: ";
}

// agregar quicksort
void mostrarQuicksort(){
	quicksort(vehiculos, 0, vehiculos.size() - 1, comparacion);

	cout << "Ordenado por color y numero de asientos: " << endl;
	cout << "=========================================" << endl;
	for (const auto& vehiculos : vehiculos) {
		cout << "=====================" << endl;
		cout << "ID: " << vehiculos.id << endl;
		cout << "Marca: " << vehiculos.marcaStr << endl;
		cout << "Modelo:" << vehiculos.modelo << endl;
		cout << "Color: " << vehiculos.color << endl;
		cout << "Asientos: " << vehiculos.asiento << endl;
		cout << "=====================" << endl;
		cout << endl;
	}
}

// agregar busqueda binaria
bool comprarPorMarca(const Vehiculo& a, const Vehiculo& b) {
	return a.marca < b.marca;
}

void mostrarBusquedaBinaria() {
	// 1. Crear vector de punteros
	vector<Vehiculo*> punteros;
	for (auto& v : vehiculos) {
		punteros.push_back(&v);
	}

	// 2. Ordenar por marca
	auto compararPorMarca = [](const Vehiculo* a, const Vehiculo* b) {
		return a->getMarca() < b->getMarca();
		};
	sort(punteros.begin(), punteros.end(), compararPorMarca);

	// 3. Pedir marca a buscar
	int target;
	cout << "Busqueda Binaria" << endl;
	cout << "================" << endl;
	cout << "Ingrese el numero de la marca que desea encontrar" << endl;
	cout << "-> Toyota (1), Nissan (2), Hyundai (3), Mercedes (4): ";
	cin >> target;

	// 4. Realizar búsqueda
	if (!punteros.empty()) {
		int resultado = busqueda_binaria(punteros.data(), 0, punteros.size() - 1, target);

		// 5. Mostrar resultados
		if (resultado != -1) {
			cout << "Se encontro la marca " << target << " con ID: " << resultado << endl;
			cout << "\nVehiculos de la marca " << target << ":" << endl;
			cout << "=========================" << endl;
			for (const auto& v : vehiculos) {
				if (v.getMarca() == target) {
					cout << "ID: " << v.id << endl;
					cout << "Marca: " << v.getMarcaStr() << endl;
					cout << "Modelo: " << v.modelo << endl;
					cout << "Color: " << v.color << endl;
					cout << "Asientos: " << v.asiento << endl;
					cout << "========================" << endl;
				}
			}
		}
		else {
			cout << "No se encontro ningun vehiculo de la marca " << target << endl;
		}
	}
	else {
		cout << "No hay vehiculos para buscar." << endl;
	}
}

// agregar validacion para BST

bool esValido(int valor) {
	return valor >= 10 && valor <= 999;
}

int main() {
	srand(time(0));

	//Generacion de los datos de 350 vehiculos
	for (int i; i < 350; i++) {
		vehiculos.push_back(v.generadorDatos(i + 1));
	}

	//Insercion del arbol
	MiArbolBinario arbol;

	//Insercion de grafos
	Grafo grafo;

	int op;
	int valor;
	do {
		system("cls");
		menu();
		cin >> op;
		switch (op) {
		case 1:
			mostrarQuicksort();
			cin.ignore();
			cin.get();
			break;
		case 2:
			mostrarBusquedaBinaria();
			cin.ignore();
			cin.get();
			break;
		case 3:
			cout << "Ingrese valores para insertar (ingrese un valor fuera del rango 10-999 para terminar): " << endl;
			while (true) {
				cin >> valor;
				if (cin.fail()) {
					cout << "Entrada invalida. Por favor ingrese un numero entero." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				if (!esValido(valor)) {
					cout << "Valor fuera del rango permitido. Terminando entrada de valores." << endl;
					break;
				}
				arbol.insertar(valor);
			}
			break;
		case 4:
			cout << "== ELEMENTOS EN ORDEN ===" << endl;
			arbol.enOrden();
			cin.ignore();
			cin.get();
			break;
		case 5:
			cout << "=== PROMEDIO EN UN RANGO ===" << endl;
			cout << "Ingrese un valor para calcular el promedio del rango: " << endl;
			cin >> valor;
			cout << "Promedio del rango: " << arbol.promedio_rango(valor) << endl;
			cin.ignore();
			cin.get();
			break;
		case 6:
			cout << "=== PRODUCTO DE LOS DIGITOS ===" << endl;
			cout << "Producto de los digitos del mayor valor: " << arbol.producto_digitos() << endl;
			cin.ignore();
			cin.get();
			break;
		case 7:
			cout << "Iniciando el registro aleatorio..." << endl;
			grafo.registro_aleatorio();
			cout << "==================================" << endl;
			
			int valor_vertice;
			cout << "Ingrese un valor vertice: "; cin >> valor_vertice;
			cout << "==================================" << endl;

			int suma = grafo.sumatoria_Arcos(valor_vertice);
			if (suma != -1) {
				cout << "La suma de los arcos para el vertice" << valor_vertice << " es " << suma << endl;
			}
			else {
				cout << "Vertice no encontrado" << endl;
			}
			cin.ignore();
			cin.get();
			break;
		}
	} while (op != 8);
	system("pause>0");
	return 0;
}