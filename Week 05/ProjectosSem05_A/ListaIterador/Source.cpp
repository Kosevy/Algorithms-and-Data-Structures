#include <iostream>
#include "lista.h"


using namespace std;

int main() {
	ListaS<int> l;

	for (int i = 0; i < 10; ++i) {		
		l.insertarInicio(i);
	}
	
	bool ini = true;
	for (ListaS<int>::Iterador it = l.inicial(); it != l.ultimo(); it++) {
		cout << (ini ? "" : ", ") << *it ;
		ini = false;
	}

	getchar();
	return 0;
}