#pragma once
#include "Pacientes.h"


void quickSort(Paciente arr[], int izquierda, int derecha) {
    if (izquierda >= derecha) return;

    float pivote = arr[(izquierda + derecha) / 2].NivelGlucosa;
    int i = izquierda;
    int j = derecha;

    while (i <= j) {
        while (arr[i].NivelGlucosa < pivote) i++;
        while (arr[j].NivelGlucosa > pivote) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (izquierda < j) quickSort(arr, izquierda, j);
    if (i < derecha) quickSort(arr, i, derecha);
}
