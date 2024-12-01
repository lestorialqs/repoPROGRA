#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Arbol.h"
#include <fstream>
#include <sstream>
using namespace std;

void cargarPeliculasAlArbol(Arbol &arbol, const string &filename) {
    ifstream archivo(filename);
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, titulo, sinopsis, tag, split, source_sinopsis;

        // Leemos los atributos de la película separados por '|'
        getline(ss, id, '|');
        getline(ss, titulo, '|');
        getline(ss, sinopsis, '|');
        getline(ss, tag, '|');
        getline(ss, split, '|');
        getline(ss, source_sinopsis, '|');

        // Creamos un objeto Pelicula con los atributos
        Pelicula pelicula(id, titulo, sinopsis, tag, split, source_sinopsis);

        // Insertamos la película en el árbol
        arbol.insertarNodo(pelicula);
    }
}

int main(){
    Arbol arbol;
    cargarPeliculasAlArbol(arbol, "limpio2.csv");

    arbol.buscadorPalabra("barco");
    cout << "Buscando 'barco':" << endl;
    arbol.buscadorPalabra("barco");

}