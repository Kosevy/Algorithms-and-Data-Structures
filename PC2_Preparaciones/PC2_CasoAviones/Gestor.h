#pragma once
#include "Utilidades.h"

int datosCant;

struct Vuelo {
	int registro;
	int idAerolinea;
	int idVuelo;
	string matriculaStr;

    Vuelo(int r = 0, int iA = 0, int iV = 0, string ms = "")
        : registro(r), idAerolinea(iA), idVuelo(iV), matriculaStr(ms) {
    }
};

/* c. MergeSort */
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


/*d. HashTable */
class HashTable {
private:
    static const int TAMANO = 100;
    vector<pair<pair<int, int>, string>> tabla[TAMANO];

    int funcionHash(int clave) {
        return clave % TAMANO;
    }

public:
    void insertar(int modelo, int marca, string matricula) {
        int clave = modelo + marca;
        int indice = funcionHash(clave);
        tabla[indice].push_back({ {modelo, marca}, matricula });
    }

    bool buscar(int modelo, int marca, string& color) {
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



/* b. Indexar idAerolinea */


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



/* a. Generar datos y almacenar en vector*/
vector<Vuelo> generarDatos(int datosCant) {
    vector<string> letras = { "AB", "VD", "GB", "TG", "YH",
                               "WE", "QZ", "CD", "PY" };
    vector<Vuelo> vuelos;

    srand(static_cast<unsigned>(time(0)));

    int cantidad = 100 + rand() % (5000 - 100 + 1);

    for (int i = 0; i < cantidad; ++i) {
        string letra = letras[rand() % letras.size()];
        int idRegistro = rand() % 100 + 1;
        int idAerolinea = 1000 + rand() % (9999 + 1 - 1000);
        int idVuelo = 10000 + rand() % (99999 + 1 - 10000);
        int idMatricula = 10 + rand() % (99 + 1 - 10);

        vuelos.emplace_back(i + 1, idAerolinea, idVuelo, letra + to_string(idMatricula));
    }

    return vuelos;
}