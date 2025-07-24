#include <iostream>
#include "HashTablaAbierto.h"
#include "HashEntidad.hpp"

using namespace std;

// Simple main
int main()
{
	HashTablaA ht = HashTablaA();
	ht.insert(HashEntidad(1000,680));
	ht.insert(HashEntidad(1500, 100));
	ht.insert(HashEntidad(950, 68));
		
		
	cout << "Vista de la tabla Hash:" << endl;
	ht.DispAll();

	cin.get();
	return 0;
}