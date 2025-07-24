#include <iostream>
#include "Quicksort.hpp"

using namespace std;

int main() {

	int arreglo[] = {4,5,1,9,3,2};
	int n = 6;
	//r=n-1
	//(*A, p, r) 
	quicksort(arreglo, 0, n-1);
	cout << "Arreglo ordenado por quicksort" << endl;
	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}

	cin.ignore();
	cin.get();

	return 0;
}