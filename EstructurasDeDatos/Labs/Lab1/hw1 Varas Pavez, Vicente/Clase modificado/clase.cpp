#include "clase.h"

clase::clase(int myInt) {
	_myInt = myInt;
}

int clase::getMyInt() {
	return _myInt;
}

void clase::incMyInt() {
	_myInt = _myInt+1;
}

void clase::incMyIntBy(int inc){
	_myInt = _myInt + inc;
}
