#include<iostream>
#include "MergeSort.hpp"
using namespace std;

int main() {
	int arreglo[] = { 3,1,4,1,5,9,2,6 };
	int n = 8;

	mergeSort(arreglo, n);

	for (int i = 0;i < n;i++) {

		cout << arreglo[i] << " ";
	}


	system("pause");
	return 0;
}