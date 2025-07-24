#include <iostream>
#include "ArbolAVL.hpp"

using namespace std;

void imprimir(int e) {
	cout << " " << e;
}

int main() {

	ArbolAVL <int>* tree;

	tree = new ArbolAVL<int>(imprimir);

	tree->Insertar(15);
	tree->Insertar(20);
	tree->Insertar(24);
	tree->Insertar(10);
	tree->Insertar(13);
	tree->Insertar(7);
	tree->Insertar(30);
	tree->Insertar(36);
	tree->Insertar(25);

	cout << "Impresion inOrden de elementos: " << endl;
	tree->inOrden();
	cout << endl;
	cout << "Impresion inOrden de alturas: " << endl;
	tree->inOrdenH();

	cin.get();

	return 0;
}