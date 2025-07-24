#ifndef __QUICKSELECT_HPP__
#define __QUICKSELECT_HPP__
#include <iostream>

using namespace std;

int particion(int *A, int p, int r) {
	int x = A[r]; //el pivote
	int i = p - 1; //indice de los menores
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int quickselect(int *A, int p, int r, int k) {
	if (p == r) return A[p];
	//indice del pivote con A ordenado Izq(Menores) Der(Mayores) al pivote
	int q = particion(A, p, r); 
	int l = q - p + 1; //nro elementos del sub arreglo donde se encuentra el kesimo elemento
	if (k == l)
		return A[q];
	else if (k < l) {
		return quickselect(A, p, q - 1, k);
	}
	else {
		return quickselect(A, q + 1, r, k - l);
	}


}


#endif // !__QUICKSELECT_HPP__

