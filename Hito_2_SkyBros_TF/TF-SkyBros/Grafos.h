#pragma once
#include "pch.h"
#include "conio.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <string>
using namespace System;
using namespace std;

class GrafoTransferAeropuerto {
private:
    int numNodos;
    vector<vector<pair<int, int>>> adyacencia; // destino, costo
    vector<string> nombresCiudades;
    map<int, pair<int, int>> posicionesConsola; // para dibujar el mapa
    map<string, int> indiceCiudades; // nombre -> indice

    void inicializarCiudades() {
        nombresCiudades = {
            "Aeropuerto Jorge Chavez",  // 0
            "Centro Lima",              // 1
            "Miraflores",              // 2
            "San Isidro",              // 3
            "Barranco",                // 4
            "Callao Puerto",           // 5
            "La Molina",               // 6
            "Surco"                    // 7
        };

        // Crear mapa de indices
        for (int i = 0; i < nombresCiudades.size(); i++) {
            indiceCiudades[nombresCiudades[i]] = i;
        }

        // Posiciones para el mapa visual (fila, columna)
        posicionesConsola[0] = { 3, 5 };   // Aeropuerto
        posicionesConsola[1] = { 6, 15 };  // Centro Lima
        posicionesConsola[2] = { 8, 25 };  // Miraflores
        posicionesConsola[3] = { 6, 22 };  // San Isidro
        posicionesConsola[4] = { 10, 25 }; // Barranco
        posicionesConsola[5] = { 2, 2 };   // Callao
        posicionesConsola[6] = { 10, 35 }; // La Molina
        posicionesConsola[7] = { 8, 30 };  // Surco
    }

    void cargarConexiones() {
        // Conexiones desde Aeropuerto Jorge Chavez
        agregarConexion(0, 1, 45);  // Aeropuerto -> Centro Lima (45 soles)
        agregarConexion(0, 2, 55);  // Aeropuerto -> Miraflores (55 soles)
        agregarConexion(0, 3, 50);  // Aeropuerto -> San Isidro (50 soles)
        agregarConexion(0, 5, 25);  // Aeropuerto -> Callao (25 soles)

        // Conexiones entre distritos
        agregarConexion(1, 2, 20);  // Centro -> Miraflores
        agregarConexion(1, 3, 15);  // Centro -> San Isidro
        agregarConexion(2, 3, 10);  // Miraflores -> San Isidro
        agregarConexion(2, 4, 12);  // Miraflores -> Barranco
        agregarConexion(2, 7, 18);  // Miraflores -> Surco
        agregarConexion(3, 7, 22);  // San Isidro -> Surco
        agregarConexion(4, 7, 15);  // Barranco -> Surco
        agregarConexion(6, 7, 20);  // La Molina -> Surco
        agregarConexion(1, 6, 35);  // Centro -> La Molina
    }

public:
    GrafoTransferAeropuerto() {
        numNodos = 8; // 8 ubicaciones
        adyacencia.resize(numNodos);
        inicializarCiudades();
        cargarConexiones();
    }

    void agregarConexion(int origen, int destino, int costo) {
        adyacencia[origen].push_back({ destino, costo });
        adyacencia[destino].push_back({ origen, costo }); // Bidireccional
    }

    vector<int> dijkstra(int inicio, vector<int>& predecesores) {
        vector<int> distancia(numNodos, numeric_limits<int>::max());
        predecesores.assign(numNodos, -1);

        distancia[inicio] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> cola;
        cola.push({ 0, inicio });

        while (!cola.empty()) {
            int distActual = cola.top().first;
            int nodoActual = cola.top().second;
            cola.pop();

            if (distActual > distancia[nodoActual]) continue;

            for (auto& vecino : adyacencia[nodoActual]) {
                int nodoVecino = vecino.first;
                int peso = vecino.second;

                if (distancia[nodoVecino] > distActual + peso) {
                    distancia[nodoVecino] = distActual + peso;
                    predecesores[nodoVecino] = nodoActual;
                    cola.push({ distancia[nodoVecino], nodoVecino });
                }
            }
        }

        return distancia;
    }

