//
//  Video.cpp
//  ProyectoIntegrador
//
//  Created by Juan Torrijos on 03/07/20.
//  Copyright © 2020 Juan Torrijos. All rights reserved.
//

#include <stdio.h>
#include "Video.h"
#include <iostream>

using namespace std;

void Video::calificaVideo(int calif_vid){
    calificacion = calif_vid;
}
void Video::muestraDatos(){
    cout<<endl<<"Tipo de video: "<<tipoVideo<<endl;
    cout<<"Nombre del video: "<<nombreVideo<<endl;
    cout<<"Género: "<<genero<<endl;
    cout<<"Calificación: "<<calificacion<<endl;
    cout<<"Año de lanzamiento: "<<anioLanzamiento<<endl;
    cout<<"Duración: "<<duracion<<endl;
}

// Constructor 1 que recibe todos los valores
Video::Video(string tipo, string nom, string gen, int cal, int anio, int dur){
    tipoVideo = tipo;
    nombreVideo = nom;
    genero = gen;
    calificacion = cal;
    anioLanzamiento = anio;
    duracion = dur;
}
// Constructor 2 sin calificacion
Video::Video(string tipo, string nom, string gen, int anio, int dur){
    tipoVideo = tipo;
    nombreVideo = nom;
    genero = gen;
    anioLanzamiento = anio;
    duracion = dur;
}

string Video::getNombre() {
    return nombreVideo;
}

string Video::getGenero(){
	return genero;
}

string Video::getTipo(){
	return tipoVideo;
}

int Video::getCalificacion() {
    return calificacion;
}

ostream & operator << (ostream &out, const Video &v) 
{ 
	out << v.nombreVideo << " (" << v.tipoVideo << ")" << endl;
    return out; 
} 

void Video::agregaCap(Capitulo c){
	cout<<c.getNom();
}

int Video::getCap(){
	return 0;
}