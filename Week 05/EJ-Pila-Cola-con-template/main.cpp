#include "pch.h"
#include "Pila.h"
#include "Cola.h"
#include "Punto.h"
#include "iostream"
using namespace std;

int main()
{
    //define objeto del tipo pila
    Pila<Punto*>* Objpila;
    //instancia el objeto
    Objpila = new Pila<Punto*>();
    //Push : agrega elementos a la pila
    Objpila->push(new Punto(10, 10));
    Objpila->push(new Punto(30, 30));
    Objpila->push(new Punto(50, 50));
    Objpila->push(new Punto(9, 9));

    //muestra la pila
    Punto* temporal;
    do {
        temporal = Objpila->pop();
        if (temporal != nullptr)
        {
            cout << temporal->muestra();
        }

    } while (temporal != nullptr);

    //cola
    Cola<Punto*>* Objcola;
    Objcola = new Cola<Punto*>();
    Objcola->encolar(new Punto(1, 1));
    Objcola->encolar(new Punto(2, 2));
    Objcola->encolar(new Punto(0, 0));
    Objcola->encolar(new Punto(3, 3));
    //muestra la cola
    cout << endl << "COLA" << endl;
    do {
        temporal = Objcola->desencolar();
        cout << temporal->muestra();

    } while ( !Objcola->estaVacia() );

    system("pause>0");
    return 0;
}
