#include "Trie.h"
#include <unordered_set>
// Destructor del nodo TrieNode
TrieNode::~TrieNode() {
    for (auto& child : children) {
        delete child.second;
    }
}

// Constructor y destructor de Trie
Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

// Inserción de palabra clave, título y sinopsis
void Trie::insert(const string& palabraClave, const string& movie, const string& synopsis) {
    TrieNode* current = root;

    // Convertir la palabra clave a minúsculas
    string lowerPalabraClave = palabraClave;
    transform(lowerPalabraClave.begin(), lowerPalabraClave.end(), lowerPalabraClave.begin(), ::tolower);


    // Insertar en el trie
    for (char ch : lowerPalabraClave) {
        if (!current->children[ch]) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }

    current->wordEnd = true;

    // Evitar duplicados
    if (find(current->movies.begin(), current->movies.end(), movie) == current->movies.end()) {
        current->movies.push_back(movie);
        current->synopses.push_back(synopsis);
    }
}

// Búsqueda por prefijo
vector<string> Trie::searchByPrefix(const string& prefix) const {
    TrieNode* current = root;

    // Convertir prefijo a minúsculas
    string lowerPrefix = prefix;
    transform(lowerPrefix.begin(), lowerPrefix.end(), lowerPrefix.begin(), ::tolower);

    for (char ch : lowerPrefix) {
        if (!current->children[ch]) {
            return {};
        }
        current = current->children[ch];
    }

    vector<string> result;
    vector<string> dummySynopses;
    collectMovies(current, result, dummySynopses);
    return result;
}

// Búsqueda por palabra
vector<string> Trie::searchByWord(const string& word) const {
    return searchByPrefix(word);
}




// Búsqueda por frase en título o sinopsis
vector<pair<string, string>> Trie::searchByPhrase(const string& phrase) const {
    vector<string> results;
    vector<string> synopses;
    collectMovies(root, results, synopses);

    // Usar un set para evitar duplicados
    unordered_set<string> uniques;

    vector<pair<string, string>> filteredResults;
    string lowerPhrase = phrase;
    transform(lowerPhrase.begin(), lowerPhrase.end(), lowerPhrase.begin(), ::tolower);


    for (size_t i = 0; i < results.size(); ++i) {
        string lowerTitle = results[i];
        string lowerSynopsis = synopses[i];

        transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
        transform(lowerSynopsis.begin(), lowerSynopsis.end(), lowerSynopsis.begin(), ::tolower);

        if ((lowerTitle.find(lowerPhrase) != string::npos || lowerSynopsis.find(lowerPhrase) != string::npos) &&
            uniques.find(lowerTitle) == uniques.end()) {

            filteredResults.emplace_back(results[i], synopses[i]);
            uniques.insert(lowerTitle); // Marcar el título como añadido
        }
    }
    return filteredResults;
}



// Recopilar títulos y sinopsis desde un nodo Trie
void Trie::collectMovies(TrieNode* node, vector<string>& result, vector<string>& synopses) const {
    if (node->wordEnd) {
        result.insert(result.end(), node->movies.begin(), node->movies.end());
        synopses.insert(synopses.end(), node->synopses.begin(), node->synopses.end());
    }

    for (auto& child : node->children) {
        collectMovies(child.second, result, synopses);
    }
}

vector<string> Trie::searchByTitle(const string& phrase) const {
    vector<string> results;
    vector<string> dummySynopses; // Sinopsis no son necesarias aquí
    collectMovies(root, results, dummySynopses);

    // Usar un set para evitar duplicados
    unordered_set<string> uniques;
    vector<string> filteredResults;

    string lowerPhrase = phrase;
    transform(lowerPhrase.begin(), lowerPhrase.end(), lowerPhrase.begin(), ::tolower);

    for (const string& title : results) {
        string lowerTitle = title;
        transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

        if (lowerTitle.find(lowerPhrase) != string::npos && uniques.find(lowerTitle) == uniques.end()) {
            filteredResults.push_back(title);
            uniques.insert(lowerTitle); // Evitar duplicados
        }
    }
    return filteredResults;
}
