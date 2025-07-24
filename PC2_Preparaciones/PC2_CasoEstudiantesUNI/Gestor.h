#pragma once
#include "Utilidades.h"
#include "Nodo.h"
#include "QuickSort.h"
#include "BSTEstudiantes.h"
#include "HashTable.h"
#include "BinarySearch.h"

struct Estudiante {
	int id;
	int edad;
	string nombreStr;
	int nombre;
	string programaStr; //1 -> maestria | 2-> doctorado
	int programa;
	int promedio;

	bool operator==(const Estudiante& otro) const {
		return id == otro.id;
	}

	int operator-(const Estudiante& otro) const {
		return id - otro.id;
	}
};

Estudiante generarEstudianteAleatorio(){
	Estudiante estudiante;
	estudiante.id = 10 + rand() % (999 + 1 - 10);
	estudiante.edad = 18 + rand() % (30 + 1 - 18);
	estudiante.promedio = rand() % 20 + 1;
	estudiante.programa = rand() % 2 + 1;

	switch (estudiante.programa) {
	case 1:
		estudiante.programaStr = "Maestria";
		break;
	case 2:
		estudiante.programaStr = "Doctorado";
		break;
	}

	estudiante.nombre = rand() % 8 + 1;

	switch (estudiante.nombre) {
	case 1:
		estudiante.nombreStr = "Anye";
		break;
	case 2:
		estudiante.nombreStr = "Benicio";
		break;
	case 3:
		estudiante.nombreStr = "Carlos";
		break;
	case 4:
		estudiante.nombreStr = "Juan";
		break;
	case 5:
		estudiante.nombreStr = "Vilma";
		break;
	case 6:
		estudiante.nombreStr = "Wido";
		break;
	case 7:
		estudiante.nombreStr = "Diego";
		break;
	case 8:
		estudiante.nombreStr = "Sergio";
		break;
	}
	return estudiante;
}

template <typename T>
class ListaEnlazada {
private:
	Nodo<T>* cabeza;
	Nodo<T>* actual;

	TablaHash promedio;
	BSTEstudiantes<Estudiante>* arbolEstudiantes;
public:
	ListaEnlazada() : cabeza(nullptr), actual(nullptr) {
		//inicializa con imprimir y comparar
		arbolEstudiantes = new BSTEstudiantes<Estudiante>(
			[](Estudiante e) { cout << e.id << endl; },
			[](Estudiante a, Estudiante b) {return a.id - b.id; }
		);
	}
	~ListaEnlazada() {
		Nodo<T>* temp = cabeza;
		while (temp != nullptr) {
			Nodo<T>* siguiente = temp->siguiente;
			delete temp;
			temp = siguiente;
		}
	}

	void agregar(const T& val) {
		Nodo<T>* nuevoNodo = new Nodo<T>(val);
		if (cabeza == nullptr) {
			cabeza = nuevoNodo;
			actual = cabeza;
		}
		else {
			actual->siguiente = nuevoNodo;
			actual = nuevoNodo;
		}

		if (val.id % 2 == 0) {
			arbolEstudiantes->insertar(val);
		}
	}

	void mostrar() {
		Nodo<T>* temp = cabeza;
		while (temp != nullptr) {
			cout << "=== DATOS DE LA PERSONA ===" << endl;
			cout << "NOMBRE: " << temp->valor.nombreStr << endl;
			cout << "ID: " << temp->valor.id << endl;
			cout << "EDAD: " << temp->valor.edad << endl;
			cout << "PROMEDIO: " << temp->valor.promedio << endl;
			cout << "PROGRAMA: " << temp->valor.programaStr << endl;
			cout << "===========================" << endl;
			cout << endl;
			temp = temp->siguiente;
		}
	}

	//QUICKSORT

	void mostraOrdenPorEdad() {
		if (cabeza == nullptr) return; //caso base

		// 1. Crea un arreglo de punteros a los nodos
		vector<Nodo<T>*> nodos;
		Nodo<T>* temp = cabeza;
		int n = 0;
		while (temp != nullptr) {
			nodos.push_back(temp);
			temp = temp->siguiente;
			n++;
		}

		// 2. Ordenar el arreglo usando qs
		quicksort(nodos.data(), 0, n-1, [](Nodo<T>* a, Nodo<T>* b) {
			return a->valor.edad < b->valor.edad;
		});

		// 3. Se reconstruye la lista enlazada
		cabeza = nodos[0];
		for (int i = 0; i < n - 1; i++) {
			nodos[i]->siguiente = nodos[i + 1];
		}
		nodos[n - 1]->siguiente = nullptr;

		// 4. Mostrar resultados

		cout << "==== Orden por edad de menor a mayor ====" << endl;
		temp = cabeza;
		while (temp != nullptr) {
			cout << "Edad: " << temp->valor.edad << " - Estudiante: " << temp->valor.nombreStr << endl;
			temp = temp->siguiente;
		}
		cout << "=========================================" << endl;
	}

	// BUSQUEDA BINARIA

