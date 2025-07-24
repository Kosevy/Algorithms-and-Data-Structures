#include<iostream>
#include "Quickselect.hpp"

using namespace std;

int main() {

	int arreglo[] = { 2,8,7,1,3,5,6,4 };
	int n = 8;
	int k = 5; //el kesimo menor elemento del arreglo

	int e = quickselect(arreglo, 0, n - 1, k);

	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}

	cout << "El kesimo elemento es: " << e;

	cin.ignore();
	cin.get();
	return 0;
}