    void mostrarRuta(int inicio, int destino, const vector<int>& predecesores) {
        vector<int> ruta;
        int actual = destino;

        while (actual != -1) {
            ruta.push_back(actual);
            actual = predecesores[actual];
        }

        if (ruta.back() != inicio) {
            Console::SetCursorPosition(15, 20);
            cout << "No hay ruta disponible.";
            return;
        }

        Console::SetCursorPosition(15, 18);
        cout << "Ruta optima:";
        Console::SetCursorPosition(15, 19);
        cout << "------------";

        int fila = 20;
        for (int i = ruta.size() - 1; i >= 0; i--) {
            Console::SetCursorPosition(15, fila++);
            cout << nombresCiudades[ruta[i]];
            if (i > 0) {
                cout << " -->";
            }
        }
    }

    void dibujarMapa() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(30, 1);
        cout << "=== MAPA DE TRANSFERS ===";
        Console::ForegroundColor = ConsoleColor::White;

        const int FILAS = 15, COLUMNAS = 50;
        vector<vector<char>> mapa(FILAS, vector<char>(COLUMNAS, ' '));

        // Colocar ciudades en el mapa
        for (int i = 0; i < numNodos; i++) {
            int x = posicionesConsola[i].first;
            int y = posicionesConsola[i].second;
            if (x < FILAS && y < COLUMNAS) {
                mapa[x][y] = char('A' + i);
            }
        }

        // Dibujar el mapa
        for (int i = 0; i < FILAS; i++) {
            Console::SetCursorPosition(10, i + 3);
            for (int j = 0; j < COLUMNAS; j++) {
                cout << mapa[i][j];
            }
        }

