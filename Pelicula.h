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
    string tag;
    string split;
    string source_sinopsis;
public:
    Pelicula(){}
    Pelicula(string& _id, string& _titulo, string& _sinopsis, string& _tag, string& _split, string& _source):
    id(_id), titulo(_titulo), sinopsis(_sinopsis), tag(_tag), split(_split), source_sinopsis(_source){}

    const string& getId() const {return id;}
    const string& getTitulo() const {return titulo;}
    const string& getSinopsis() const {return sinopsis;}


    ~Pelicula(){}
};


#endif //REPOPROGRA_PELICULA_H
