#include "iostream"
using namespace System;
using namespace std;

int busqueda_binaria(int arreglo[], int limite_ini, int limite_fin, int dato_buscar)
{
    if (limite_fin >= limite_ini)
    {
        int mitad = limite_ini + (limite_fin - limite_ini) / 2;
        if (arreglo[mitad] == dato_buscar) {
            return mitad;
        }
        if (arreglo[mitad] > dato_buscar) {
            busqueda_binaria(arreglo, limite_ini, mitad - 1, dato_buscar);
        }
        busqueda_binaria(arreglo, mitad + 1, limite_fin, dato_buscar);

    }
    return -1;
}

int main()
{
    int arreglo[] = { 3,5,6,17,28,30,32,45,80 };

    int tam_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);
    cout << "tam arreglo " << sizeof(arreglo) / sizeof(arreglo[0]);
    int dato_buscar = 6;
    int limite_ini = 0;
    int limite_fin = tam_arreglo;
    int resultado = busqueda_binaria(arreglo, limite_ini, limite_fin - 1, dato_buscar);
    if (resultado == -1) {
        cout << "\n EL numero NO fue encontrado ";
    }
    else
    {
        cout << "\n EL numero fue encontrado en la posicion " << resultado;
    }


    system("pause>0");
    return 0;
}
