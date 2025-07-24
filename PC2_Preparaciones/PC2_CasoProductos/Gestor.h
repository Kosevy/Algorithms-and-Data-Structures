#include "Utilidades.h"

struct Producto {
    int id;
    string nombre;
    int stock;
    int marca;
    int modelo;
    int color;

    Producto(int i = 0, string n = "", int s = 0, int ma = 0, int mo = 0, int c = 0)
        : id(i), nombre(n), stock(s), marca(ma), modelo(mo), color(c) {}
};

/* 1. MERGESORT */
template<typename T>
void mergeSort(vector<T>& arr, int izq, int der, function<bool(const T&, const T&)> comparador) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;

        mergeSort(arr, izq, medio, comparador);
        mergeSort(arr, medio + 1, der, comparador);

        int n1 = medio - izq + 1;
        int n2 = der - medio;

        vector<T> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[izq + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[medio + 1 + j];

        int i = 0, j = 0, k = izq;

        while (i < n1 && j < n2) {
            if (comparador(L[i], R[j])) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

/* 2. BUSQUEDA BINARIA */
template<typename T>
int busquedaBinaria(const vector<T>& arr, const T& valor, function<int(const T&, const T&)> comparador) {
    int inicio = 0;
    int fin = arr.size() - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == valor)
            return medio;
        else if (comparador(arr[medio], valor) < 0)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }

    return -1;
}

/* 3. HASH TABLE */
class HashTable {
private:
    static const int TAMANO = 100;
    vector<pair<pair<int, int>, int>> tabla[TAMANO];

    int funcionHash(int clave) {
        return clave % TAMANO;
    }

public:
    void insertar(int modelo, int marca, int color) {
        int clave = modelo + marca;
        int indice = funcionHash(clave);
        tabla[indice].push_back({ {modelo, marca}, color });
    }

    bool buscar(int modelo, int marca, int& color) {
        int clave = modelo + marca;
        int indice = funcionHash(clave);

        for (const auto& par : tabla[indice]) {
            if (par.first.first == modelo && par.first.second == marca) {
                color = par.second;
                return true;
            }
        }
        return false;
    }

    void mostrar() {
        for (int i = 0; i < TAMANO; i++) {
            if (!tabla[i].empty()) {
                cout << "[" << i << "] ";
                for (const auto& par : tabla[i]) {
                    cout << "(" << par.first.first << " " << par.first.second
                        << " : " << par.second << ") ";
                }
                cout << endl;
            }
        }
    }
};

/* 4. ARBOL BINARIO DE BUSQUEDA */
struct NodoArbol {
    int valor;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

    NodoArbol(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolBinarioBusqueda {
private:
    NodoArbol* raiz;

    NodoArbol* insertarRec(NodoArbol* nodo, int valor) {
        if (nodo == nullptr)
            return new NodoArbol(valor);

        if (valor < nodo->valor)
            nodo->izquierdo = insertarRec(nodo->izquierdo, valor);
        else if (valor > nodo->valor)
            nodo->derecho = insertarRec(nodo->derecho, valor);

        return nodo;
    }

    NodoArbol* encontrarMinimo(NodoArbol* nodo) {
        while (nodo->izquierdo != nullptr)
            nodo = nodo->izquierdo;
        return nodo;
    }

    NodoArbol* eliminarRec(NodoArbol* nodo, int valor, bool& eliminado) {
        if (nodo == nullptr)
            return nullptr;

        if (valor < nodo->valor)
            nodo->izquierdo = eliminarRec(nodo->izquierdo, valor, eliminado);
        else if (valor > nodo->valor)
            nodo->derecho = eliminarRec(nodo->derecho, valor, eliminado);
        else {
            // Nodo con un solo hijo o sin hijos
            if (nodo->izquierdo == nullptr) {
                NodoArbol* temp = nodo->derecho;
                delete nodo;
                eliminado = true;
                return temp;
            }
            else if (nodo->derecho == nullptr) {
                NodoArbol* temp = nodo->izquierdo;
                delete nodo;
                eliminado = true;
                return temp;
            }

            // Nodo con dos hijos
            NodoArbol* temp = encontrarMinimo(nodo->derecho);
            nodo->valor = temp->valor;
            nodo->derecho = eliminarRec(nodo->derecho, temp->valor, eliminado);
        }
        return nodo;
    }

	void preOrdenRec(NodoArbol* nodo, vector<int>& resultado) {
		if (nodo != nullptr) {
			resultado.push_back(nodo->valor);
			preOrdenRec(nodo->izquierdo, resultado);
			preOrdenRec(nodo->derecho, resultado);
		}
	}

    void inOrdenRec(NodoArbol* nodo, vector<int>& resultado) {
        if (nodo != nullptr) {
            inOrdenRec(nodo->izquierdo, resultado);
            resultado.push_back(nodo->valor);
            inOrdenRec(nodo->derecho, resultado);
        }
    }

	void postOrdenRec(NodoArbol* nodo, vector<int>& resultado) {
		if (nodo != nullptr) {
			postOrdenRec(nodo->izquierdo, resultado);
			postOrdenRec(nodo->derecho, resultado);
			resultado.push_back(nodo->valor);
		}
	}

    NodoArbol* encontrarMaximo(NodoArbol* nodo) {
        while (nodo != nullptr && nodo->derecho != nullptr)
            nodo = nodo->derecho;
        return nodo;
    }

public:
    ArbolBinarioBusqueda() : raiz(nullptr) {}

    void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }

    bool eliminar(int valor) {
        bool eliminado = false;
        raiz = eliminarRec(raiz, valor, eliminado);
        return eliminado;
    }

    vector<int> preOrden() {
        vector<int> resultado;
        preOrdenRec(raiz, resultado);
        return resultado;
    }

    vector<int> inOrden() {
        vector<int> resultado;
        inOrdenRec(raiz, resultado);
        return resultado;
    }

	vector<int> postOrden() {
		vector<int> resultado;
		postOrdenRec(raiz, resultado);
		return resultado;
	}

    NodoArbol* obtenerRaiz() {
        return raiz;
    }

    NodoArbol* encontrarMaximo() {
        return encontrarMaximo(raiz);
    }
};

/* 5. MOSTRAR SI EL NODO MAYOR ES CAPICUA */
bool esCapicuaTresCifras(int numero) {
    if (numero < 100 || numero > 999)
        return false;

    int centenas = numero / 100;
    int unidades = numero % 10;

    return centenas == unidades;
}

/* GENERAR DATOS */
vector<Producto> generarDatos(int cantidad) {
    vector<string> nombres = { "item1", "item2", "item3", "item4", "item5",
                               "item6", "item7", "item8", "item9", "item10" };
    vector<Producto> productos;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < cantidad; ++i) {
        string nombre = nombres[rand() % nombres.size()];
        int stock = rand() % 100 + 1;
        int marca = rand() % 20 + 1;
        int modelo = rand() % 50 + 1;
        int color = rand() % 10 + 1;

        productos.emplace_back(i + 1, nombre, stock, marca, modelo, color);
    }

    return productos;
}

/* MENU PRINCIPAL */
void menu() {
    system("cls");
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Ordenar productos por stock (MergeSort)" << endl;
    cout << "2. Buscar producto por marca (Busqueda Binaria)" << endl;
    cout << "3. Mostrar tabla hash" << endl;
    cout << "4. Mostrar arbol binario de busqueda (In-Orden)" << endl;
    cout << "5. Verificar si el nodo mayor es capicua" << endl;
    cout << "6. Eliminar un nodo del arbol" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}