#include "Utilidades.h"

template<class T>
class Nodo2 {
public:
    T dato;
    Nodo2<T>* siguiente;
    //constructor
    Nodo2(T valor, Nodo2<T>* sig = nullptr) {
        dato = valor;
        siguiente = sig;
    }
};


template<class T>
class Pila {
private:
	Nodo2<T>* tope;
public:
	Pila() : tope(nullptr) {} //forma estandar de usar constructor con pila

	void push(T valor) {
		tope = new Nodo2<T>(valor, tope);
	}

	bool pop(T& valor) {
		if (tope == nullptr) return false;
		valor = tope->dato; //puntero entra a dato
		Nodo2<T>* temp = tope;
		tope = tope->siguiente; //actualiza tope
		delete temp;
		return true; //libera memoria
	}

	bool estaVacia() { return tope == nullptr; } //si esta vacia retorna nullptr

	bool verTope(T& valor) {  //funcion peek
		if (estaVacia()) return false;
		valor = tope->dato;
		return true;
	}
};

class ValidarParentesis {
private:
    Pila<char> pila;
    bool isBracket(char c) {
        return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
    }
public:
    bool validar(const string& expresion) {
        if (expresion.empty()) return false;

		char valor;
        for (char c : expresion) {
            if (!isBracket(c)) continue;
            switch (c) {
                case '(':
                case '[':
                case '{':
                    pila.push(c);
                    break;
                case ')':
                    if (pila.estaVacia() || pila.verTope(valor) != '(') return false;
                    pila.pop(valor);
                    break;
                case ']':
                    if (pila.estaVacia() || pila.verTope(valor) != '[') return false;
                    pila.pop(valor);
                    break;
                case '}':
                    if (pila.estaVacia() ||pila.verTope(valor) != '{') return false;
                    pila.pop(valor);
                    break;
            }
        }
        return pila.estaVacia();
    }
};

void pregunta5() {
    ValidarParentesis validador;
    string expresion;
    
    do {
        cout << "\n===Validar parentesis balanceados===" << endl;
        cout << "Ingrese una expresion (o 'salir' para terminar): ";
        getline(cin, expresion);
        
        if (expresion == "salir") break;
        
        if (validador.validar(expresion)) {
            cout << "Los parentesis estan balanceados!" << endl;
        } else {
            cout << "Los parentesis NO estan balanceados!" << endl;
        }
        
        cout << "Presione Enter para continuar...";
        cin.ignore();
    } while (true);
}