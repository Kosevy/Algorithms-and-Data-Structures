#include<iostream>
#include <vector>
using namespace std;
#include "BinarySearch.hpp"

int main() {
	vector<int> A = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	BinarySearch<int> bs;

	//int resp = bs.binarySearch(A, 10);
	int resp = bs.binarySearchMejor(A, 9);

	cout << "Se encuentra en el indice: " << resp <<endl;

	cin.get();
	return 0;
}