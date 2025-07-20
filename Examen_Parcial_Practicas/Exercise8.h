#include "Utilidades.h"

int particion(vector<int>& arreglo, int inicio, int final) {
	int pivote = arreglo[inicio];
	int i = inicio + 1;
	for (int j = i; j <= final; j++) {
		if (arreglo[j] < pivote) {
			swap(arreglo[i], arreglo[j]);
			i++;
		}
	}
	swap(arreglo[inicio], arreglo[i - 1]);
	return i - 1;
}

void quickSort(vector<int>& array, int inicio, int final) {
	if (inicio < final) {
		int pivote = particion(array, inicio, final);
		quickSort(array, inicio, pivote - 1);
		quickSort(array, pivote + 1, final);
	}
}

void imprimirArreglo(vector<int>arreglo) {
	for (int i = 0; i < arreglo.size(); i++) {
		cout << arreglo[i] << " ";
	}
	cout << endl;
    cin.ignore();
}

void pregunta8() {
    vector<int>arreglo;
    int op8;

    do {
        Console::Clear();
        cout << "\n=== Ordenamiento QuickSort ===" << endl;
        cout << "1. Generar arreglo aleatorio" << endl;
        cout << "2. Ingresar arreglo manualmente" << endl;
        cout << "3. Ordenar arreglo" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op8;
        cin.ignore();

        switch (op8) {
                int n;
            case 1:
                cout << "Ingrese el tamano del arreglo: ";
                cin >> n;
                srand(time(0));
                for (int i = 0; i < n; i++) {
                    arreglo.push_back(rand() % 100);
                }
                cout << "Arreglo generado: ";
                imprimirArreglo(arreglo);
                cin.ignore();
                break;
            case 2:
                cout << "Ingrese el tamano del arreglo: ";
                cin >> n;
                arreglo.resize(n);
                for (int i = 0; i < n; i++) {
                    cout << "Ingrese el elemento " << i + 1 << ": ";
                    cin >> arreglo[i];
                }
                cout << "Arreglo ingresado: ";
                imprimirArreglo(arreglo);
                cin.ignore();
                break;
            case 3:
                if (arreglo.empty()) {
                    cout << "Error: Primero debe generar o ingresar un arreglo" << endl;
                    cin.ignore();
                    break;
                }
				cout << "Arreglo original: ";
				imprimirArreglo(arreglo);
                quickSort(arreglo, 0, arreglo.size() - 1);
                cout << "Arreglo ordenado: ";
                imprimirArreglo(arreglo);  
                break;
            case 4:
                cout << "Volviendo al menu principal..." << endl;
                cin.ignore();
                break;
            default:
                cout << "Error, intente de nuevo" << endl;
        }
    } while (op8 != 4);
}