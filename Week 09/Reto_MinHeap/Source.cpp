#include <iostream>
using namespace std;

#include "Heap.h"

int main() {

	cout << "\n=== EJEMPLO MAX-HEAP ===" << endl;
	int A[10] = { 16,14,10,8,7,19,3,2,4,1 };

	cout << "Arreglo original: "; print(A, 10);
	cout << endl;

	cout << "Seleccion de Raiz: "; buildMaxHeap(A, 10);
	print(A, 10);
	cout << endl;

	heapsortMAX(A, 10);
	cout << "Arreglo Max-Heap: "; print(A, 10);
	cout << endl;

	//

	cout << "\n=== EJEMPLO MIN-HEAP ===" << endl;
	int B[10] = { 16,14,10,8,7,19,3,2,4,1 };

	cout << "Arreglo original: "; print(B, 10);
	cout << endl;

	cout << "Seleccion de Raiz: "; buildMinHeap(B, 10);
	print(B, 10);
	cout << endl;

	heapsortMIN(B, 10);
	cout << "Arreglo Min-Heap: "; print(B, 10);
	cout << endl;

	cin.ignore();
	cin.get();
	return 0;
}