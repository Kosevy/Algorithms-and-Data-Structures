#pragma once
#include "Utilidades.h"

class RedLaboratorios {
private:
	struct Vertice {
		int valor;
		vector <int> arcos;
	};

	vector<Vertice> vertices;

public:
	RedLaboratorios() {}

	// Primera Funcion
	void registro_aleatorio() {
		srand(time(0));

		vertices.clear();

		for (int i = 0; i < 6; i++) {
			Vertice v;
			v.valor = 100 + rand() % (999 + 1 - 100);

			int num_arcos = rand() % 3 + 1;

			for (int j = 0; j < num_arcos; j++) {
				int arc_valor = 60 + rand() % (99 + 1 - 99);

				v.arcos.push_back(arc_valor);
			}

			vertices.push_back(v);
		}

		// Mostrar Registro Aleatorio 
		for (int i = 0; i < vertices.size(); i++) {
			cout << "Laboratorio L" << i << ": Capacidad: " << vertices[i].valor << " Conexiones: " << vertices[i].arcos.size() << " Eficiencia de las redes: ";
			for (int j = 0; j < vertices[i].arcos.size(); j++) {
				cout << vertices[i].arcos[j] << " ";
			}
			cout << endl;
		}
	}
};