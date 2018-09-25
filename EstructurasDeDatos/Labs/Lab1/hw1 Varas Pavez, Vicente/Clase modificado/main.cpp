#include <iostream>
#include "clase.h"

using namespace std;

int main() {
	clase c(5);
	c.incMyInt();
	c.incMyIntBy(3);
	std::cout << c.getMyInt() << std::endl;
}
