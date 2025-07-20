#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ESTACIONES = 6;

class Electricidad{
private:
    string estaciones[MAX_ESTACIONES];
    int capacidades[MAX_ESTACIONES];
    int matrizEnlaces[MAX_ESTACIONES][MAX_ESTACIONES];
    int total;

public:
    Electricidad() {
        total = MAX_ESTACIONES;
        srand((unsigned)time(nullptr));
        // Inicializar estaciones y matriz de enlaces
        for (int i = 0; i < total; i++) {
            estaciones[i] = "E" + to_string(i + 1);
            capacidades[i] = 1000 + rand() % 4001; // capacidad entre 1000 y 5000
            for (int j = 0; j < total; j++) {
                matrizEnlaces[i][j] = 0;
            }
        }
    }

    void registro_aleatorio() {
        // Crear enlaces aleatorios
        for (int i = 0; i < total; i++) {
            int conexiones = rand() % 4; // 0 a 3 enlaces
            for (int c = 0; c < conexiones; c++) {
                int j = rand() % total;
                if (i != j && matrizEnlaces[i][j] == 0) {
                    int consumo = 50 + rand() % 251; // 50-300 kWh
                    matrizEnlaces[i][j] = consumo;
                    matrizEnlaces[j][i] = consumo; // grafo no dirigido
                }
            }
        }
    }

    void mostrarEstaciones() {
        cout << "Estaciones generadas y sus capacidades:\n";
        for (int i = 0; i < total; i++) {
            cout << estaciones[i] << " (" << capacidades[i] << " kWh)\n";
        }
        cout << endl;
    }

    void mostrarMatriz() {
        cout << "Matriz de consumos entre estaciones:\n    ";
        for (int i = 0; i < total; i++) {
            cout << estaciones[i] << "\t";
        }
        cout << "\n";

        for (int i = 0; i < total; i++) {
            cout << estaciones[i] << " ";
            for (int j = 0; j < total; j++) {
                cout << matrizEnlaces[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    void mostrarListaAdyacencia() {
        cout << "\nLista de adyacencia con consumos:\n";
        for (int i = 0; i < total; i++) {
            cout << estaciones[i] << " -> ";
            for (int j = 0; j < total; j++) {
                if (matrizEnlaces[i][j] > 0) {
                    cout << estaciones[j] << "(" << matrizEnlaces[i][j] << " kWh) ";
                }
            }
            cout << "\n";
        }
    }

    double promedioConsumo() {
        int suma = 0;
        int contador = 0;
        for (int i = 0; i < total; i++) {
            for (int j = i + 1; j < total; j++) {
                if (matrizEnlaces[i][j] > 0) {
                    suma += matrizEnlaces[i][j];
                    contador++;
                }
            }
        }
        return contador > 0 ? (double)suma / contador : 0.0;
    }
};
