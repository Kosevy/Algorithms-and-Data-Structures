#ifndef __HASHTABLA_HPP__
#define __HASHTABLA_HPP__
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "HashEntidad.hpp"
using namespace std;

typedef unsigned int size_t;

class HashTablaA {
private:
	vector<list<HashEntidad>> theLists;   // Tabla
	int  currentSize;

public:
	explicit HashTablaA(int size = 101) : currentSize{ 0 }
	{
		theLists.resize(101);
	}

	void makeEmpty()
	{
		for (auto & thisList : theLists)
			thisList.clear();
	}	

	bool insert(HashEntidad && x)
	{
		auto & whichList = theLists[myhash(x.getKey())]; //Obtenemos la lista de elementos según el hash obtenido
		
		whichList.push_back(x); //Agregamos el nuevo elemento a la lista

		return true;
	}	

	void DispAll() {
		int pos = 0;
		for (auto & thisList : theLists) {
			cout << "Key: " + to_string(pos) << " | ";
			for (auto & it : theLists[pos]) {
				cout << it.getKey() << ",";
			}
			cout << endl;
			pos++;
		}
	}

private:		
	
	size_t myhash(const int key) const {
		size_t hashVal=key;
		hashVal %= theLists.size();
		//hashVal = 10; //Prueba para verificar como se almacenan los elementos si obtienen el mismo hash
		return(hashVal);
	}
};

#endif // !__HASHTABLA_HPP__
