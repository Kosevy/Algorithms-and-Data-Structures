#include "Electricidad.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

RedElectrica::RedElectrica() : total(0), estacionesGeneradas(false) {
    for (int i = 0; i < MAX_RED; i++) {
        capacidad[i] = 0;
        estaciones[i] = "";
        posX[i] = posY[i] = 0;
        for (int j = 0; j < MAX_RED; j++) {
            matrizEnlaces[i][j] = 0;
        }
    }
}

int RedElectrica::buscarIndice(const string& nombre) {
    for (int i = 0; i < total; i++) {
        if (estaciones[i] == nombre) return i;
    }
    return -1;
}

bool RedElectrica::agregarEstacion(const string& nombre, int cap) {
    if (total >= MAX_RED) return false;
    if (buscarIndice(nombre) != -1) return false; // evitar duplicados
    estaciones[total] = nombre;
    capacidad[total] = cap;
    total++;
    estacionesGeneradas = true;
    return true;
}

bool RedElectrica::agregarEnlace(const string& a, const string& b, int consumo) {
    int i = buscarIndice(a);
    int j = buscarIndice(b);
    if (i == -1 || j == -1 || i == j) return false;
    if (matrizEnlaces[i][j] != 0) return false;
    matrizEnlaces[i][j] = consumo;
    matrizEnlaces[j][i] = consumo;
    return true;
}

void ubicar(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void RedElectrica::mostrarRedVisual() {
    system("cls");
    cout << "=== RED ELECTRICA VISUAL ===\n\n";

    if (total == 0) {
        cout << "No hay estaciones agregadas.\n";
        system("pause");
        return;
    }

    const int cols = 3;
    const int spanX = 25, spanY = 5;
    const int ox = 5, oy = 3;

    
    for (int i = 0; i < total; i++) {
        int r = i / cols;
        int c = i % cols;
        posX[i] = ox + c * spanX;
        posY[i] = oy + r * spanY;

        ubicar(posX[i], posY[i]);
        string label = estaciones[i] + " (" + to_string(capacidad[i]) + " kWh)";
        cout << label;
    }

   
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (matrizEnlaces[i][j] > 0) {
                int midX = (posX[i] + posX[j]) / 2;
                int midY = (posY[i] + posY[j]) / 2;
                ubicar(midX, midY);
                cout << matrizEnlaces[i][j];
            }
        }
    }

    ubicar(0, oy + ((total + cols - 1) / cols) * spanY + 3);
    cout << "\nPresione ENTER para continuar...";
    while (_getch() != 13) {}
}

void RedElectrica::registro_aleatorio() {
    
    total = 0;
    estacionesGeneradas = false;
    for (int i = 0; i < MAX_RED; i++) {
        capacidad[i] = 0;
        estaciones[i] = "";
        for (int j = 0; j < MAX_RED; j++) {
            matrizEnlaces[i][j] = 0;
        }
    }

    string nombres[MAX_RED] = { "E1", "E2", "E3", "E4", "E5", "E6" };

    
    for (int i = 0; i < MAX_RED; i++) {
        int cap = 1000 + rand() % 4001;
        agregarEstacion(nombres[i], cap);
    }

    
    for (int i = 0; i < MAX_RED; i++) {
        int enlaces = rand() % 4;
        for (int c = 0; c < enlaces; c++) {
            int j = rand() % MAX_RED;
            if (i != j && matrizEnlaces[i][j] == 0) {
                int consumo = 50 + rand() % 251;
                agregarEnlace(estaciones[i], estaciones[j], consumo);
            }
        }
    }

    estacionesGeneradas = true;
    mostrarRedVisual();
}

void RedElectrica::mostrarRed() {
    mostrarRedVisual();
}

void RedElectrica::interactuar() {
    bool salir = false;
    while (!salir) {
        system("cls");
        cout << "=== MENU RED ELECTRICA ===\n";
        cout << "1. Generar estaciones aleatorias (capacidad 1000-5000 kWh)\n";
        cout << "2. Agregar enlace (consumo 50-300 kWh)\n";
        if (estacionesGeneradas) {
            cout << "3. Mostrar red\n";
            cout << "4. Salir\n";
        }
        else {
            cout << "4. Salir\n";
        }
        cout << "Seleccione opcion: ";

        int op;
        cin >> op;
        cin.ignore();

        if (op == 1) {
            if (total >= MAX_RED) {
                cout << "Limite maximo de estaciones alcanzado.\n";
                system("pause");
                continue;
            }
            string nombre = "E" + to_string(total + 1);
            int cap = 1000 + rand() % 4001;
            if (agregarEstacion(nombre, cap)) {
                cout << "Estacion " << nombre << " agregada con capacidad " << cap << " kWh.\n";
            }
            else {
                cout << "Error al agregar estacion.\n";
            }
            system("pause");
        }
        else if (op == 2) {
            if (!estacionesGeneradas) {
                cout << "Primero debe generar estaciones (opcion 1).\n";
                system("pause");
                continue;
            }
            if (total < 2) {
                cout << "Debe haber al menos 2 estaciones para crear enlaces.\n";
                system("pause");
                continue;
            }
            string a, b;
            cout << "Estacion origen: ";
            getline(cin, a);
            cout << "Estacion destino: ";
            getline(cin, b);
            int consumo = 50 + rand() % 251;
            if (agregarEnlace(a, b, consumo)) {
                cout << "Enlace agregado entre " << a << " y " << b << " con consumo estimado " << consumo << " kWh.\n";
            }
            else {
                cout << "Error: estaciones invalidas, enlace ya existe o mismo nodo.\n";
            }
            system("pause");
        }
        else if (op == 3 && estacionesGeneradas) {
            mostrarRedVisual();
        }
        else if ((op == 4 && estacionesGeneradas) || (op == 3 && !estacionesGeneradas)) {
            salir = true;
        }
        else {
            cout << "Opcion no valida.\n";
            system("pause");
        }
    }
}
