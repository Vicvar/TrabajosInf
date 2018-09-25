#include <vector>

class Busqueda{
	private:
		std::vector<int> vect;
	public:
		Busqueda(int N);
		void lineal(int N);
		void binariaRecursiva(int N,int l, int r);
		void binariaIterativa(int N);
		void impVec();
};