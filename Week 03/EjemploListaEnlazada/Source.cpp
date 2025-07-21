#include "ListaEnlazada.h"
#include "MisFunciones.h"
using namespace System;

int main()
{
    ListaEnlazada* ObjListaEnlazada;
    ObjListaEnlazada = new ListaEnlazada();
    int op, dato;

    while (1)
    {
        Console::Clear();
        op = menu();

        if (op == 1)
        {
            ObjListaEnlazada->MostrarElementos();
        }
        if (op == 2)
        {
            cout << endl << "Ingrese el dato: "; cin >> dato;
            ObjListaEnlazada->InsertarAlFinal(dato);
        }
        if (op == 3)
        {
            cout << endl << "Ingrese el dato: "; cin >> dato;
            ObjListaEnlazada->InsetarAlInicio(dato);
        }

        system("pause>0");
    }

    return 0;
}