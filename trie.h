#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool wordEnd = false;
    vector<string> movies; // Títulos de películas relacionadas
    vector<string> synopses; // Sinopsis relacionadas

    TrieNode() = default;
    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;

    void collectMovies(TrieNode* node, vector<string>& result, vector<string>& synopses) const;

public:
    Trie();
    ~Trie();
    void insert(const string& palabraClave, const string& movie, const string& synopsis);
    vector<string> searchByPrefix(const string& prefix) const;
    vector<string> searchByWord(const string& word) const;
    vector<pair<string, string>> searchByPhrase(const string& phrase) const; // Retorna título y sinopsis
    vector<string> searchByTitle(const string& phrase) const;
};

#endif // TRIE_H



