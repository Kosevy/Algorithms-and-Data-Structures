#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
using namespace std;

class Grafo {
    int numNodos;
    vector<vector<pair<int, int>>> adyacencia;

    // posiciones de ciudades en consola
    map<int, pair<int, int>> posiciones; // nodo -> (fila, columna)

public:
    Grafo(int n) {
        numNodos = n;
        adyacencia.resize(n);

        // posiciones 
        posiciones[0] = { 1, 5 };   // A
        posiciones[1] = { 1, 20 };  // B
        posiciones[2] = { 5, 10 };  // C
        posiciones[3] = { 10, 20 }; // D
        posiciones[4] = { 10, 5 };  // E
    }

    void agregarConexion(int origen, int destino, int distancia) {
        adyacencia[origen].push_back({ destino, distancia });
        adyacencia[destino].push_back({ origen, distancia });
    }

    void dijkstra(int inicio) {
        vector<int> distancia(numNodos, numeric_limits<int>::max());
        distancia[inicio] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> cola;
        cola.push({ 0, inicio });

        while (!cola.empty()) {
            int distActual = cola.top().first;
            int nodoActual = cola.top().second;
            cola.pop();

            for (auto vecino : adyacencia[nodoActual]) {
                int nodoVecino = vecino.first;
                int peso = vecino.second;

                if (distancia[nodoVecino] > distActual + peso) {
                    distancia[nodoVecino] = distActual + peso;
                    cola.push({ distancia[nodoVecino], nodoVecino });
                }
            }
        }

        cout << "\n Distancias mínimas desde la ciudad " << char('A' + inicio) << ":\n";
        for (int i = 0; i < numNodos; i++) {
            cout << "Hasta " << char('A' + i) << ": " << distancia[i] << " km\n";
        }
    }

    void dibujarMapa() {
        const int FILAS = 15, COLUMNAS = 30;
        vector<vector<char>> mapa(FILAS, vector<char>(COLUMNAS, ' '));

        for (int i = 0; i < numNodos; i++) {
            int x = posiciones[i].first;
            int y = posiciones[i].second;
            mapa[x][y] = 'A' + i;
        }

        cout << "\nMapa de ciudades:\n";
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                cout << mapa[i][j];
            }
            cout << '\n';
        }
    }
};

int main() {
    Grafo mapa(5); // A, B, C, D, E

    mapa.agregarConexion(0, 1, 4);  // A-B
    mapa.agregarConexion(0, 2, 2);  // A-C
    mapa.agregarConexion(1, 2, 5);  // B-C
    mapa.agregarConexion(1, 3, 10); // B-D
    mapa.agregarConexion(2, 4, 3);  // C-E
    mapa.agregarConexion(4, 3, 4);  // E-D

    mapa.dibujarMapa();
    mapa.dijkstra(0); // Desde ciudad A


    system("pause>0");
    return 0;
}
