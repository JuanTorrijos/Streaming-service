#include <iostream>
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula():Video(" "," "," ", 0, 0, 0){
	nominaciones = 0;
}

Pelicula::Pelicula(string nom, string gen, int cal, int anio, int dur, int nomin):Video("Pelicula", nom, gen, cal, anio, dur){
	nominaciones = nomin;
}

void Pelicula::muestraDatos(){
	cout<<endl<<"Tipo de video: "<<tipoVideo<<endl;
    cout<<"Nombre del video: "<<nombreVideo<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Calificacion: "<<calificacion<<endl;
    cout<<"Anio de lanzamiento: "<<anioLanzamiento<<endl;
    cout<<"Duracion: "<<duracion<<endl;
	cout<<"Nominaciones: "<<nominaciones<<endl;
}