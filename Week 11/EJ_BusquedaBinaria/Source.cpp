// ConsoleApplication10.cpp: archivo de proyecto principal
#include "conio.h"
#include "iostream"
#include "time.h"
#define N 10
using namespace System;
using namespace std;

bool existe(int candidato, int* arreglo)
{
	for (int i = 0; i < N; i++)
	{
		if (candidato == arreglo[i])
			return true;
	}
	return false;
}

void genera_arreglo(int* arreglo)
{
	//datos con datos entre 1 y 100
	srand(time(NULL));
	int candidato;
	for (int i = 0; i < N; )
	{
		candidato = 1 + rand() % 90;
		if (existe(candidato, arreglo) == false)//verifica si el elemento ya existe
		{
			arreglo[i] = candidato;
			i++;
		}
	}
}

void imprime_arreglo(int* arreglo)
{
	for (int i = 0; i < N; i++)
	{
		cout << "\n arreglo[" << i << "] -> " << arreglo[i];
	}
}

int busqueda_simple(int buscar, int* arreglo)
{
	int resultado = 0;

	for (int i = 0; i < N; i++)
	{
		if (arreglo[i] == buscar)
			resultado = 1;
	}

	return resultado;
}

int busquedabinaria_iterativa(int* arreglo, int buscar, int inicio, int fin)
{
	int centro;

	while (inicio <= fin)
	{
		centro = (inicio + fin) / 2;
		if (buscar == arreglo[centro])
			return centro;
		if (buscar > arreglo[centro])
			inicio = centro + 1;
		if (buscar < arreglo[centro])
			fin = centro - 1;
	}
	return -1;
}

void ordena_arreglo(int* arreglo)
{
	int temp;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arreglo[i] > arreglo[j])
			{
				temp = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = temp;
			}
		}
	}
}


int main()
{
	int arreglo[N];
	int buscar;
	while (1)
	{
		Console::Clear();

		genera_arreglo(arreglo);
		cout << "\nARREGLO ORIGINAL\n";
		imprime_arreglo(arreglo);

		ordena_arreglo(arreglo);
		cout << "\nARREGLO ORDENADO\n";
		imprime_arreglo(arreglo);

		//ingresa un dato a buscar
		cout << "\nINGRESE UN DATO A BUSCAR ";
		cin >> buscar;

		/*
		if(   busqueda_simple(buscar, arreglo) == 1 )
		{
			cout<<"\n EL dato ha sido encontrado";
		}else
			cout<<"\n EL dato no fue encontrado";
		*/

		int resultado;
		resultado = busquedabinaria_iterativa(arreglo, buscar, 0, N - 1);
		if (resultado == -1)
			cout << "\n EL dato NO ha sido encontrado";
		else
			cout << "\n EL dato ha sido encontrado en la posicion: " << resultado;


		cout << endl << endl << "PRESIONE UNA TECLA PARA CONTINUAR....";
		system("pause>0");
	}
	return 0;
}
