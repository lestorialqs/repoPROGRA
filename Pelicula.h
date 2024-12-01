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
    Pelicula(string _id, string _titulo, string _sinopsis, string _tag, string _split, string _source):
    id(_id), titulo(_titulo), sinopsis(_sinopsis), tag(_tag), split(_split), source_sinopsis(_source){}

    string getId(){return id;}
    string getTitulo(){return titulo;}
    string getSinopsis(){return sinopsis;}

    void setId(string i){id = i;}
    void setTitulo(string t){titulo = t;}
    void setSinopsis(string s){sinopsis = s;}
    void setTag(string ta){tag = ta;}
    void setSplit(string s){split = s;}
    void setSource(string s){source_sinopsis = s;}
    ~Pelicula(){}
};


#endif //REPOPROGRA_PELICULA_H
