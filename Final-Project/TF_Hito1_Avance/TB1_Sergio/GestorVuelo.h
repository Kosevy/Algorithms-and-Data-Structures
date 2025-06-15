#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "conio.h"
#include <functional>
#include <list>

using namespace System;
using namespace std;

template <typename T>
struct Vuelo {
    T origen;
    T destino;
    string aerolinea;
    double precio;
    string fecha;
    string hora;
    int escalas;
    bool disponible;

    Vuelo() : escalas(0), disponible(true) {}

    Vuelo(T orig, T dest, string aero, double prec, string fech, string hor, int esc = 0) {
        origen = orig;
        destino = dest;
        aerolinea = aero;
        precio = prec;
        fecha = fech;
        hora = hor;
        escalas = esc;
        disponible = true;
    }
};

template <typename T>
Vuelo<T> generarVuelo() {
    Vuelo<T> vuelo;
        
    int origenIndex = rand() % 4 + 1;
	switch (origenIndex) {
	case 1:
        vuelo.origen = "Lima"; 
        break;
	case 2: 
        vuelo.origen = "Cusco"; 
        break;
	case 3: 
        vuelo.origen = "Arequipa"; 
        break;
	case 4: 
        vuelo.origen = "Trujillo"; 
        break;
	default: 
        vuelo.origen = "Lima"; 
        break;
	}

	int destinoIndex = rand() % 5 + 1;
    switch (destinoIndex) {
    case 1:
        vuelo.destino = "Rosario";
        break;
    case 2:
		vuelo.destino = "Bogota";
		break;
    case 3:
		vuelo.destino = "Santiago";
		break;
    case 4:
		vuelo.destino = "Quito";
		break;
	case 5:
		vuelo.destino = "Madrid";
		break;
    }

	int aerolineaIndex = rand() % 5 + 1;
    switch (aerolineaIndex) {
    case 1:
        vuelo.aerolinea = "LATAM";
        break;
    case 2:
        vuelo.aerolinea = "Sky Airline";
        break;
    case 3:
        vuelo.aerolinea = "Viva Air";
        break;
    case 4:
        vuelo.aerolinea = "Avianca";
        break;
    case 5:
        vuelo.aerolinea = "Iberia";
        break;
    }
     
	vuelo.precio = 100 + rand() % (1000 - 100 + 1);
	vuelo.fecha = "2025-06-" + to_string(rand() % 30 + 1);
	vuelo.hora = to_string(rand() % 24) + ":" + to_string(rand() % 60);
	vuelo.escalas = rand() % 3;
	vuelo.disponible = true;
	return vuelo;
}

template <typename T>
class GestorVuelos {
private:
    vector<Vuelo<T>> vuelos;

    void cargarVuelosAleatorios(int cantidad) {
        vuelos.clear(); // Limpiar los vuelos existentes
        for (int i = 0; i < cantidad; ++i) {
            vuelos.push_back(generarVuelo<T>()); // Generar y agregar vuelos aleatorios
        }
    }

    /*void cargarVuelosEjemplo() {
        vuelos.clear();
        // Vuelos nacionales
        vuelos.push_back(Vuelo<T>("Lima", "Cusco", "LATAM", 250.0, "2025-06-15", "08:00", 0));
        vuelos.push_back(Vuelo<T>("Lima", "Arequipa", "Sky Airline", 180.0, "2025-06-15", "10:30", 0));
        vuelos.push_back(Vuelo<T>("Lima", "Trujillo", "Viva Air", 120.0, "2025-06-16", "14:00", 0));
        vuelos.push_back(Vuelo<T>("Cusco", "Lima", "LATAM", 270.0, "2025-06-17", "16:00", 0));
        vuelos.push_back(Vuelo<T>("Arequipa", "Lima", "Sky Airline", 190.0, "2025-06-18", "09:15", 0));

        // Vuelos internacionales
        vuelos.push_back(Vuelo<T>("Lima", "Buenos Aires", "Aerolineas Argentinas", 450.0, "2025-06-20", "23:00", 0));
        vuelos.push_back(Vuelo<T>("Lima", "Bogota", "Avianca", 380.0, "2025-06-22", "11:30", 0));
        vuelos.push_back(Vuelo<T>("Lima", "Santiago", "LATAM", 320.0, "2025-06-25", "07:45", 0));
        vuelos.push_back(Vuelo<T>("Lima", "Quito", "LATAM", 290.0, "2025-06-28", "13:20", 1));
        vuelos.push_back(Vuelo<T>("Lima", "Madrid", "Iberia", 850.0, "2025-07-01", "18:30", 1));
    }*/

public:
    GestorVuelos() {
        //cargarVuelosEjemplo();
        cargarVuelosAleatorios(30);
    }