        // Leyenda
        Console::SetCursorPosition(15, 20);
        cout << "Leyenda de ubicaciones:";
        for (int i = 0; i < numNodos; i++) {
            Console::SetCursorPosition(15, 21 + i);
            cout << char('A' + i) << " = " << nombresCiudades[i];
        }
    }

    void buscarMejorRuta() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2);
        cout << "=== BUSCAR MEJOR RUTA ===";
        Console::ForegroundColor = ConsoleColor::White;

        // Mostrar opciones de origen
        Console::SetCursorPosition(15, 4);
        cout << "Seleccione punto de origen:";
        for (int i = 0; i < numNodos; i++) {
            Console::SetCursorPosition(15, 5 + i);
            cout << (i + 1) << ". " << nombresCiudades[i];
        }

        Console::SetCursorPosition(15, 14);
        cout << "Ingrese numero de origen: ";
        int origenNum;
        cin >> origenNum;

        if (origenNum < 1 || origenNum > numNodos) {
            Console::SetCursorPosition(15, 16);
            cout << "Opcion invalida. Presione cualquier tecla...";
            _getch();
            return;
        }

        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2);
        cout << "=== BUSCAR MEJOR RUTA ===";
        Console::ForegroundColor = ConsoleColor::White;

        // Mostrar opciones de destino
        Console::SetCursorPosition(15, 4);
        cout << "Seleccione punto de destino:";
        for (int i = 0; i < numNodos; i++) {
            Console::SetCursorPosition(15, 5 + i);
            cout << (i + 1) << ". " << nombresCiudades[i];
        }

        Console::SetCursorPosition(15, 14);
        cout << "Ingrese numero de destino: ";
        int destinoNum;
        cin >> destinoNum;

        if (destinoNum < 1 || destinoNum > numNodos) {
            Console::SetCursorPosition(15, 16);
            cout << "Opcion invalida. Presione cualquier tecla...";
            _getch();
            return;
        }

        int origen = origenNum - 1;
        int destino = destinoNum - 1;

        if (origen == destino) {
            Console::SetCursorPosition(15, 16);
            cout << "El origen y destino son iguales. Presione cualquier tecla...";
            _getch();
            return;
        }

        // Calcular ruta optima
        vector<int> predecesores;
        vector<int> distancias = dijkstra(origen, predecesores);

        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 2);
        cout << "=== RESULTADO DE BUSQUEDA ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 4);
        cout << "Desde: " << nombresCiudades[origen];
        Console::SetCursorPosition(15, 5);
        cout << "Hasta: " << nombresCiudades[destino];
        Console::SetCursorPosition(15, 6);
        cout << "Costo total: S/. " << distancias[destino];

        if (distancias[destino] == numeric_limits<int>::max()) {
            Console::SetCursorPosition(15, 8);
            cout << "No hay ruta disponible entre estos puntos.";
        }
        else {
            mostrarRuta(origen, destino, predecesores);

            Console::SetCursorPosition(15, 26);
            cout << "¿Desea confirmar este transfer? (S/N): ";
            char confirmacion;
            cin >> confirmacion;

            if (confirmacion == 'S' || confirmacion == 's') {
                Console::SetCursorPosition(15, 28);
                cout << "Transfer confirmado! Costo: S/. " << distancias[destino];
                Console::SetCursorPosition(15, 29);
                cout << "El conductor lo estara esperando.";
            }
            else {
                Console::SetCursorPosition(15, 28);
                cout << "Transfer cancelado.";
            }
        }

        Console::SetCursorPosition(15, 31);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarTodasLasRutas() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2);
        cout << "=== TODAS LAS RUTAS DISPONIBLES ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 4);
        cout << "Seleccione punto de origen:";
        for (int i = 0; i < numNodos; i++) {
            Console::SetCursorPosition(15, 5 + i);
            cout << (i + 1) << ". " << nombresCiudades[i];
        }

        Console::SetCursorPosition(15, 14);
        cout << "Ingrese numero de origen: ";
        int origenNum;
        cin >> origenNum;

        if (origenNum < 1 || origenNum > numNodos) {
            Console::SetCursorPosition(15, 16);
            cout << "Opcion invalida. Presione cualquier tecla...";
            _getch();
            return;
        }

        int origen = origenNum - 1;
        vector<int> predecesores;
        vector<int> distancias = dijkstra(origen, predecesores);

        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(30, 2);
        cout << "=== DISTANCIAS DESDE " << nombresCiudades[origen] << " ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 4);
        cout << "Destinos disponibles y sus costos:";
        Console::SetCursorPosition(15, 5);
        cout << "-----------------------------------";

        for (int i = 0; i < numNodos; i++) {
            if (i != origen) {
                Console::SetCursorPosition(15, 6 + i);
                if (distancias[i] == numeric_limits<int>::max()) {
                    cout << "Hacia " << nombresCiudades[i] << ": No disponible";
                }
                else {
                    cout << "Hacia " << nombresCiudades[i] << ": S/. " << distancias[i];
                }
            }
        }

        Console::SetCursorPosition(15, 16);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarMenu() {
        bool salir = false;
        int opcion;

        while (!salir) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(35, 2);
            cout << "=== TRANSFER AEROPUERTO ===";
            Console::ForegroundColor = ConsoleColor::White;

            Console::SetCursorPosition(15, 4);
            cout << "Servicio de Transfer Aeropuerto Jorge Chavez";
            Console::SetCursorPosition(15, 5);
            cout << "==========================================";

            Console::SetCursorPosition(15, 7);
            cout << "Servicio disponible las 24 horas";
            Console::SetCursorPosition(15, 8);
            cout << "Vehiculos con aire acondicionado";
            Console::SetCursorPosition(15, 9);
            cout << "Conductores profesionales";
            Console::SetCursorPosition(15, 10);
            cout << "Tarifas fijas sin sorpresas";
            Console::SetCursorPosition(15, 11);
            cout << "Reserva con 30 minutos de anticipacion";

            Console::SetCursorPosition(15, 13);
            cout << "Ubicaciones disponibles:";
            Console::SetCursorPosition(15, 14);
            cout << "• Aeropuerto Internacional Jorge Chavez";
            Console::SetCursorPosition(15, 15);
            cout << "• Principales distritos de Lima";
            Console::SetCursorPosition(15, 16);
            cout << "• Zonas turisticas y comerciales";
            
            Console::SetCursorPosition(15, 18);
            cout << "1. Ver mapa de ubicaciones";
            Console::SetCursorPosition(15, 19);
            cout << "2. Buscar mejor ruta";
            Console::SetCursorPosition(15, 20);
            cout << "3. Ver todas las rutas desde un punto";
            Console::SetCursorPosition(15, 22);
            cout << "0. Volver al menu anterior";

            Console::SetCursorPosition(15, 25);
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 0:
                salir = true;
                break;
            case 1:
                dibujarMapa();
                Console::SetCursorPosition(15, 35);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                break;
            case 2:
                buscarMejorRuta();
                break;
            case 3:
                mostrarTodasLasRutas();
                break;
            default:
                Console::SetCursorPosition(15, 12);
                cout << "Opcion invalida. Presione cualquier tecla...";
                _getch();
                break;
            }
        }
    }


};