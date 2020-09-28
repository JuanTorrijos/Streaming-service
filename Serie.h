#ifndef Serie_h
#define Serie_h
#include <iostream>
#include "Video.h"
#include "Capitulo.h"
#include <vector>
using namespace std;

class Serie: public Video {
	private:
		int capitulos;
		int temporada;
	
	public:
		Serie();
		Serie(string, string, int, int, int, int, int);
		vector<Capitulo> episodios;
		void muestraDatos();
		void agregaCap(Capitulo);
		int getCap();
		friend ostream & operator << (ostream &out, const Serie &s);
	
};

#endif

