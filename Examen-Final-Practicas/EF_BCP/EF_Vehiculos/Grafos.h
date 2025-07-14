#pragma once
#include "Utilidades.h"

class Grafo {
private:
	struct Vertice {
		int valor;
		vector <int> arcos;
	};

	vector<Vertice> vertices;

public:
	Grafo() {}

	// Primera Funcion
	void registro_aleatorio() {
		srand(time(0));

		vertices.clear();

		for (int i = 0; i < 8; i++) {
			Vertice v;
			v.valor = rand() % 999 + 1;

			int num_arcos;
			cout << "Ingrese el numero de arcos para el vertice" << v.valor << " (entre 0 y 4)";
			cin >> num_arcos;

			// Validacion de la entrada de valores para el numero de arcos
			while (num_arcos < 0 || num_arcos > 4 || cin.fail()) {
				cout << "Numero de arcos invalido. Por favor, ingrese un numero entre 0 y 4: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> num_arcos;
			}

			for (int j = 0; j < num_arcos; j++) {
				int arc_valor;
				cout << "Ingrese el varlo del arco" << (j + 1) << "(entre 10 y 900): ";
				cin >> arc_valor;

				// Validacion de la entrada de valores para un valor de arco
				while (arc_valor < 10 || arc_valor > 900 || cin.fail()) {
					cout << "Valor de arco invalido. Por favor, ingrese un numero entre 10 y 900";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> arc_valor;
				}
				
				v.arcos.push_back(arc_valor);
			}

			vertices.push_back(v);
		}
		cout << "--------------------------------------------------" << endl;

		// Mostrar el grafo 
		for (int i = 0; i < vertices.size(); i++) {
			cout << "Vertice " << vertices[i].valor << " tiene " << vertices[i].arcos.size() << " arcos: ";
			for (int j = 0; j < vertices[i].arcos.size(); j++) {
				cout << vertices[i].arcos[j] << " ";
			}
			cout << endl;
		}
	}

	// Segunda funcion
	int sumatoria_Arcos(int valor_vertice) {
		for (Vertice& v : vertices) {
			if (v.valor == valor_vertice) {
				int sum = 0;
				for (int arc : v.arcos) {
					sum += arc;
				}
			return sum;
			}
		}
		return -1;
	}
};