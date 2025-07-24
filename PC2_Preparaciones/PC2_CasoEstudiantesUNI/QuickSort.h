#pragma once
#ifndef __QUICKSORT_HPP__
#define __QUICKSORT_HPP__
#include "Utilidades.h"

template <typename T, typename Compare>
int particion(T* A, int p, int r, Compare comp) {
	T x = A[r]; //el pivote
	int i = p - 1; //indice de los menores
	for (int j = p; j < r; j++) {
		if (comp(A[j], x) || A[j] == x) { //comparacion usando lambda
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

template <typename T, typename Compare>
void quicksort(T* A, int p, int r, Compare comp) {
	if (p < r) {
		int q = particion(A, p, r, comp);
			quicksort(A, p, q - 1, comp);
			quicksort(A, q + 1, r, comp);
	}
}

// Sobrecarga para usar el operador < por defecto
template <typename T>
void quicksort(T* A, int p, int r) {
	quicksort(A, p, r, [](const T& a, const T& b) { return a < b; });
}

#endif // !__QUICKSORT_HPP__