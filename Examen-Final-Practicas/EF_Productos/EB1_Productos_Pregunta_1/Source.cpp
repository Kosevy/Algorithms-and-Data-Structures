#include "Gestor.h"

Producto pr;

vector<Producto> productos;

void mostrarMergeSort() {
	mergeSort<Producto>(productos, 0, productos.size() - 1,
		[](const Producto& a, const Producto& b) {
			return a.precio < b.precio;
		});

	cout << "\n=== Productos ordenados por Precio===\n";
	cout << "Precio \tID \tCategoria \tStock \tFecha de Ingreso \n";
	cout << "==============================================================" << endl;
	for (const auto& p : productos) {
		cout << p.precio << "\t" << p.id << "\t"
			<< p.categoriaStr << "\t\t" << p.stock <<
			"\t" << p.fechaIngresoStr << endl;
	}
	cin.ignore();
}

int main() {
	srand(time(0));

	for (int i; i < 250; i++) {
		productos.push_back(pr.generarDatos(i + 1));
	}

	mostrarMergeSort();
	cin.ignore();
	cin.get();

	system("pause>0");
	return 0;
}