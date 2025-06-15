#pragma once
#include "pch.h"
#include "iostream"
#include "conio.h"

using namespace System;
using namespace std;

void mostrarPresentacion()
{
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::DarkBlue;
    int x = 0, y = 1;
    Console::SetCursorPosition(x + 19, y + 8); cout << "                             |                             ";
    Console::SetCursorPosition(x + 19, y + 9); cout << "                             |                             ";
    Console::SetCursorPosition(x + 19, y + 10); cout << "                           .-'-.                           ";
    Console::SetCursorPosition(x + 19, y + 11); cout << "                          ' ___ '                          ";
    Console::SetCursorPosition(x + 19, y + 12); cout << "                ---------'  .-.  '---------                ";
    Console::SetCursorPosition(x + 19, y + 13); cout << "_________________________'  '-'  '_________________________";
    Console::SetCursorPosition(x + 19, y + 14); cout << " ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-'''''' ";
    Console::SetCursorPosition(x + 19, y + 15); cout << "               \\    /  ||/   H   \\||  \\    /               ";
    Console::SetCursorPosition(x + 19, y + 16); cout << "                '--'   OO   O|O   OO   '--'                ";
    Console::SetCursorPosition(x + 19, y + 18); cout << "                       Bienvenido!                        ";
    Console::SetCursorPosition(x + 19, y + 19); cout << "       <<Presiona cualquier tecla para continuar>>        ";


    Console::SetCursorPosition(x + 15, y + 21); cout << "**********************************************************************   ";

    Console::SetCursorPosition(x + 14, y + 23); cout << "   ********  **   **  **  **  ********  ********   *********  ********   ";
    Console::SetCursorPosition(x + 14, y + 24); cout << "   **        **  **   **  **  **    **  **    **   **     **  **         ";
    Console::SetCursorPosition(x + 14, y + 25); cout << "   ********  *****    ******  ********  ********   **     **  ********   ";
    Console::SetCursorPosition(x + 14, y + 26); cout << "         **  *****      **    **    **  **   **    **     **        **   ";
    Console::SetCursorPosition(x + 14, y + 27); cout << "         **  **  **     **    **    **  **    **   **     **        **   ";
    Console::SetCursorPosition(x + 14, y + 28); cout << "   ********  **   **    **    ********  **     **  *********  ********   ";

    Console::SetCursorPosition(x + 15, y + 30); cout << "**********************************************************************   ";
    _getch();
}

int mostrarInstrucciones()
{
    int op;
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(45, 2); cout << "SKYGRAPH";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(15, 4); cout << "=== MENU PRINCIPAL ===";
    Console::SetCursorPosition(15, 6); cout << "1. Busqueda y gestion de vuelos";
    Console::SetCursorPosition(15, 7); cout << "2. Mis reservas";
    Console::SetCursorPosition(15, 8); cout << "3. Ofertas especiales";
    Console::SetCursorPosition(15, 9); cout << "4. Servicios adicionales";
    Console::SetCursorPosition(15, 10); cout << "5. Mi perfil";
    Console::SetCursorPosition(15, 11); cout << "6. Cerrar sesion";

    Console::SetCursorPosition(15, 13); cout << "Ingrese una opcion: ";
    cin >> op;
    return op;
}