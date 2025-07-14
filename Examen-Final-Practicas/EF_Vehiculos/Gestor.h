#pragma once
#include "Utilidades.h"

class Vehiculo {
public:
	int id;
	int marca;
	string marcaStr;
	int modelo;
	int color;
	int asiento;

	Vehiculo() : id(0), marca(0), marcaStr(""), modelo(0), color(0), asiento(0) {}
	Vehiculo(int id, int marca, string marcaStr, int modelo, int color, int asiento) : id(id), marca(marca), marcaStr(marcaStr), modelo(modelo), color(0), asiento(asiento) {}

	//Implementacion generador datos

	Vehiculo generadorDatos(int id) {
		Vehiculo vehiculo;
		vehiculo.id = id;
		vehiculo.marca = rand() % 4 + 1;
		switch (vehiculo.marca) {
		case 1:
			vehiculo.marcaStr = "Toyota";
			break;
		case 2:
			vehiculo.marcaStr = "Nissan";
			break;
		case 3:
			vehiculo.marcaStr = "Hyundai";
			break;
		case 4:
			vehiculo.marcaStr = "Mercedes";
			break;
		}
		vehiculo.modelo = rand() % 11;
		vehiculo.color = rand() % 4 + 1;
		vehiculo.asiento = rand() % 5 + 2;
		return vehiculo;
	}

	int getMarca() const { return marca; }
	string getMarcaStr() const { return marcaStr; }
	int getId() const { return id; }
};

// Implementacion con templates de ordenamiento avanzado: Quick-Sort
template <typename T, typename Compare>
int particion(vector<T>& A, int p, int r, Compare comp) {
	T pivote = A[r]; //el pivote
	int i = p - 1; //indice de los menores
	for (int j = p; j < r; j++) {
		if (comp(A[j], pivote)) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

// Implementaci�n de recursividad
template <typename T, typename Compare>
void quicksort(vector<T>& A, int p, int r, Compare comp) {
	int q; //para almacenar el indice del pivote

	if (p < r) {
		q = particion(A, p, r, comp); //devuelve el indice del pivote
		quicksort(A, p, q - 1, comp);
		quicksort(A, q + 1, r, comp);
	}
}

// Funcion para el criterio de comparacion
// Primero se prioriza el orden por el color
// Despu�s se prioriza el orden por el numero de asientos

bool comparacion(const Vehiculo& a, const Vehiculo& b) {
	if (a.color != b.color) {
		return a.color < b.color;
	}
	return a.asiento < b.asiento;
}

// Implementacion de busqueda binaria recursiva
int busqueda_binaria(Vehiculo* arreglo[], int limite_ini, int limite_fin, int marca_buscar)
{
	if (limite_fin >= limite_ini)
	{
		int mitad = limite_ini + (limite_fin - limite_ini) / 2;
		int marca_actual = arreglo[mitad]->getMarca();

		if (marca_actual == marca_buscar) {
			// Encontramos una coincidencia, buscar la primera aparición
			int primer_indice = mitad;
			while (primer_indice > 0 && arreglo[primer_indice - 1]->getMarca() == marca_buscar) {
				primer_indice--;
			}
			return arreglo[primer_indice]->getId();
		}

		if (marca_actual > marca_buscar) {
			return busqueda_binaria(arreglo, limite_ini, mitad - 1, marca_buscar);
		}
		return busqueda_binaria(arreglo, mitad + 1, limite_fin, marca_buscar);
	}
	return -1;
}