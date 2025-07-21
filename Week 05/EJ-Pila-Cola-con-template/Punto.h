#pragma once
#include <string>
#include <sstream>
using namespace std;

class Punto {
	int x, y;
public:
	Punto(int x = 0, int y = 0) :x(x), y(y)
	{ }

	string muestra()
	{
		ostringstream lalo;
		lalo << "p( ";
		lalo << x;
		lalo << ", ";
		lalo << y;
		lalo << ")\n";
		return (lalo.str());
	}

};
