#include <iostream>
#include "Serie.h"
using namespace std;

Serie::Serie():Video(" ", " ", " ", 0, 0, 0){
	capitulos = 0;
	temporada = 0;
}

Serie::Serie(string nom, string gen, int cal, int anio, int dur, int cap, int temp):Video("Serie", nom, gen, cal, anio, dur){
	capitulos = cap;
	temporada = temp;
}

void Serie::muestraDatos(){
	cout<<endl<<"Tipo de video: "<<tipoVideo<<endl;
    cout<<"Nombre del video: "<<nombreVideo<<endl;
    cout<<"Genero: "<<genero<<endl;
    cout<<"Calificacion: "<<calificacion<<endl;
    cout<<"Anio de lanzamiento: "<<anioLanzamiento<<endl;
    cout<<"Duracion: "<<duracion<<endl;
	cout<<"Temporadas: "<<temporada<<endl;
	cout<<"Capitulos: "<<capitulos<<endl;
	cout<<"\t\tCapitulo \t\t| "<<"Calificacion"<<endl;
	for(int i = 0 ; i<episodios.size() ; i++){
		cout<<"\t"<<i+1<<". "<<episodios[i].getNom()<<"\t| "<<episodios[i].getCal()<<endl;
	}
}

void Serie::agregaCap(Capitulo c){
	episodios.push_back(c);
}

int Serie::getCap(){
	return capitulos;
}

ostream & operator << (ostream &out, const Serie &s) 
{  
	out << "Nombre: " << s.nombreVideo << endl;
	out << "Capitulos: " << endl;
	vector<Capitulo> eps = s.episodios; 
	for (int i=0 ; i<eps.size() ; i++){
		Capitulo ep = eps[i];
		cout<<"\t"<<i+1<<". "<<ep.getNom()<<endl;
	}
    return out; 
} 