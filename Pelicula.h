//
// Created by hanksvi on 30/11/2024.
//

#ifndef REPOPROGRA_PELICULA_H
#define REPOPROGRA_PELICULA_H
#include <iostream>
using namespace std;
class Pelicula{
    string id;
    string titulo;
    string sinopsis;
public:
    Pelicula(){}
    Pelicula(string _id, string _titulo, string _sinopsis): id(_id), titulo(_titulo), sinopsis(_sinopsis){}

    string getId(){return id;}
    string getName(){return titulo;}
    string getSinopsis(){return sinopsis;}

    ~Pelicula(){}
};


#endif //REPOPROGRA_PELICULA_H
