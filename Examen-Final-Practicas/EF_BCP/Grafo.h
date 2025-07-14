#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__
#include "Utilidades.h"

template<class T,T vacio=-1>
class CGrafo {
protected:
	class CArco {
	public:
		T info;
		int v; //indice del vertice de llegada
		CArco(int vLlegada) {
			info = vacio;
			v = vLlegada;
		}
	};
	class CVertice {
	public:
		T info;
		vector<CArco*>* ady; //Lista de adyacencia
		CVertice() {
			info = vacio;
			ady = new vector<CArco*>();
		}
	};
	//Lista de vértices
	vector<CVertice*>* vertices;

public:
	CGrafo() {
		vertices = new vector<CVertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		CVertice * vert = new CVertice();
		vert->info = info;
		vertices->push_back(vert);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int v) {
		return (vertices->at(v))->info;
	}
	void modificarVertice(int v, T info) {
		(vertices->at(v))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int v, int vLlegada) {
		CVertice* ver = vertices->at(v);
		//Crear el objeto ARCO
		CArco* arc = new CArco(vLlegada);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1;
	}
	
	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	T obtenerArco(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, T info) {
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	int obtenerVerticeLlegada(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; //indice del vertice de llegada
	}
};

class GrafoSedes : public CGrafo<int, -1> {
    protected:
        // Mapa para guardar los índices de las sedes
        map<string, int> indiceSedes;
        // Vector para guardar los nombres de las sedes
        vector<string> nombresSedes;

        CVertice* obtenerVerticePorIndice(int indice) {
            if (indice >= 0 && indice < (int)vertices->size()) {
                return vertices->at(indice);
            }
            return nullptr;
        }

        int cantidadTotalVertices() const {
            return vertices->size();
        }
        
    public:
        // Constructor que inicializa las 6 sedes
        GrafoSedes() {
            // Agregar las 6 sedes
            agregarSede("A");
            agregarSede("B");
            agregarSede("C");
            agregarSede("D");
            agregarSede("E");
            agregarSede("F");
            
            // Establecer conexiones con distancias (en km)
            // Puedes modificar estas conexiones según necesites
            conectarSedes("A", "B", 10);
            conectarSedes("A", "C", 15);
            conectarSedes("B", "C", 20);
            conectarSedes("B", "D", 25);
            conectarSedes("C", "E", 30);
            conectarSedes("D", "E", 15);
            conectarSedes("D", "F", 10);
            conectarSedes("E", "F", 20);
        }
        
        // Agregar una nueva sede
        void agregarSede(const string& nombre) {
            if (indiceSedes.find(nombre) == indiceSedes.end()) {
                int indice = adicionarVertice(0); // El valor 0 es un placeholder
                indiceSedes[nombre] = indice;
                if (indice >= nombresSedes.size()) {
                    nombresSedes.resize(indice + 1);
                }
                nombresSedes[indice] = nombre;
            }
        }
        
        // Conectar dos sedes con una distancia
        void conectarSedes(const string& origen, const string& destino, int distancia) {
            if (indiceSedes.find(origen) != indiceSedes.end() && 
                indiceSedes.find(destino) != indiceSedes.end()) {
                
                int indiceOrigen = indiceSedes[origen];
                int indiceDestino = indiceSedes[destino];
                
                // Agregar arco en ambas direcciones (grafo no dirigido)
                int pos1 = adicionarArco(indiceOrigen, indiceDestino);
                modificarArco(indiceOrigen, pos1, distancia);
                
                int pos2 = adicionarArco(indiceDestino, indiceOrigen);
                modificarArco(indiceDestino, pos2, distancia);
            }
        }
        
        // Mostrar la matriz de adyacencia con las distancias
        void mostrarMatrizAdyacencia() {
            cout << "\nMatriz de Adyacencia (Distancias en km):\n";
            cout << "   ";
            
            // Encabezado con los nombres de las sedes
            for (const auto& nombre : nombresSedes) {
                cout << setw(4) << nombre;
            }
            cout << "\n";
            
            // Filas de la matriz
            for (size_t i = 0; i < nombresSedes.size(); ++i) {
                cout << setw(3) << nombresSedes[i];
                
                for (size_t j = 0; j < nombresSedes.size(); ++j) {
                    int distancia = obtenerDistancia(i, j);
                    if (i == j) {
                        cout << setw(4) << "0";
                    } else if (distancia != -1) {
                        cout << setw(4) << distancia;
                    } else {
                        cout << setw(4) << "-";
                    }
                }
                cout << "\n";
            }
        }
        
        // Obtener la distancia entre dos sedes
        int obtenerDistancia(int origen, int destino) {
            if (origen < 0 || origen >= (int)nombresSedes.size() || 
                destino < 0 || destino >= (int)nombresSedes.size()) {
                return -1;
            }
            
            CVertice* vertice = obtenerVerticePorIndice(origen);
            for (size_t i = 0; i < vertice->ady->size(); ++i) {
                if (obtenerVerticeLlegada(origen, i) == destino) {
                    return obtenerArco(origen, i);
                }
            }
            return -1; // No hay conexión directa
        }
        
        // Mostrar la lista de adyacencia
        void mostrarListaAdyacencia() {
            cout << "\nLista de Adyacencia:\n";
            for (size_t i = 0; i < cantidadTotalVertices(); ++i) {
                cout << nombresSedes[i] << " -> ";
                CVertice* vertice = obtenerVerticePorIndice(i);
                for (size_t j = 0; j < vertice->ady->size(); ++j) {
                    int destino = obtenerVerticeLlegada(i, j);
                    int distancia = obtenerArco(i, j);
                    cout << "(" << nombresSedes[destino] << ", " << distancia << "km) ";
                }
                cout << "\n";
            }
        }
    };

#endif // !__GRAFO_HPP__

