#pragma once
#include "Utilidades.h"
#ifndef __HEAP_HPP__
#define __HEAP_HPP__

int parent(int i) {
	return (i - 1) / 2;
}
int left(int i) {
	return 2 * i + 1;
}
int rigth(int i) {
	return 2 * i + 2;
}

template<typename T, typename Compare>
void maxHeapify(T A[], int n, int i, Compare comp) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && comp(A[l], A[largest])) largest = l;
	if (r < n && comp(A[r], A[largest])) largest = r;
	if (largest != i) {
		std::swap(A[i], A[largest]);
		maxHeapify(A, n, largest, comp);
	}
}

template<typename T, typename Compare>
void buildMaxHeap(T A[], int n, Compare comp) {
	for (int i = n / 2 - 1; i >= 0; --i)
		maxHeapify(A, n, i, comp);
}

void print(int A[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << A[i] << " ";
		//cout << endl;
	}
}

//aplicacion de ordenamiento
template<typename T, typename Compare>
void heapsort(T A[], int n, Compare comp) {
	buildMaxHeap(A, n, comp);
	for (int i = n - 1; i > 0; --i) {
		std::swap(A[0], A[i]);
		maxHeapify(A, i, 0, comp);
	}
}

#endif // !__HEAP_HPP__

