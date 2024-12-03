#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children; // Asociaciones de caracteres con nodos hijos
    bool wordend;                            // Marca el final de una palabra o frase
    vector<string> movies;                   // Almacena las películas asociadas al nodo

    TrieNode() : wordend(false) {}
};

class Trie {
private:
    TrieNode* root;

    void deleteTrie(TrieNode* node);

public:
    Trie();
    ~Trie();

    void insert(const string& keyword, const string& movie);        // Inserta una palabra clave asociada a una película
    vector<string> searchByPrefix(const string& prefix) const;     // Busca películas por prefijo
    vector<string> searchByWord(const string& word) const;         // Busca películas por una palabra clave
    vector<string> searchByPhrase(const string& phrase) const;     // Busca películas por una frase exacta
    void collectMovies(TrieNode* node, vector<string>& result) const; // Recolecta las películas desde un nodo y sus descendientes
};

#endif // TRIE_H



