#pragma once
#include "Utilidades.h"
#include "HeapSort.h"
#include "HashTable.h"
#include "ListaEnlazada.h"

TablaHash tablaClientes;

//implementacion de clase registro

class Registro {
public:
	int dni;
	int nroTarjeta;
	float monto;
	int mes;
	int anio;
	int tipoOperacion;
	string tipoOperacionStr;

	Registro() : dni(0), nroTarjeta(0), monto(0), mes(0), anio(0), tipoOperacion(0){}
	Registro(int dni, int nroTarjeta, float monto, int mes, int anio, int tipoOperacion):
			dni(dni), nroTarjeta(nroTarjeta), monto(monto), mes(mes), anio(anio), tipoOperacion(tipoOperacion){}

	//generador de datos

	Registro generarRegistro(int dni) {
		Registro registro;
		registro.dni = dni; //dni 1, ...1000
		registro.nroTarjeta = rand() % 99999 + 10000;
		registro.monto = rand() % 5000 + 10.0;
		registro.mes = rand() % 12 + 1;
		registro.anio = rand() % 2025 + 2020;
		registro.tipoOperacion = rand() % 4 + 1;
		switch (registro.tipoOperacion) {
		case 1:
			registro.tipoOperacionStr = "Retiro";
			break;
		case 2:
			registro.tipoOperacionStr = "Deposito";
			break;
		case 3:
			registro.tipoOperacionStr = "Transferencia";
			break;
		case 4:
			registro.tipoOperacionStr = "Cambio de clave";
			break;
		}
		return registro;
	}
};

// Implementacion de recursividad con template para HeapSort
template <typename T>
void buildMaxHeap(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		maxHeapify(A, n, i);
	}
}

template <typename T>
void heapSort(int A[], int n) {
	if (n <= 1) return;

	buildMaxHeap(A, n);

	swap(A[0], A[n - 1]);

	heapSort(A, n - 1);
}

// Funcion para el criterio de comparacion
// Se prioriza el orden por MONTO

bool comparacion(const Registro& a, const Registro& b) {
	return a.monto < b.monto;
}

//Funcion para cargar registros en la tabla hash
void cargarEnTablaHash(const vector<Registro>& registros) {
	for (const auto& reg : registros) {
		// Usar el DNI como clave (convertido a string)
        // y el monto como valor (también convertido a string)
        tablaClientes.insertar(to_string(reg.dni), to_string(reg.monto));
	}
}

// Función para buscar un cliente por DNI
string buscarEnTablaHash(int dni) {
    return tablaClientes.buscar(to_string(dni));
}

// Función para mostrar la tabla hash
void mostrarTablaHash() {
    tablaClientes.mostrar();
}


// Funci�n para crear una lista enlazada de DNIs a partir de un vector de registros
// Utiliza la clase ListaEnlazada proporcionada por el docente
void crearListaEnlazadaDNI(const vector<Registro>& registros, ListaEnlazada& lista) {
	for (const auto& reg : registros) {
		lista.InsertarAlFinal(reg.dni);
	}
}