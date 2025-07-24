#ifndef __QUICKSORT_HPP__
#define __QUICKSORT_HPP__
#include <iostream>
using namespace std;

int particion(int *A, int p, int r) {
	int x = A[r]; //el pivote
	int i = p - 1; //indice de los menores
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(int *A, int p, int r) {
	int q; //para almacenar el indice del pivote

	if (p < r) {
		q = particion(A, p, r); //devuelve el indice del pivote
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

#endif // !__QUICKSORT_HPP__

