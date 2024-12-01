//
// Created by hanksvi on 30/11/2024.
//

#ifndef REPOPROGRA_ARBOL_H
#define REPOPROGRA_ARBOL_H
#include <iostream>
#include "Pelicula.h"

using namespace std;

struct Nodo{
    Pelicula* pelicula;
    Nodo* left;
    Nodo* right;

    Nodo(Pelicula* p){
        pelicula = p;
        left = nullptr;
        right = nullptr;
    }

};

class Arbol{
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo* nodo, Pelicula* p);
    void buscadorPalabraAux(Nodo* nodo, string palabra);
public:
    void insertarNodo(Pelicula* p){
        raiz = insertarNodoAux(raiz, p);
    }
    void buscadorPalabra(string palabra){
        buscadorPalabraAux(raiz, palabra);
    }
};

Nodo* Arbol::insertarNodoAux(Nodo *nodo, Pelicula *p) {
    if(nodo == nullptr) return new Nodo(p);

    if(nodo->pelicula->getId() < p->getId())
        nodo->right = insertarNodoAux(nodo->right, p);
    else
        nodo->left = insertarNodoAux(nodo->left, p);
    return nodo;
}

void Arbol::buscadorPalabraAux(Nodo *nodo, std::string palabra) {
    if(nodo == nullptr) return;

}

#endif //REPOPROGRA_ARBOL_H