	void buscarPrograma() {
		if (cabeza == nullptr) {
			cout << "La lista esta vacia." << endl;
			cin.ignore();
			return;
		}
	
		// 1. Crear vector para mantener los estudiantes y sus índices originales
		vector<pair<Estudiante, int>> estudiantesConIndice;
		Nodo<T>* temp = cabeza;
		int indice = 0;
	
		// 2. Llenar el vector con los estudiantes
		while (temp != nullptr) {
			estudiantesConIndice.push_back({temp->valor, indice});
			temp = temp->siguiente;
			indice++;
		}
	
		// 3. Ordenar por programa
		sort(estudiantesConIndice.begin(), estudiantesConIndice.end(),
			[](const pair<Estudiante, int>& a, const pair<Estudiante, int>& b) {
				return a.first.programa < b.first.programa;
			});
	
		// 4. Pedir valor a buscar
		int valorBuscar;
		cout << "Ingrese el programa a buscar (1 -> Maestria | 2 -> Doctorado): ";
		cin >> valorBuscar;
	
		// 5. Validar entrada
		if (valorBuscar != 1 && valorBuscar != 2) {
			cout << "\nError: El programa debe ser 1 (Maestria) o 2 (Doctorado)" << endl;
			cin.ignore();
			return;
		}
	
		// 6. Lambda para multiplicar por 3
		auto multiplicarPorTres = [](int x) { return x * 3; };
		int programaBuscado = multiplicarPorTres(valorBuscar);
	
		// 7. Búsqueda binaria
		int inicio = 0;
		int fin = estudiantesConIndice.size() - 1;
		int indiceEncontrado = -1;
		Estudiante estudianteEncontrado;
	
		while (inicio <= fin) {
			int medio = inicio + (fin - inicio) / 2;
			int programaActual = estudiantesConIndice[medio].first.programa;
	
			if (programaActual == programaBuscado) {
				indiceEncontrado = estudiantesConIndice[medio].second;
				estudianteEncontrado = estudiantesConIndice[medio].first;
				break;
			}
			if (programaActual < programaBuscado) {
				inicio = medio + 1;
			} else {
				fin = medio - 1;
			}
		}
	
		// 8. Mostrar resultados
		if (indiceEncontrado != -1) {
			cout << "\n=== ESTUDIANTE ENCONTRADO ===" << endl;
			cout << "Indice en la lista original: " << indiceEncontrado << endl;
			cout << "ID: " << estudianteEncontrado.id << endl;
			cout << "Nombre: " << estudianteEncontrado.nombreStr << endl;
			cout << "Programa: " << estudianteEncontrado.programa 
				 << " (" << estudianteEncontrado.programaStr << ")" << endl;
			cout << "Edad: " << estudianteEncontrado.edad << endl;
			cout << "Promedio: " << estudianteEncontrado.promedio << endl;
		} else {
			cout << "\nNo se encontro ningun estudiante en el programa " 
				 << valorBuscar << " (" 
				 << (valorBuscar == 1 ? "Maestria" : "Doctorado") << ")" << endl;
		}
		cout << "=============================" << endl;
		cin.ignore();
	}

	//HASH TABLE

	void mostrarPromedio() {
		cout << "==== Clave: ID + Edad | Valor: Promedio ====" << endl;
		Nodo<T>* temp = cabeza;
		while (temp != nullptr) {
			promedio.insertar(temp->valor.id, temp->valor.edad, temp->valor.promedio);
			temp = temp->siguiente;
		}
		promedio.mostrar();
		cout << "============================================" << endl;
	}

	// BST
	
	bool insertarEstudiante(Estudiante est) {
		if (est.id % 2 != 0) {
			return false;
		}
		return arbolEstudiantes->insertar(est);
	}

	void mostrarIDPares() {
		cout << "=== IDs Pares en el Arbol ===" << endl;
		arbolEstudiantes->recorrerEnOrden([](Estudiante e) {
			if (e.id % 2 == 0) {
				cout << "ID: " << e.id << " - Nombre: " << e.nombreStr << endl;
			}
			});
		cout << "============================" << endl;
	}

	void eliminarNodoPorID() {
		if (arbolEstudiantes == nullptr) {
			cout << "El arbol no ha sido inicializado." << endl;
			return;
		}

		cout << "=== Elementos actuales del arbol ===" << endl;
		arbolEstudiantes->enOrden();
		cout << "====================================" << endl;

		int idEliminar;
		cout << "Ingrese el ID del estudiante a eliminar: "; cin >> idEliminar;

		if (idEliminar >= 10 && idEliminar <= 999) {
			Estudiante temp;
			temp.id = idEliminar;

			if (arbolEstudiantes->Eliminar(temp)) {
				cout << "Estudiante con ID " << idEliminar << " eliminado exitosamente." << endl;
				cin.ignore();
			} else {
				cout << "No se encontró ningún estudiante con ID: " << idEliminar << " en el arbol." << endl;
				cin.ignore();
			}
		} else {
			cout << "No se puede eliminar. El ID debe tener exactamente 2 cifras (entre 10 y 999)" << endl;
			cin.ignore();
		}
	}

	void mostrarMayorID() {

		Estudiante mayor = arbolEstudiantes->Maximo();
		cout << "Mayor ID: " << mayor.id << " - Nombre: " << mayor.nombreStr << endl;

		if (mayor.id % 7 == 0 && mayor.id > 9 && mayor.id < 100) {
			cout << "El ID " << mayor.id << " es multiplo de 7 de dos cifras" << endl;
		}
		else {
			cout << "El ID " << mayor.id << " no es multiplo de 7 de dos cifras" << endl;
		}
	}

};