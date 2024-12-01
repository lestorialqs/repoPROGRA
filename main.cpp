#include <iostream>
#include <fstream>
#include <sstream>
#include "trie.h"

using namespace std;


void insertWords(Trie& trie,const string& text,const string& movie) {
    stringstream ss(text);
    string word;
    while(ss>>word){
        trie.insert(word,movie);
    }
}

void loadMovies(Trie& trie) {
    ifstream file("../limpio2.csv");
    if (!file.is_open()) {
        cerr<<"Error: No se pudo abrir el archivo de la base de datos.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string imdb_id, title, plot_synopsis, tags, split, synopsis_source;

        getline(ss, imdb_id, '|');
        getline(ss, title, '|');
        getline(ss, plot_synopsis, '|');
        getline(ss, tags, '|');
        getline(ss, split, '|');
        getline(ss, synopsis_source, '|');

        insertWords(trie, title, title);
    }

    file.close();
    cout<<"Base de datos cargada con exito.\n";
}

int main() {
    Trie trie;

    //Cargar películas desde la base de datos
    loadMovies(trie);

    string keyword;
    cout<<"Ingrese una palabra clave para buscar peliculas: ";
    getline(cin, keyword);

    vector<string> results=trie.searchInTitles(keyword);
    if (!results.empty()) {
        cout<<"Peliculas encontradas:\n";
        for(const string& movie : results){
            cout << "- " << movie << "\n";
        }
    }else {
        cout<<"No se encontraron peliculas para la palabra clave ingresada.\n";
    }
    return 0;
}
