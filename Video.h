//
//  Video.h
//  ProyectoIntegrador
//
//  Created by Juan Torrijos on 03/07/20.
//  Copyright © 2020 Juan Torrijos. All rights reserved.
//

#ifndef Video_h
#define Video_h
#include <iostream>
#include "Capitulo.h"
#include <vector>

using namespace std;

class Video {
protected:
    string tipoVideo;
    string nombreVideo;
    string genero;
    int calificacion;
    int anioLanzamiento;
    int duracion;
    
public:
	vector<Capitulo> episodios;
    void calificaVideo(int);
    virtual void muestraDatos() = 0;
	virtual void agregaCap(Capitulo);
	virtual int getCap();
    Video();
    Video(string, string, string, int, int, int);
    Video(string, string, string, int, int);
    string getNombre();
	string getGenero();
	string getTipo();
    int getCalificacion();
	friend ostream & operator << (ostream &out, const Video &v);
};

#endif /* Video_h */