    void mostrarMenu() {
        bool salir = false;
        int opcion;

        while (!salir) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 2); cout << "=== CATALOGO DE VUELOS ===";

            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(15, 4); cout << "1. Buscar vuelos (Origen -> Destino)";
            Console::SetCursorPosition(15, 5); cout << "2. Filtrar por precio (QuickSort)";
            Console::SetCursorPosition(15, 6); cout << "3. Filtrar por aerolinea";
            Console::SetCursorPosition(15, 7); cout << "4. Filtrar por escalas (MergeSort)";
            Console::SetCursorPosition(15, 8); cout << "5. Ver todos los vuelos";
            Console::SetCursorPosition(15, 9); cout << "6. Reservar vuelo";
            Console::SetCursorPosition(15, 10); cout << "0. Volver al menu principal";

            Console::SetCursorPosition(15, 12); cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 0:
                salir = true;
                break;
            case 1:
                buscarVuelos();
                break;
            case 2:
                filtrarPorPrecio();
                break;
            case 3:
                filtrarPorAerolinea();
                break;
            case 4:
                filtrarPorEscalas();
                break;
            case 5:
                mostrarTodosLosVuelos();
                break;
            case 6:
                reservarVuelo();
                break;
            default:
                mostrarMensaje("OPCION INVALIDA", "Opcion no valida.", ConsoleColor::Red);
                break;
            }
        }
    }

    void buscarVuelos() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== BUSCAR VUELOS ===";
        Console::ForegroundColor = ConsoleColor::White;

        T origen, destino;
        Console::SetCursorPosition(15, 4); cout << "Ingrese ciudad de origen: ";
        cin >> origen;
        Console::SetCursorPosition(15, 5); cout << "Ingrese ciudad de destino: ";
        cin >> destino;

        vector<Vuelo<T>> vuelosEncontrados;

        for (const auto& vuelo : vuelos) {
            if (vuelo.origen == origen && vuelo.destino == destino && vuelo.disponible) {
                vuelosEncontrados.push_back(vuelo);
            }
        }

        if (vuelosEncontrados.empty()) {
            Console::SetCursorPosition(15, 7); cout << "No se encontraron vuelos para esa ruta.";
        }
        else {
            Console::SetCursorPosition(15, 7); cout << "Vuelos encontrados:";
            Console::SetCursorPosition(15, 8); cout << "----------------------------------------";

            for (size_t i = 0; i < vuelosEncontrados.size() && i < 8; i++) {
                Console::SetCursorPosition(15, 9 + i);
                cout << (i + 1) << ". " << vuelosEncontrados[i].aerolinea
                    << " - $" << vuelosEncontrados[i].precio
                    << " - " << vuelosEncontrados[i].fecha
                    << " " << vuelosEncontrados[i].hora;
                if (vuelosEncontrados[i].escalas > 0) {
                    cout << " (" << vuelosEncontrados[i].escalas << " escala(s))";
                }
            }
        }

        Console::SetCursorPosition(15, 20); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    //Filtro Precio - QuickSort

    void filtrarPorPrecio() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== FILTRAR POR PRECIO ===";
        Console::ForegroundColor = ConsoleColor::White;

        vector<Vuelo<T>> vuelosOrdenados = vuelos;
        ordenarQuickSort(vuelosOrdenados, 0, vuelosOrdenados.size() - 1);

        Console::SetCursorPosition(15, 4); cout << "Vuelos ordenados por precio (menor a mayor):";
        Console::SetCursorPosition(15, 5); cout << "--------------------------------------------";

        for (size_t i = 0; i < vuelosOrdenados.size() && i < 30; i++) {
            Console::SetCursorPosition(15, 6 + i);
            cout << "$" << vuelosOrdenados[i].precio << " - "
                << vuelosOrdenados[i].origen << " -> " << vuelosOrdenados[i].destino
                << " (" << vuelosOrdenados[i].aerolinea << ")";
        }

        Console::SetCursorPosition(15, 38); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void filtrarPorAerolinea() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== FILTRAR POR AEROLINEA ===";
        Console::ForegroundColor = ConsoleColor::White;

        string aerolinea;
        Console::SetCursorPosition(15, 4); cout << "Ingrese la aerolinea (Use Mayusculas y Minusculas): ";
        cin.ignore();
        getline(cin, aerolinea);

        vector<Vuelo<T>> vuelosAerolinea;
        for (const auto& vuelo : vuelos) {
            if (vuelo.aerolinea == aerolinea && vuelo.disponible) {
                vuelosAerolinea.push_back(vuelo);
            }
        }

        if (vuelosAerolinea.empty()) {
            Console::SetCursorPosition(15, 6); cout << "No se encontraron vuelos para esa aerolinea.";
        }
        else {
            Console::SetCursorPosition(15, 6); cout << "Vuelos de " << aerolinea << ":";
            Console::SetCursorPosition(15, 7); cout << "--------------------";

            for (size_t i = 0; i < vuelosAerolinea.size(); i++) {
                Console::SetCursorPosition(15, 8 + i);
                cout << vuelosAerolinea[i].origen << " -> " << vuelosAerolinea[i].destino
                    << " - $" << vuelosAerolinea[i].precio
                    << " - " << vuelosAerolinea[i].fecha;
            }
        }

        Console::SetCursorPosition(15, 38); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

	//Filtro Escalas - MergeSort

    void filtrarPorEscalas() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== FILTRAR POR ESCALAS ===";
        Console::ForegroundColor = ConsoleColor::White;

        vector<Vuelo<T>> vuelosFiltrados;
		ordenarMergeSort(vuelos, 0, vuelos.size() - 1);

        Console::SetCursorPosition(15, 4); cout << "Vuelos ordenados por escalas (0 a 2):";
        Console::SetCursorPosition(15, 5); cout << "--------------------------------------------";

		for (const auto& vuelo : vuelos) {
			if (vuelo.escalas >= 0 && vuelo.escalas <= 2 && vuelo.disponible) {
				vuelosFiltrados.push_back(vuelo);
			}
		}

		if (vuelosFiltrados.empty()) {
			Console::SetCursorPosition(15, 7); cout << "No se encontraron vuelos con 0 a 2 escalas.";
		}
		else {
			for (size_t i = 0; i < vuelosFiltrados.size() && i < 30; i++) {
				Console::SetCursorPosition(15, 8 + i);
                cout << " (" << vuelosFiltrados[i].escalas << " escala(s)) "
                    << vuelosFiltrados[i].origen << " -> " << vuelosFiltrados[i].destino
                    << " - $" << vuelosFiltrados[i].precio
                    << " - " << vuelosFiltrados[i].fecha;
			}
		}

        Console::SetCursorPosition(15, 39); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarTodosLosVuelos() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== TODOS LOS VUELOS ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 4); cout << "Vuelos disponibles:";
        Console::SetCursorPosition(15, 5); cout << "-------------------";

        for (size_t i = 0; i < vuelos.size(); i++) {
            if (vuelos[i].disponible) {
                Console::SetCursorPosition(15, 6 + i);
                cout << (i + 1) << ". " << vuelos[i].origen << " -> " << vuelos[i].destino
                    << " - " << vuelos[i].aerolinea << " - $" << vuelos[i].precio
                    << " - " << vuelos[i].fecha;
            }
        }

        Console::SetCursorPosition(15, 36); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void reservarVuelo() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== RESERVAR VUELO ===";
        Console::ForegroundColor = ConsoleColor::White;

        mostrarTodosLosVuelos(); // Mostrar todos los vuelos disponibles

        int indice;
        Console::SetCursorPosition(15, 36); // Ajustar posición para evitar solapamiento
        cout << "Ingrese el numero del vuelo que desea reservar: ";
        cin >> indice;

        if (indice < 1 || indice > vuelos.size()) {
            Console::SetCursorPosition(15, 37);
            cout << "Número de vuelo inválido. Presione cualquier tecla para continuar...";
            _getch();
            return;
        }

        Vuelo<T>& vueloSeleccionado = vuelos[indice - 1];
        if (!vueloSeleccionado.disponible) {
            Console::SetCursorPosition(15, 37);
            cout << "El vuelo seleccionado no está disponible. Presione cualquier tecla para continuar...";
            _getch();
            return;
        }

        vueloSeleccionado.disponible = false; // Marcar el vuelo como reservado
        Console::SetCursorPosition(15, 37);
        cout << "Reserva exitosa! Vuelo reservado: " << vueloSeleccionado.origen << " -> " << vueloSeleccionado.destino;
        Console::SetCursorPosition(15, 38);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

