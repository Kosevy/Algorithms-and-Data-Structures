#include "pch.h"
#include "iostream"
#include "Presentaciones.h"
#include "FormularioVuelo.h"
#include "GestorVuelo.h"
#include "GestorServicios.h"
#include "UsuarioSistema.h"
#include "Hash.h"
#include "Grafos.h"

using namespace System;
using namespace std;

int main()
{
    srand(time(0));
    Console::SetWindowSize(100, 40);
    SistemaUsuarios<string> sistemaUsuarios;
    mostrarPresentacion();
    bool autenticado = sistemaUsuarios.mostrarMenuAutenticacion();

    if (autenticado) {
        bool salir = false;
        ArbolReservas<Vuelo<string>> reservas;
        GestorServicios gestorServicios;
        while (!salir) {
            int opcion = mostrarInstrucciones();
            switch (opcion)
            {
            case 1: {
                bool salirSubmenu = false;
                GestorVuelos<string> gestorVuelos(&reservas);

                while (!salirSubmenu) {
                    Console::Clear();
                    Console::ForegroundColor = ConsoleColor::Yellow;
                    Console::SetCursorPosition(35, 2); cout << "=== BUSQUEDA Y GESTION DE VUELOS ===";
                    Console::ForegroundColor = ConsoleColor::White;

                    Console::SetCursorPosition(15, 4); cout << "1. Ver todos los vuelos";
                    Console::SetCursorPosition(15, 5); cout << "2. Formulario de busqueda"; // Lista enlazada
                    Console::SetCursorPosition(15, 6); cout << "3. Buscar vuelos (Origen -> Destino)";
                    Console::SetCursorPosition(15, 7); cout << "4. Filtrar por precio"; // QuickSort
                    Console::SetCursorPosition(15, 8); cout << "5. Filtrar por aerolinea"; // Búsqueda lineal
                    Console::SetCursorPosition(15, 9); cout << "6. Filtrar por escalas"; // MergeSort
                    Console::SetCursorPosition(15, 10); cout << "7. Reservar vuelo";
                    Console::SetCursorPosition(15, 11); cout << "0. Volver al menu principal";

                    Console::SetCursorPosition(15, 13); cout << "Seleccione una opcion: ";
                    int subOpcion1;
                    cin >> subOpcion1;

                    switch (subOpcion1) {
                    case 1: {
                        gestorVuelos.mostrarTodosLosVuelos();
                        break;
                    }
                    case 2: {
                        FormularioBusquedaVuelos<string> formulario;
                        formulario.mostrarMenu();
                        break;
                    }
                    case 3: {
                        gestorVuelos.buscarVuelos();
                        break;
                    }
                    case 4: {
                        gestorVuelos.filtrarPorPrecio();
                        break;
                    }
                    case 5: {
                        gestorVuelos.filtrarPorAerolinea();
                        break;
                    }
                    case 6: {
                        gestorVuelos.filtrarPorEscalas();
                        break;
                    }
                    case 7: {
                        gestorVuelos.reservarVuelo();
                        break;
                    }
                    case 0:
                        salirSubmenu = true;
                        break;
                    default:
                        Console::Clear();
                        Console::SetCursorPosition(15, 15);
                        cout << "Opcion no valida. Presione cualquier tecla...";
                        _getch();
                        break;
                    }
                }
                break;
            }
            case 2: {
                bool salirSubmenuReservas = false;

                while (!salirSubmenuReservas) {
                    Console::Clear();
                    Console::ForegroundColor = ConsoleColor::Magenta;
                    Console::SetCursorPosition(35, 2); cout << "=== GESTION DE RESERVAS ===";
                    Console::ForegroundColor = ConsoleColor::White;

                    Console::SetCursorPosition(15, 4); cout << "1. Mostrar Reservas";
                    Console::SetCursorPosition(15, 5); cout << "2. Modificar Reservas";
                    Console::SetCursorPosition(15, 6); cout << "3. Eliminar Reservas";
                    Console::SetCursorPosition(15, 7); cout << "4. Ver detalles de una Reserva";
                    Console::SetCursorPosition(15, 8); cout << "0. Volver al menu principal";

                    Console::SetCursorPosition(15, 10); cout << "Seleccione una opcion: ";
                    int subOpcion2;
                    cin >> subOpcion2;

                    switch (subOpcion2) {
                    case 1: {
                        reservas.mostrarReservasEnumeradas();
                        Console::SetCursorPosition(15, 30);
                        cout << "Presione cualquier tecla para continuar...";
                        _getch();
                        break;
                    }
                    case 2: {
                        reservas.menuModificarReservas();
                        break;
                    }
                    case 3: {
                        reservas.menuEliminarReservas();
                        break;
                    }
                    case 4: {
                        if (reservas.tieneReservas()) {
                            int total = reservas.mostrarReservasEnumeradas();
                            Console::SetCursorPosition(15, 25);
                            cout << "Ingrese el numero del vuelo para ver detalles: ";
                            int num;
                            cin >> num;
                            reservas.verDetallesReserva(num);
                        }
                        else {
                            Console::SetCursorPosition(15, 10);
                            cout << "No hay reservas disponibles.";
                            Console::SetCursorPosition(15, 12);
                            cout << "Presione cualquier tecla para regresar...";
                            _getch();
                        }
                        break;
                    }
                    case 0:
                        salirSubmenuReservas = true;
                        break;
                    default:
                        Console::Clear();
                        Console::SetCursorPosition(15, 10);
                        cout << "Opcion no valida. Presione cualquier tecla...";
                        _getch();
                        break;
                    }
                }
                break;
            }
            case 3: {
                bool salirSubmenuServicios = false;
                HashTableAutos gestorAutos; // Crear instancia de la hash table

                while (!salirSubmenuServicios) {
                    Console::Clear();
                    Console::ForegroundColor = ConsoleColor::Yellow;
                    Console::SetCursorPosition(35, 2); cout << "=== SERVICIOS ADICIONALES ===";
                    Console::ForegroundColor = ConsoleColor::White;

                    Console::SetCursorPosition(15, 4); cout << "1. Reservar hotel"; // AVL
                    Console::SetCursorPosition(15, 5); cout << "2. Alquilar auto"; // Hash Table
                    Console::SetCursorPosition(15, 6); cout << "3. Transfer aeropuerto"; // Grafos
                    Console::SetCursorPosition(15, 7); cout << "0. Volver al menu principal";

                    Console::SetCursorPosition(15, 9); cout << "Seleccione una opcion: ";
                    int subOpcion3;
                    cin >> subOpcion3;

                    switch (subOpcion3) {
                    case 1: {
                        if (reservas.tieneReservas()) {
                            int total = reservas.mostrarReservasEnumeradas();
                            Console::SetCursorPosition(15, 25);
                            cout << "Ingrese el numero del vuelo para reservar hotel: ";
                            int num;
                            cin >> num;
                            string ciudadDestino = reservas.obtenerDestinoPorIndice(num);
                            if (!ciudadDestino.empty()) {
                                string nombreHotelReservado = gestorServicios.reservarHotel(ciudadDestino);
                                if (!nombreHotelReservado.empty()) {
                                    reservas.asociarHotelAReserva(ciudadDestino, nombreHotelReservado);
                                }
                            }
                            else {
                                Console::SetCursorPosition(15, 32);
                                cout << "Opcion invalida. Presione cualquier tecla para continuar...";
                                _getch();
                            }
                        }
                        else {
                            Console::SetCursorPosition(15, 10);
                            cout << "Primero debe reservar un vuelo para acceder a los servicios adicionales.";
                            Console::SetCursorPosition(15, 12);
                            cout << "Presione cualquier tecla para regresar...";
                            _getch();
                        }
                        break;
                    }
                    case 2: {
                        gestorAutos.mostrarMenu(); // Llamar al menú de la hash table
                        break;
                    }
                    case 3: {
                        GrafoTransferAeropuerto gestorTransfer;
                        gestorTransfer.mostrarMenu();
                        break;
                    }
                    case 0:
                        salirSubmenuServicios = true;
                        break;
                    default:
                        Console::Clear();
                        Console::SetCursorPosition(15, 10);
                        cout << "Opcion no valida. Presione cualquier tecla...";
                        _getch();
                        break;
                    }
                }
                break;
            }
            case 4: {
                Console::Clear();
                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::SetCursorPosition(35, 10);
                cout << "¡Buen viaje! Esperamos verte pronto.";
                Console::SetCursorPosition(35, 14);
                cout << "Presione cualquier tecla para salir...";
                _getch();
                salir = true;
                break;
            }
            default: {
                Console::Clear();
                Console::SetCursorPosition(35, 10);
                cout << "Opción no válida";
                _getch();
                break;
            }
            }
        }
    }
    return 0;
}
