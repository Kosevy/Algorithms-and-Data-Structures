#include "pch.h"
#include "Pila.h"
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
    do{
        temporal = Objpila->pop();
        if(temporal !=nullptr)
        {
            cout << temporal->muestra();
        }

    } while (temporal != nullptr);



    system("pause>0");
    return 0;
}
