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



#include <mutex>

class Arbol {
private:
    Nodo* raiz;
    std::mutex mtx; // Mutex para sincronización

    Nodo* insertarNodoAux(Nodo* nodo, Pelicula* p);
    void buscadorPalabraAux(Nodo* nodo, string palabra);
    void liberarMemoria(Nodo* nodo);

public:
    Arbol() : raiz(nullptr) {}
    ~Arbol() { liberarMemoria(raiz); }

    void insertarNodo(Pelicula* p) {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueo del mutex
        raiz = insertarNodoAux(raiz, p);
    }

    void buscadorPalabra(string palabra) {
        std::lock_guard<std::mutex> lock(mtx); // Bloqueo del mutex
        buscadorPalabraAux(raiz, palabra);
    }
};




#endif //REPOPROGRA_ARBOL_H
