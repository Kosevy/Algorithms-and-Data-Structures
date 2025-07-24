#include <iostream>
#include "HashEntidad.hpp"
#include "HashTabla.hpp"

using namespace std;

void imprimirTablaHash(HashTabla *ht,int*keys) {
	cout << "SIZE TABLA: " << ht->size()<<endl;
	cout << "SIZE ACTUAL: " << ht->sizeactual() << endl;
	for (int i = 0; i < ht->size(); ++i) {
		cout << ht->buscar(keys[i])<< " : " <<keys[i] << endl;
	}
}

int main() {
	HashTabla *ht = new HashTabla(9);
	int keys[] = {6,34,67,92,8,5,3,2,15};
	ht->insertar(6, 60);
	ht->insertar(34, 340);
	ht->insertar(67, 160);
	ht->insertar(92, 360);
	ht->insertar(8, 120);
	ht->insertar(5, 452);
	ht->insertar(3, 422);
	ht->insertar(2, 952);
	ht->insertar(15, 752);

	imprimirTablaHash(ht, keys);

	cin.get();

	return 0;
}