#include "trie.h"
#include <algorithm>

using namespace std;

Trie::Trie() {
    root=new TrieNode();
}

Trie::~Trie() {
    deleteTrie(root);
}

void Trie::deleteTrie(TrieNode* node) {
    for (auto& pair : node->children) {
        deleteTrie(pair.second);
    }
    delete node;
}

void Trie::insert(const string& palabra_clave, const string& movie) {
    TrieNode* actual=root;

    // Convertir la palabra clave a minúsculas
    string lowerpalabra_clave=palabra_clave;
    transform(lowerpalabra_clave.begin(), lowerpalabra_clave.end(), lowerpalabra_clave.begin(), ::tolower);

    for (char ch:lowerpalabra_clave) {
        if (!actual->children.count(ch)) {
            actual->children[ch] = new TrieNode();
        }
        actual = actual->children[ch];
    }
    actual->wordend = true;

    // Evitar duplicados en la lista de películas
    if (find(actual->movies.begin(), actual->movies.end(), movie) == actual->movies.end()) {
        actual->movies.push_back(movie);
    }
}

vector<string> Trie::searchInTitles(const string& palabra_clave) const {
    TrieNode* actual = root;

    // Convertir la palabra clave a minúsculas
    string lowerpalabra_clave = palabra_clave;
    transform(lowerpalabra_clave.begin(), lowerpalabra_clave.end(), lowerpalabra_clave.begin(), ::tolower);

    // Si la palabra clave no existe, retornar vacío
    for (char ch : lowerpalabra_clave) {
        if (!actual->children.count(ch)) {
            return {};
        }
        actual = actual->children[ch];
    }

    // Recoger todas las peliculas asociadas a este nodo y sus descendientes
    vector<string> result;
    collectMovies(actual, result);
    return result;
}

void Trie::collectMovies(TrieNode* node, vector<std::string> &result) const{
    if(node->wordend){
        // Si llegamos al final de una palabra, agregamos las peliculas
        result.insert(result.end(), node->movies.begin(), node->movies.end());
    }

    // Recursivamente buscar en los hijos
    for(auto& p: node->children){
        collectMovies(p.second, result);
    }

}

