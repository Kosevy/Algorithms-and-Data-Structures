#pragma once
#include "Cola.h"
#include "Pila.h"
#include "Utilidades.h"

class EstacionTren {
private:
	vector<int> vagonesOriginales;
	Cola<int> entrada;
	Pila<int> patio;
	Cola<int> salida;
	Pila<int> maniobras;
	int proximoEsperado;
	int movimientos;
public:
EstacionTren(int vagones[], int size) : proximoEsperado(1), movimientos(0) {
    for (int i = 0; i < size; i++) {
        entrada.encolar(vagones[i]);
		vagonesOriginales.push_back(vagones[i]);
    }
}

	void mostrarEstado() {
		int valor;
		cout << "Entrada: ["; if (entrada.verFrente(valor)) cout << valor; cout << "]" << endl;
		cout << "Patio: ["; if (patio.verTope(valor)) cout << valor; cout << "]" << endl;
		cout << "Salida: ["; if (salida.verFrente(valor)) cout << valor; cout << "]" << endl;
		cout << "Movimientos realizados: " << movimientos << endl; 
	}

	bool moverEntradaAPatio() {
		int vagon;
		if (entrada.desencolar(vagon)) {
			patio.push(vagon);
			movimientos++;
			return true;
		}
		return false;
	}
	
	bool moverPatioASalida() {
		int vagon;
		if (patio.pop(vagon)) {
			salida.encolar(vagon);
			movimientos++;
			return true;
		}
		return false;
	}

	bool moverEntradaASalidaDirecto() {
		int vagon;
		if (entrada.desencolar(vagon)) {
			salida.encolar(vagon);
			movimientos++;
			return true;
		}
		return false;
		
	}

	void autocompletar() {
		while (true) {
			int frenteEntrada;
			bool entradaTieneValor = entrada.verFrente(frenteEntrada);

			if (entradaTieneValor && frenteEntrada == proximoEsperado) {
				moverEntradaASalidaDirecto();
			} else {
				int topePatio;
				if (patio.verTope(topePatio) && topePatio == proximoEsperado) {
					moverPatioASalida();
				} else if (entradaTieneValor) {
					moverEntradaAPatio();
				} else {
					break;
				}
			}
		}
	}

	void reiniciarSimulacion() {
		// Vaciar el patio
		int valor;
		while (patio.verTope(valor)) {
			patio.pop(valor);
		}

		// Vaciar la salida
		while (salida.verFrente(valor)) {
			salida.desencolar(valor);
		}

		// Restaurar los vagones originales en la entrada
		for (int vagon : vagonesOriginales) {
			entrada.encolar(vagon);
		}

		proximoEsperado = 1;
		movimientos = 0;
	}
};