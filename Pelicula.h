#ifndef Pelicula_h
#define Pelicula_h
#include <iostream>
#include "Video.h"
using namespace std;

class Pelicula: public Video{
	private:
		int nominaciones;
		
	public:
		Pelicula();
		Pelicula(string, string, int, int, int, int);
		void muestraDatos();
};



#endif 

