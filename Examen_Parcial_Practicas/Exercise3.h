#pragma once
#include "Utilidades.h"

void boomerangSort(char arr[], int n) {
    auto start = chrono::high_resolution_clock::now();

    int i = 0;
    bool movingForward = true;

    while (i < n -1) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
                if (i > 0) {
                    i--;
                    movingForward = false;
                }
            }
        else {
            if (movingForward) {
                i++;
            }
            else {
                movingForward = true;
                i++;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl; 
}

//necesita ordernarse -> O(n^2) ya que recorre el arreglo 2 veces, uno para mostrar datos y otro para comparar


void pregunta3() {
    char arr[] = {'d', 'c', 'b', 'e', 'a', 'f'};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << endl << "Arreglo original: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
    cout << endl;

    boomerangSort(arr, n);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl << "Presione enter para volver al menu";
    cin.get();
}