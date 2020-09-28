#ifndef Capitulo_h
#define Capitulo_h
#include <iostream>

using namespace std;

class Capitulo {
	private:
		string nombre;
		int calificacion;
		
	public:
		Capitulo();
		Capitulo(string, int);
		string getNom();
		int getCal();
		void setCal(int);
	
};

#endif

