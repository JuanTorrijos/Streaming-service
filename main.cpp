//
//  main.cpp
//
//  Created by Juan Torrijos on 21/07/20.
//  Copyright © 2020 Juan Torrijos. All rights reserved.
//

#include <iostream>
#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Capitulo.h"
#include <vector>

using namespace std;

int main(){
	vector<Video*> videos;
	
    int opc, cali, opcion;
	opc = 0;
	while (opc <6){
    
    cout<<"\n=== Menu ==="<<endl;
    cout<<"1. Cargar videos"<<endl;
    cout<<"2. Calificar videos"<<endl;
	cout<<"3. Mostrar videos segun calificacion o genero"<<endl;
	cout<<"4. Mostrar episodios de una serie segun la calificacion"<<endl;
	cout<<"5. Mostrar peliculas segun la calificacion"<<endl;
	cout<<"6. Salir"<<endl;
    cout<<"\n Introduzca la opcion deseada: "; 
	cin>>opc;
	
	if (opc<1 || opc>6){
		cout << "Opcion invalida, por favor introduce una correcta"<<endl;
		opc = 0;
	}
	
		switch (opc){
			case 1:{
				vector<string> capsAvatar;
					capsAvatar.insert(capsAvatar.end(), {"El niño en el iceberg", "El regreso del Avatar", "El templo del Aire del Sur"});
				vector<string> capsTBBT;
					capsTBBT.insert(capsTBBT.end(), {"The Big Bran Hypothesis", "The Fuzzy Boots Corollary"});
				Video *peli1 = new Pelicula("Mulan","Infantil",5,2000,120, 1);
				videos.push_back(peli1);
				Video *peli2 = new Pelicula("Ender's Game","Ficcion",4,2014,120, 3);
				videos.push_back(peli2);
				Video *peli3 = new Pelicula("It","Terror",2,2018,120, 0);
				videos.push_back(peli3);

				Video *serie1 = new Serie("Avatar","Animada",5,2004,30, 3, 3);
				for (int i=0 ; i<serie1->getCap() ; i++){
					string nomcap = capsAvatar[i];
					Capitulo cap(nomcap, 5-i);
					serie1->agregaCap(cap);
				}
				videos.push_back(serie1);

				Video *serie2 = new Serie("The Big Bang Theory","Comedia",5,2009,30, 2, 10);
				for (int i=0 ; i<serie2->getCap() ; i++){
					string nomcap = capsTBBT[i];
					Capitulo cap(nomcap, 5-i);
					serie2->agregaCap(cap);
				}
				videos.push_back(serie2);
				
			}
				break;
				
			case 2:{
				if(videos.size() == 0){
					cout<<"No hay datos cargados, por favor selecciona 1 para cargar los archivos"<<endl;
				}
				else {
					cout<<"--- Lista de videos ---"<<endl;
					for (int i=0 ; i<videos.size() ; i++){
						Video *ind = videos[i];
						cout<<i+1<<". "<<*ind;
					}
					
					cout<<"\n ¿Cual deseas calificar?"<<endl;
					cin>>opcion;
					while(opcion<1 || opcion>videos.size()){
						cout << "Opcion invalida, elige otra vez"<<endl;
						cin>>opcion;
					}
					Video *index2 = videos[opcion-1];
					if (index2->getTipo() == "Serie"){
						if(Serie* s = dynamic_cast<Serie*>(videos[opcion-1])) {
							vector<Capitulo> eps = s->episodios;
							cout<<"Selecciona el capitulo a calificar"<<endl;
							for (int i=0 ; i<eps.size() ; i++){
								cout<<i+1<<". "<<eps[i].getNom()<<endl;
							}
							cin>>opcion;
							cout<<"Introduce la calificacion: ";
							cin>>cali;
							while(cali<1 || cali>5){
							cout << "Opcion invalida, introduce un numero de 1-5"<<endl;
							cin>>cali;
							}
							s->episodios[opcion-1].setCal(cali);
							cout<<"El capitulo "<<s->episodios[opcion-1].getNom()<<" tiene una calificacion de: "<<s->episodios[opcion-1].getCal();
						}
						
					}
					else {
						cout<<"Introduce la calificacion: ";
						cin>>cali;
						while(cali<1 || cali>5){
						cout << "Opcion invalida, introduce un numero de 1-5"<<endl;
						cin>>cali;
						}
						index2->calificaVideo(cali);
						cout<<"El video "<<index2->getNombre()<<" tiene una calificacion de: "<<index2->getCalificacion();
					}
				}
				
			}
				break;
				
			case 3:{
				if(videos.size() == 0){
					cout<<"No hay datos cargados, por favor selecciona 1 para cargar los archivos"<<endl;
				}
				else{
					cout << "Criterio a buscar:" << endl;
					cout << "1. Calificacion" << endl << "2. Genero" << endl;
					cin>>opcion;
					while(opcion<1 || opcion>2){
						cout << "Opcion invalida, elige otra vez"<<endl;
						cin>>opcion;
					}
					if (opcion == 1){
						cout << "Introduce la calificacion: (1-5)";
						cin>>cali;
						while(cali<1 || cali>5){
						cout << "Opcion invalida, introduce un numero de 1-5"<<endl;
						cin>>cali;
						}
						for (int i=0 ; i<videos.size() ; i++){
							Video *ind = videos[i];
							if (ind->getCalificacion() == cali){
								ind->muestraDatos();
							}
						}
					}
					else {
						string gen;
						cout << "Introduce el genero: (";
						for(int i=0 ; i<videos.size() ; i++){
							if(i==videos.size()-1){
								cout<<videos[i]->getGenero();
							}
							else{
								cout<<videos[i]->getGenero()<<"/";
							}
						}
						cout<<")"<<endl;
						cin>>gen;
						int cont = 0;
						for (int i=0 ; i<videos.size() ; i++){
							Video *ind = videos[i];
							if (ind->getGenero() == gen){
								cont++;
								ind->muestraDatos();
							}
						}
						if (cont == 0){
							cout<<"Ningun video cumple con el criterio"<<endl;
						}
					}
				}
			}
				break;
			
			case 4:{
				if(videos.size() == 0){
					cout<<"No hay datos cargados, por favor selecciona 1 para cargar los archivos"<<endl;
				}
				else{
					bool pass = false;
					cout << "Elige la serie" << endl;
					for (int i=0 ; i<videos.size() ; i++){
						if(videos[i]->getTipo() == "Serie"){
							cout<<i+1<<". "<<videos[i]->getNombre()<<endl;
							
						}
					}
					cin>>opcion;
					while(pass == false){
						if(opcion < 1){
							cout << "Opcion invalida, elige otra vez"<<endl;
							cin>>opcion;
						}
						else if(opcion > videos.size()){
							cout << "Opcion invalida, elige otra vez"<<endl;
							cin>>opcion;
						}
						else if(videos[opcion-1]->getTipo() == "Serie"){
							pass = true;
						}
						else{
							cout << "Opcion invalida, elige otra vez"<<endl;
							cin>>opcion;
						}
					}
					cout << "Introduce la calificacion a buscar: (1-5)"<<endl;
					cin>>cali;
					while(cali<1 || cali>5){
						cout << "Opcion invalida, introduce un numero de 1-5"<<endl;
						cin>>cali;
					}
					if(Serie* s = dynamic_cast<Serie*>(videos[opcion-1])) {
						vector<Capitulo> eps = s->episodios;
						for (int i=0 ; i<eps.size() ; i++){
							if(eps[i].getCal() == cali){
								cout << eps[i].getNom() << endl;
							}
						}
					}
				}
			}
				break;
				
			case 5:{
				if(videos.size() == 0){
					cout<<"No hay datos cargados, por favor selecciona 1 para cargar los archivos"<<endl;
				}
				else{
					cout << "Introduce la calificacion: (1-5)";
					cin>>cali;
					while(cali<1 || cali>5){
						cout << "Opcion invalida, introduce un numero de 1-5"<<endl;
						cin>>cali;
					}
					for (int i=0 ; i<videos.size() ; i++){
						if(videos[i]->getTipo() == "Pelicula"){
							if(videos[i]->getCalificacion() == cali){
								videos[i]->muestraDatos();
							}
						}
					}
				}
			}
		}
    }
    return 0;
}
