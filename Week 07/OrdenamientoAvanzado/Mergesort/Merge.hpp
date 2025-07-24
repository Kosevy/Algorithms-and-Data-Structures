#ifndef __MERGE_HPP__
#define __MERGE_HPP__

void Merge(int *A1, int *A2, int *A, int n) {
	int i = 0, j = 0, k = 0;
	int mitad = n / 2;
	while (i < mitad && j < n - mitad) {
		if (A1[i] < A2[j]) {
			A[k] = A1[i];
			i++;k++;
		}
		else {
			A[k] = A2[j];
			j++;k++;
		}
	}
	while (i < mitad) {
		A[k] = A1[i];
		i++;k++;
	}
	while (j < n - mitad) {
		A[k] = A2[j];
		j++;k++;
	}
}


#endif // !__MERGE_HPP__

