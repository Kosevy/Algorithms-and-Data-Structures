#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <iostream>
using namespace std;


int parent(int i) {
	return (i - 1) / 2;
}
int left(int i) {
	return 2 * i + 1;
}
int right(int i) {
	return 2 * i + 2;
}

void minHeapify(int A[], int n, int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if (l < n && A[l] < A[i]) {
		smallest = l;
	}
	if (r < n && A[r] < A[smallest]) {
		smallest = r;
	}
	if (smallest != i) {
		swap(A[i], A[smallest]);
		minHeapify(A, n, smallest);
	}
}

void buildMinHeap(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		minHeapify(A, n, i);
	}
}

void maxHeapify(int A[], int n, int i) {
	int l = left(i);
	int r = right(i);
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

void buildMaxHeap(int A[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		maxHeapify(A, n, i);
	}
}

void print(int A[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << A[i] << " ";
		//cout << endl;
	}
}

//aplicacion de ordenamiento
void heapsortMAX(int A[], int n) {
	buildMaxHeap(A, n);
	for (int i = n - 1; i > 0; --i) {
		swap(A[0], A[i]);
		maxHeapify(A, --n, 0);
	}
}

void heapsortMIN(int A[], int n) {
	buildMinHeap(A, n);
	for (int i = n - 1; i > 0; --i) {
		swap(A[0], A[i]);
		minHeapify(A, --n, 0);
	}
}

#endif // !__HEAP_HPP__