private:

    //IMPLEMENTACION QUICKSORT

    int particion(vector<Vuelo<T>>& vuelos, int inicio, int fin) {
        double pivote = vuelos[fin].precio;
        int i = inicio - 1;

        for (int j = inicio; j <= fin - 1; j++) {
            if (vuelos[j].precio <= pivote) {
                i++;
                swap(vuelos[i], vuelos[j]);
            }
        }

        swap(vuelos[i + 1], vuelos[fin]);
        return i + 1;
    }

    void ordenarQuickSort(vector<Vuelo<T>>& vuelos, int inicio, int fin) {
        if (inicio < fin) {
            int indicePivote = particion(vuelos, inicio, fin);
            ordenarQuickSort(vuelos, inicio, indicePivote - 1);
            ordenarQuickSort(vuelos, indicePivote + 1, fin);
        }
    }

    //IMPLEMENTACION MERGESORT

    void merge(vector<Vuelo<T>>& vuelos, int inicio, int medio, int fin) {
        // Crear subarreglos temporales
        vector<Vuelo<T>> temp(fin - inicio + 1);
        int i = inicio, j = medio + 1, k = 0;

        // Combinar los subarreglos ordenados
        while (i <= medio && j <= fin) {
            if (vuelos[i].escalas <= vuelos[j].escalas) {
                temp[k++] = vuelos[i++];
            }
            else {
                temp[k++] = vuelos[j++];
            }
        }

        // Copia los elementos restantes del primer subarreglo
        while (i <= medio) {
            temp[k++] = vuelos[i++];
        }

        // Copia los elementos restantes del segundo subarreglo
        while (j <= fin) {
            temp[k++] = vuelos[j++];
        }

        // Copia los elementos ordenados al arreglo original
        for (int i = 0; i < k; i++) {
            vuelos[inicio + i] = temp[i];
        }
    }

    void ordenarMergeSort(vector<Vuelo<T>>& vuelos, int inicio, int fin) {
        if (inicio < fin) {
            int medio = inicio + (fin - inicio) / 2;
            ordenarMergeSort(vuelos, inicio, medio);
            ordenarMergeSort(vuelos, medio + 1, fin);
            merge(vuelos, inicio, medio, fin);
        }
    }


    void mostrarMensaje(const string& titulo, const string& mensaje, ConsoleColor color = ConsoleColor::Green) {
        Console::Clear();
        Console::ForegroundColor = color;
        Console::SetCursorPosition(35, 2); cout << "=== " << titulo << " ===";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(15, 4); cout << mensaje;
        Console::SetCursorPosition(15, 6); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }
};
