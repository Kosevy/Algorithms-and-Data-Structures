#pragma once
#ifndef __HEAP_HPP__
#define __HEAP_HPP__
#include "Utilidades.h"

int parent(int i) {
	return (i - 1) / 2;
}
int left(int i) {
	return 2 * i + 1;
}
int rigth(int i) {
	return 2 * i + 2;
}

template <typename T>
void maxHeapify(int A[], int n, int i) {
	int l = left(i);
	int r = rigth(i);
	int largest(0);
	if (l <= (n - 1) && A[l] > A[i]) {
		largest = l;
	}
	else
		largest = i;
	if (r <= (n - 1) && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		maxHeapify(A, n, largest);
	}
}

void print(int A[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << A[i] << " ";
		//cout << endl;
	}
}

#endif // !__HEAP_HPP__

