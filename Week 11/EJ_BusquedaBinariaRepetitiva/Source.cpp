#include "iostream"
using namespace System;
using namespace std;

int main()
{
    int arreglo[] = { 3,5,6,17,28,30,32,45,80 };
    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
    int mitad;
    bool encontrado = 0;

    cout << "tam arreglo " << sizeof(arreglo) / sizeof(arreglo[0]);
    int dato_buscar = 6;
    int limite_ini = 0;
    int limite_sup = tam_arreglo;

    while (limite_ini <= limite_sup)
    {
        mitad = (limite_ini + limite_sup) / 2;

        if (arreglo[mitad] == dato_buscar)
        {
            encontrado = true;
            break;
        }
        if (arreglo[mitad] > dato_buscar)
        {
            limite_sup = mitad;
            mitad = (limite_ini + limite_sup) / 2;
        }
        if (arreglo[mitad] < dato_buscar)
        {
            limite_ini = mitad;
            mitad = (limite_ini + limite_sup) / 2;
        }
    }

    if (encontrado) {
        cout << "\n EL numero fue encontrado en la posicion : " << mitad;
    }


    system("pause>0");
    return 0;
}
