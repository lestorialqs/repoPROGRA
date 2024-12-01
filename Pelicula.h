//
// Created by hanksvi on 30/11/2024.
//

#ifndef REPOPROGRA_PELICULA_H
#define REPOPROGRA_PELICULA_H
#include <iostream>
using namespace std;
class Pelicula{
    string id;
    string name;
    string sinopsis;
public:
    Pelicula(){}
    Pelicula(string _id, string _name, string _sinopsis): id(_id), name(_name), sinopsis(_sinopsis){}

    string getId(){return id;}
    string getName(){return name;}
    string getSinopsis(){return sinopsis;}

    ~Pelicula(){}
};


#endif //REPOPROGRA_PELICULA_H
