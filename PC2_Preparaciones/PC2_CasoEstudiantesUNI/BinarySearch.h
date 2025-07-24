#pragma once
#include "Utilidades.h"


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

