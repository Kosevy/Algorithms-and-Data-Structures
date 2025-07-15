#include "BST.h";

void menu() {
	cout << "=== MENU PRINCIPAL - BST ===" << endl;
	cout << "1. Insertar precio" << endl;
	cout << "2. Mostrar intervalo promedio de precios" << endl;
	cout << "3. Mostrar precios" << endl;
	cout << "4. Salir" << endl;
	cout << "Ingrese una opcion: ";
}

//Validacion
bool esValido(double precio) {
	return precio >= 1.00 && precio <= 9999.99;
}

int main() {
	InventarioProductos inventario;
	int op;
	double precio;
	do {
		system("cls");
		menu();
		cin >> op;
		switch (op) {
		case 1:
			cout << "Ingrese precio a insertar (Solo valores positivos con dos decimales entre 1.00 y 9999.99): ";
			while (true) {
				cin >> precio;
				if (cin.fail()) {
					cout << "Entrada invalida. Por favor ingrese un numero entero." << endl;
					cin.clear();
					cin.ignore(numeric_limits<double>::max(), '\n');
					continue;
				}
				if (!esValido(precio)) {
					cout << "Valor fuera del rango permitido. Terminando entrada de valores." << endl;
					break;
				}
				inventario.insertarPrecio(precio);
			}
			break;
		case 2:
			cout << "=== INTERVALO PROMEDIO DE PRECIOS ===" << endl;
			cout << "Ingrese un valor para calcular el promedio del rango: " << endl;
			cin >> precio;
			cout << "Promedio del rango: " << inventario.promedioIntervalo(precio) << endl;
			cin.ignore();
			cin.get();
			break;
		case 3:
			cout << "=== PRECIOS EN ORDEN ===" << endl;
			inventario.mostrarPrecios();
			cin.ignore();
			cin.get();
			break;
		}
	} while (op != 4);
	system("pause>0");
}