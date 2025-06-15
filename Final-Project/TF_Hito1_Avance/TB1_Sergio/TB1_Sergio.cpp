#include "pch.h"
#include "iostream"
#include "Presentaciones.h"
#include "FormularioVuelo.h"
#include "GestorVuelo.h"
#include "UsuarioSistema.h"

using namespace System;
using namespace std;

int main()
{
    srand(time(0));
    Console::SetWindowSize(100, 40);
    SistemaUsuarios<string> sistemaUsuarios;
    mostrarPresentacion();
    bool autenticado = true; // Cambiado para pruebas rápidas

    if (autenticado) {
        bool salir = false;
        while (!salir) {
            int opcion = mostrarInstrucciones();
            switch (opcion)
            {
            case 1: {
                // Submenú para formulario y catálogo
                Console::Clear();
                Console::ForegroundColor = ConsoleColor::Yellow;
                Console::SetCursorPosition(35, 2); cout << "=== BUSQUEDA Y GESTION DE VUELOS ===";
                Console::ForegroundColor = ConsoleColor::White;

                Console::SetCursorPosition(15, 4); cout << "1. Formulario de busqueda (Lista Enlazada)";
                Console::SetCursorPosition(15, 5); cout << "2. Catalogo de vuelos disponibles";
                Console::SetCursorPosition(15, 6); cout << "0. Volver al menu principal";

                Console::SetCursorPosition(15, 8); cout << "Seleccione una opcion: ";
                int subOpcion;
                cin >> subOpcion;

                switch (subOpcion) {
                case 1: {
                    FormularioBusquedaVuelos<string> formulario;
                    formulario.mostrarMenu();
                    break;
                }
                case 2: {
                    GestorVuelos<string> gestorVuelos;
                    gestorVuelos.mostrarMenu();
                    break;
                }
                case 0:
                    break;
                default:
                    Console::Clear();
                    Console::SetCursorPosition(15, 10);
                    cout << "Opcion no valida. Presione cualquier tecla...";
                    _getch();
                    break;
                }
                break;
            }
            case 2: {
                Console::Clear();
                Console::SetCursorPosition(15, 10);
                cout << "Modulo 'Mis reservas' en desarrollo...";
                Console::SetCursorPosition(15, 12);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                break;
            }
            case 3: {
                Console::Clear();
                Console::SetCursorPosition(15, 10);
                cout << "Modulo 'Ofertas especiales' en desarrollo...";
                Console::SetCursorPosition(15, 12);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                break;
            }
            case 4: {
                Console::Clear();
                Console::SetCursorPosition(15, 10);
                cout << "Modulo 'Servicios adicionales' en desarrollo...";
                Console::SetCursorPosition(15, 12);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                break;
            }
            case 5: {
                Console::Clear();
                Console::SetCursorPosition(15, 10);
                cout << "Modulo 'Mi perfil' en desarrollo...";
                Console::SetCursorPosition(15, 12);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                break;
            }
            case 6: {
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