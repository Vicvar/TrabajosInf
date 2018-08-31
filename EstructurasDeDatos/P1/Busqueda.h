#include "ListADT.h"
class Busqueda{

	public:
		Busqueda();
		static bool lineal(ListADT*,int);
		static bool binaria(ListADT*,int,int,int);
		static bool exponencial(ListADT*,int);
};