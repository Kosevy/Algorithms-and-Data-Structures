#ifndef _SELECTION_UTIL_
#define _SELECTION_UTIL_
//-------------------------------------

void selectionSort(int*v, int n) {
	int pMenor;
	int menor;
	for (int i = 0; i < n - 1; ++i) {
		menor = v[i];
		pMenor = i;
		for (int j = i + 1; j < n; ++j) {
			if (v[j] < menor) {
				menor = v[j];
				pMenor = j;
			}
		}
		if (pMenor != i) {
			int temp = v[pMenor];
			v[pMenor] = v[i];
			v[i] = temp;
		}
	}
}

/*
 pm
  i j
  _______
  0 1 2 3
 {3,7,5,0}

*/
//-----------------------------------
void print(int* v, int n){
  for (int i = 0; i < n; ++i)
    std::cout << " " << v[i];
  std::cout << std::endl;
}
//-----------------------------------
#endif

