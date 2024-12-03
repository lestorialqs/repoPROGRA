#include "trie.h"
#include <unordered_set>
#include <algorithm>

using namespace std;

Trie::Trie() {
    root = new TrieNode();
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
    TrieNode* actual = root;

    // Convertir la palabra clave a minúsculas
    string lower_palabra_clave = palabra_clave;
    transform(lower_palabra_clave.begin(), lower_palabra_clave.end(), lower_palabra_clave.begin(), ::tolower);

    for (char ch : lower_palabra_clave) {
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

vector<string> Trie::searchByPrefix(const string& prefix) const {
    TrieNode* actual = root;

    // Convertir el prefijo a minúsculas
    string lower_prefix = prefix;
    transform(lower_prefix.begin(), lower_prefix.end(), lower_prefix.begin(), ::tolower);

    // Recorrer el Trie según el prefijo
    for (char ch : lower_prefix) {
        if (!actual->children.count(ch)) {
            return {}; // Prefijo no encontrado
        }
        actual = actual->children[ch];
    }

    // Recolectar todas las películas desde este nodo
    vector<string> result;
    collectMovies(actual, result);
    return result;
}

vector<string> Trie::searchByWord(const string& word) const {
    TrieNode* actual = root;

    // Convertir la palabra a minúsculas
    string lower_word = word;
    transform(lower_word.begin(), lower_word.end(), lower_word.begin(), ::tolower);

    // Recorrer el Trie según la palabra
    for (char ch : lower_word) {
        if (!actual->children.count(ch)) {
            return {}; // Palabra no encontrada
        }
        actual = actual->children[ch];
    }

    // Si no es el final de una palabra, no es válida
    if (!actual->wordend) {
        return {};
    }

    return actual->movies;
}

vector<string> Trie::searchByPhrase(const string& phrase) const {
    vector<string> results;

    // Convertir la frase a minúsculas
    string lower_phrase = phrase;
    transform(lower_phrase.begin(), lower_phrase.end(), lower_phrase.begin(), ::tolower);

    // Buscar en las películas asociadas
    collectMovies(root, results);

    // Usar un set para evitar duplicados
    unordered_set<string> uniques;

    for (const string& movie : results) {
        string lower_movie = movie;
        transform(lower_movie.begin(), lower_movie.end(), lower_movie.begin(), ::tolower);

        if (lower_movie.find(lower_phrase) != string::npos) {
            uniques.insert(movie); // Agregar solo títulos únicos
        }
    }

    // Convertir el set de vuelta a un vector
    vector<string> filtered_results(uniques.begin(), uniques.end());

    return filtered_results;
}

void Trie::collectMovies(TrieNode* node, vector<string>& result) const {
    if (node->wordend) {
        result.insert(result.end(), node->movies.begin(), node->movies.end());
    }

    for (auto& p : node->children) {
        collectMovies(p.second, result);
    }
}