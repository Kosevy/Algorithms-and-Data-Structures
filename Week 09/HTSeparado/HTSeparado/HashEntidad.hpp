#ifndef __ENTIDADHASH_HPP__
#define __ENTIDADHASH_HPP__

class HashEntidad {
private:
	int key;
	int value;

public:
	HashEntidad(){}
	HashEntidad(int key, int value) {
		this->key = key;
		this->value = value;
	}
	int getKey() {
		return key;
	}
	int getValue() {
		return value;
	}
};



#endif // !__ENTIDADHASH_HPP__
