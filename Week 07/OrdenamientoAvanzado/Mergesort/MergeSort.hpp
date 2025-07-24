#ifndef __MERGESORT_HPP__
#define __MERGESORT_HPP__
#include "Merge.hpp"

void mergeSort(int *A, int n) {
	if (n > 1) {
		int mitad = n / 2;
		int *A1 = new int[mitad];
		int *A2 = new int[n-mitad];

		for (int i = 0;i < mitad;i++) {
			A1[i] = A[i];
		}
		for (int i = mitad;i < n;i++) {
			A2[i-mitad] = A[i];
		}
		mergeSort(A1, mitad);
		mergeSort(A2, n - mitad);
		Merge(A1, A2, A, n);
	}
}



#endif
