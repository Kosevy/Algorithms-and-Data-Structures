#ifndef __LISTAS_H__
#define __LISTAS_H__

template <class T>
class ListaS {
	//------------
	struct Nodo {
		T elem;
		Nodo* next;
		Nodo(T elem = 0, Nodo* next = nullptr) : elem(elem), next(next) {}
	};
	//-----
	Nodo* inicio;
	int n;
public:
	//-----------------------Inner Class---------------
	class Iterador {		
		Nodo* aux;
				
	public:		
		Iterador(Nodo* aux = nullptr) : aux(aux) {}
		void operator ++ () { aux = aux->next; }
		bool operator != (Iterador it) { return aux != it.aux; }
		T operator* () { return aux->elem; }
	};
	//---------------------Inner Class------------------
	//public:
		ListaS();
		~ListaS();
		Iterador inicial() { return Iterador(inicio); };
		Iterador ultimo() { return Iterador(nullptr); };
		bool insertarInicio(T elem);
		bool insertar(T elem, int p);
		bool insertarFinal(T elem);
		bool eliminarInicio();
		int tamanio();
};
//----------------------------------------------
template <class T>
ListaS<T>::ListaS() {
	n = 0;
	inicio = nullptr;
}

//----------------------------------------------
template <class T>
ListaS<T>::~ListaS() {
	while (inicio != nullptr) {
		Nodo* aux = inicio;
		inicio = inicio->next;
		delete aux;
	}
}

//----------------------------------------------
template <class T>
int ListaS<T>::tamanio() { // size()
	return n;
}

//----------------------------------------------
template <class T>
bool ListaS<T>::insertarInicio(T elem) { // push_front()
	Nodo* nuevo = new Nodo(elem, inicio);
	if (nuevo == nullptr) return false;
	inicio = nuevo;
	++n;
	return true;
}

//----------------------------------------------  
template <class T>
bool ListaS<T>::insertar(T elem, int p) { // insert*
	if (p < 0 || p > n) return false;
	if (p == 0) insertarInicio(elem);
	int c = 1;
	Nodo* aux = inicio;
	while (c++ < p) {
		aux = aux->next;
	}
	Nodo* nuevo = new Nodo(elem, aux->next);
	if (nuevo == nullptr) return false;
	aux->next = nuevo;
	++n;
	return true;
}

//----------------------------------------------  
template <class T>
bool ListaS<T>::insertarFinal(T elem) { // push_back()
	insertar(elem, n);
}
//----------------------------------------------  
template <class T>
bool ListaS<T>::eliminarInicio() {
	if (n == 0) return false;
	Nodo* aux = inicio;
	inicio = inicio->next;
	delete aux;
	--n;
	return true;
}
//----------------------------------------------
#endif