#pragma once
#include "pch.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace System;
using namespace std;

struct Auto {
    int id;
    string marca;
    string modelo;
    string tipo;
    double precioPorDia;
    bool disponible;
    string ciudadUbicacion;

    Auto() : id(0), precioPorDia(0.0), disponible(true) {}

    Auto(int _id, string _marca, string _modelo, string _tipo, double _precio, string _ciudad) {
        id = _id;
        marca = _marca;
        modelo = _modelo;
        tipo = _tipo;
        precioPorDia = _precio;
        disponible = true;
        ciudadUbicacion = _ciudad;
    }
};

class HashTableAutos {
private:
    static const int TABLA_SIZE = 50;
    vector<Auto>* tabla[TABLA_SIZE];

    // Funcion hash simple
    int funcionHash(int id) {
        return id % TABLA_SIZE;
    }

    // Generar ID unico para auto
    int generarID() {
        return 100 + rand() % 901; // IDs entre 100-1000
    }

    bool existeID(int id) {
        int indice = funcionHash(id);
        if (tabla[indice] != nullptr) {
            for (const auto& autoItem : *tabla[indice]) {
                if (autoItem.id == id) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    HashTableAutos() {
        // Inicializar tabla
        for (int i = 0; i < TABLA_SIZE; i++) {
            tabla[i] = nullptr;
        }
        cargarAutosIniciales();
    }

    ~HashTableAutos() {
        for (int i = 0; i < TABLA_SIZE; i++) {
            if (tabla[i] != nullptr) {
                delete tabla[i];
            }
        }
    }

    void cargarAutosIniciales() {
        // Generar autos para diferentes ciudades
        vector<string> ciudades = { "Lima", "Cusco", "Arequipa", "Trujillo", "Rosario", "Bogota", "Santiago", "Quito", "Madrid" };
        vector<string> marcas = { "Toyota", "Honda", "Ford", "Chevrolet", "Nissan", "Hyundai", "Kia" };
        vector<string> modelos = { "Corolla", "Civic", "Focus", "Cruze", "Sentra", "Elantra", "Rio" };
        vector<string> tipos = { "compacto", "sedan", "suv", "lujo" };

        srand(time(NULL));

        // Generar 30-40 autos aleatorios
        int numAutos = 30 + rand() % 11;

        for (int i = 0; i < numAutos; i++) {
            int id;
            do {
                id = generarID();
            } while (existeID(id));

            string marca = marcas[rand() % marcas.size()];
            string modelo = modelos[rand() % modelos.size()];
            string tipo = tipos[rand() % tipos.size()];
            string ciudad = ciudades[rand() % ciudades.size()];
            double precio = 30 + (rand() % 171); // Precios entre 30-200

            agregarAuto(Auto(id, marca, modelo, tipo, precio, ciudad));
        }
    }

    void agregarAuto(const Auto& autoNuevo) {
        int indice = funcionHash(autoNuevo.id);

        if (tabla[indice] == nullptr) {
            tabla[indice] = new vector<Auto>();
        }

        tabla[indice]->push_back(autoNuevo);
    }

    Auto* buscarAuto(int id) {
        int indice = funcionHash(id);

        if (tabla[indice] != nullptr) {
            for (auto& autoItem : *tabla[indice]) {
                if (autoItem.id == id) {
                    return &autoItem;
                }
            }
        }
        return nullptr;
    }

    vector<Auto> obtenerAutosPorCiudad(const string& ciudad) {
        vector<Auto> autosEncontrados;

        for (int i = 0; i < TABLA_SIZE; i++) {
            if (tabla[i] != nullptr) {
                for (const auto& autoItem : *tabla[i]) {
                    if (autoItem.ciudadUbicacion == ciudad && autoItem.disponible) {
                        autosEncontrados.push_back(autoItem);
                    }
                }
            }
        }
        return autosEncontrados;
    }

    vector<Auto> obtenerAutosPorTipo(const string& tipo) {
        vector<Auto> autosEncontrados;

        for (int i = 0; i < TABLA_SIZE; i++) {
            if (tabla[i] != nullptr) {
                for (const auto& autoItem : *tabla[i]) {
                    if (autoItem.tipo == tipo && autoItem.disponible) {
                        autosEncontrados.push_back(autoItem);
                    }
                }
            }
        }
        return autosEncontrados;
    }

    bool alquilarAuto(int id) {
        Auto* autoEncontrado = buscarAuto(id);
        if (autoEncontrado != nullptr && autoEncontrado->disponible) {
            autoEncontrado->disponible = false;
            return true;
        }
        return false;
    }

    void mostrarTodosLosAutos() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== TODOS LOS AUTOS DISPONIBLES ===";
        Console::ForegroundColor = ConsoleColor::White;

        int fila = 4;
        int contador = 0;

        for (int i = 0; i < TABLA_SIZE; i++) {
            if (tabla[i] != nullptr) {
                for (const auto& autoItem : *tabla[i]) {
                    if (autoItem.disponible && contador < 20) {
                        Console::SetCursorPosition(15, fila);
                        cout << "ID: " << autoItem.id << " | "
                            << autoItem.marca << " " << autoItem.modelo
                            << " (" << autoItem.tipo << ") | $" << autoItem.precioPorDia
                            << "/dia | " << autoItem.ciudadUbicacion;
                        fila++;
                        contador++;
                    }
                }
            }
        }

        if (contador == 0) {
            Console::SetCursorPosition(15, 6);
            cout << "No hay autos disponibles.";
        }

        Console::SetCursorPosition(15, fila + 2);
        cout << "Total de autos mostrados: " << contador;
        Console::SetCursorPosition(15, fila + 4);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void buscarAutosPorCiudad() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== BUSCAR AUTOS POR CIUDAD ===";
        Console::ForegroundColor = ConsoleColor::White;

        string ciudad;
        Console::SetCursorPosition(15, 4);
        cout << "Ingrese la ciudad: ";
        cin >> ciudad;

        vector<Auto> autos = obtenerAutosPorCiudad(ciudad);

        Console::SetCursorPosition(15, 6);
        cout << "Autos disponibles en " << ciudad << ":";
        Console::SetCursorPosition(15, 7);
        cout << "--------------------------------";

        if (autos.empty()) {
            Console::SetCursorPosition(15, 9);
            cout << "No se encontraron autos en " << ciudad;
        }
        else {
            for (size_t i = 0; i < autos.size() && i < 15; i++) {
                Console::SetCursorPosition(15, 9 + i);
                cout << (i + 1) << ". ID: " << autos[i].id << " - "
                    << autos[i].marca << " " << autos[i].modelo
                    << " - $" << autos[i].precioPorDia << "/dia";
            }
        }

        Console::SetCursorPosition(15, 26);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void alquilarAutoMenu() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== ALQUILAR AUTO ===";
        Console::ForegroundColor = ConsoleColor::White;

        int id;
        Console::SetCursorPosition(15, 4);
        cout << "Ingrese el ID del auto que desea alquilar: ";
        cin >> id;

        Auto* autoEncontrado = buscarAuto(id);

        if (autoEncontrado == nullptr) {
            Console::SetCursorPosition(15, 6);
            cout << "Auto con ID " << id << " no encontrado.";
        }
        else if (!autoEncontrado->disponible) {
            Console::SetCursorPosition(15, 6);
            cout << "El auto ya ha sido alquilado.";
        }
        else {
            // Mostrar detalles del auto
            Console::SetCursorPosition(15, 6);
            cout << "Detalles del auto:";
            Console::SetCursorPosition(15, 7);
            cout << "Marca: " << autoEncontrado->marca;
            Console::SetCursorPosition(15, 8);
            cout << "Modelo: " << autoEncontrado->modelo;
            Console::SetCursorPosition(15, 9);
            cout << "Tipo: " << autoEncontrado->tipo;
            Console::SetCursorPosition(15, 10);
            cout << "Precio por dia: $" << autoEncontrado->precioPorDia;
            Console::SetCursorPosition(15, 11);
            cout << "Ubicacion: " << autoEncontrado->ciudadUbicacion;

            Console::SetCursorPosition(15, 13);
            cout << "Confirmar alquiler? (S/N): ";
            char respuesta;
            cin >> respuesta;

            if (respuesta == 'S' || respuesta == 's') {
                if (alquilarAuto(id)) {
                    Console::SetCursorPosition(15, 15);
                    cout << "Auto alquilado exitosamente!";
                }
                else {
                    Console::SetCursorPosition(15, 15);
                    cout << "Error al alquilar el auto.";
                }
            }
            else {
                Console::SetCursorPosition(15, 15);
                cout << "Alquiler cancelado.";
            }
        }

        Console::SetCursorPosition(15, 17);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarMenu() {
        bool salir = false;
        int opcion;

        while (!salir) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(35, 2); cout << "=== ALQUILER DE AUTOS ===";
            Console::ForegroundColor = ConsoleColor::White;

            Console::SetCursorPosition(15, 4); cout << "1. Ver todos los autos";
            Console::SetCursorPosition(15, 5); cout << "2. Buscar autos por ciudad";
            Console::SetCursorPosition(15, 6); cout << "3. Alquilar auto por ID";
            Console::SetCursorPosition(15, 7); cout << "0. Volver";

            Console::SetCursorPosition(15, 9); cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 0:
                salir = true;
                break;
            case 1:
                mostrarTodosLosAutos();
                break;
            case 2:
                buscarAutosPorCiudad();
                break;
            case 3:
                alquilarAutoMenu();
                break;
            default:
                Console::SetCursorPosition(15, 11);
                cout << "Opcion no valida. Presione cualquier tecla...";
                _getch();
                break;
            }
        }
    }
};