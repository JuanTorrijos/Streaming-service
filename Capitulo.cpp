#include <stdio.h>
#include "Capitulo.h"
#include <iostream>

using namespace std;

Capitulo::Capitulo(){
	nombre = "***";
	calificacion = 0;
}

Capitulo::Capitulo(string nom, int cal){
	nombre = nom;
	calificacion = cal;
}

string Capitulo::getNom(){
	return nombre;
}

int Capitulo::getCal(){
	return calificacion;
}

void Capitulo::setCal(int cal){
	calificacion = cal;
}