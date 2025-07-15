#pragma once
#include "Utilidades.h"

class Producto {
public:
	int id;
	int categoria;
	string categoriaStr;
	int stock;
	float precio;
	int fechaIngreso;
	string fechaIngresoStr;

	Producto() : id(0), categoriaStr(""), stock(0), precio(0), fechaIngresoStr("") {}
	Producto(int id, string categoriaStr, int stock, float precio, string fechaIngresoStr) : id(id), categoriaStr(categoriaStr), stock(stock), precio(precio), fechaIngresoStr(fechaIngresoStr) {}
	
	// Dataset
	Producto generarDatos(int id) {
		Producto producto;
		producto.id = id;
		producto.categoria = rand() % 5 + 1;
		switch (producto.categoria) {
		case 1:
			producto.categoriaStr = "Cereal";
			break;
		case 2:
			producto.categoriaStr = "Polo";
			break;
		case 3:
			producto.categoriaStr = "Tenis";
			break;
		case 4:
			producto.categoriaStr = "Laptop";
			break;
		case 5:
			producto.categoriaStr = "Cama";
			break;
		}

		producto.stock = rand() % 20 + 2;
		producto.precio = rand() % 250 + 100;
		producto.fechaIngreso = 1 + rand() % (6 + 1 - 1);
		switch (producto.fechaIngreso) {
		case 1:
			producto.fechaIngresoStr = "07-08-2025";
			break;
		case 2:
			producto.fechaIngresoStr = "10-10-2022";
			break;
		case 3:
			producto.fechaIngresoStr = "16-12-2024";
			break;
		case 4:
			producto.fechaIngresoStr = "11-04-2025";
			break;
		case 5:
			producto.fechaIngresoStr = "01-02-2027";
			break;
		case 6:
			producto.fechaIngresoStr = "07-05-2021";
			break;
		}
		return producto;
	}


};

//MergeSort
template<typename T>
void mergeSort(vector<T>& arr, int izq, int der, function<bool(const T&, const T&)> comparador) {
	if (izq < der) {
		int medio = izq + (der - izq) / 2;

		mergeSort(arr, izq, medio, comparador);
		mergeSort(arr, medio + 1, der, comparador);

		int n1 = medio - izq + 1;
		int n2 = der - medio;

		vector<T> L(n1), R(n2);

		for (int i = 0; i < n1; i++)
			L[i] = arr[izq + i];
		for (int j = 0; j < n2; j++)
			R[j] = arr[medio + 1 + j];

		int i = 0, j = 0, k = izq;

		while (i < n1 && j < n2) {
			if (comparador(L[i], R[j])) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}
	}
}