#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "conio.h"

using namespace System;
using namespace std;

template <typename T>
struct Usuario {
    T email;
    T password;
};

template <typename T>
class SistemaUsuarios {
private:
    vector<Usuario<T>> usuarios;

public:
    bool mostrarMenuAutenticacion() {
        bool autenticado = false;
        bool salir = false;

        while (!autenticado && !salir) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Cyan;
            Console::SetCursorPosition(48, 2); cout << "SKYBROS";
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(35, 4); cout << "=== SISTEMA DE AUTENTICACION ===";

            Console::SetCursorPosition(15, 6); cout << "1. Iniciar sesion";
            Console::SetCursorPosition(15, 7); cout << "2. Registrarse";
            Console::SetCursorPosition(15, 8); cout << "0. Salir";

            Console::SetCursorPosition(15, 10); cout << "Seleccione una opcion: ";
            int opcion;
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
            case 0:
                salir = true;
                break;
            case 1:
                autenticado = iniciarSesion();
                break;
            case 2:
                registrarUsuario();
                break;
            default:
                Console::SetCursorPosition(15, 12); cout << "Opcion no valida. Presione cualquier tecla para continuar...";
                _getch();
                break;
            }
        }

        return autenticado;
    }

    bool iniciarSesion() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(40, 2); cout << "INICIO DE SESION";
        Console::ForegroundColor = ConsoleColor::White;

        T email, password;

        Console::SetCursorPosition(15, 4); cout << "Email: ";
        cin >> email;

        Console::SetCursorPosition(15, 5); cout << "Contrasena: ";
        cin >> password;

        cin.ignore();

        // Buscar el usuario en el vector
        for (const Usuario<T>& usuario : usuarios) {
            if (usuario.email == email && usuario.password == password) {
                Console::SetCursorPosition(15, 7); cout << "Inicio de sesion exitoso! Bienvenido!";
                Console::SetCursorPosition(15, 9); cout << "Presione cualquier tecla para continuar...";
                _getch();
                return true;
            }
        }

        Console::SetCursorPosition(15, 7); cout << "Email o contrasena incorrectos.";
        Console::SetCursorPosition(15, 9); cout << "Presione cualquier tecla para continuar...";
        _getch();
        return false;
    }

    void registrarUsuario() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(40, 2); cout << "REGISTRO DE USUARIO";
        Console::ForegroundColor = ConsoleColor::White;

        T email, password;

        Console::SetCursorPosition(15, 4); cout << "Email: ";
        cin >> email;

        // Verificar si el email ya existe
        for (const Usuario<T>& usuario : usuarios) {
            if (usuario.email == email) {
                Console::SetCursorPosition(15, 6); cout << "Este email ya esta registrado.";
                Console::SetCursorPosition(15, 8); cout << "Presione cualquier tecla para continuar...";
                _getch();
                return;
            }
        }

        Console::SetCursorPosition(15, 5); cout << "Contrasena: ";
        cin >> password;

        // Limpiar buffer
        cin.ignore();

        // Crear y registrar el nuevo usuario
        Usuario<T> nuevoUsuario;
        nuevoUsuario.email = email;
        nuevoUsuario.password = password;
        usuarios.push_back(nuevoUsuario);

        Console::SetCursorPosition(15, 7); cout << "Usuario registrado exitosamente!";
        Console::SetCursorPosition(15, 9); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }
};