#include "trie.h"
#include <algorithm>
#include <sstream>

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

void Trie::insert(const string& texto, const string& movie) {
    TrieNode* actual = root;

    string lowerTexto = texto;
    transform(lowerTexto.begin(), lowerTexto.end(), lowerTexto.begin(), ::tolower);

    stringstream ss(lowerTexto);
    string word;

    while (ss >> word) {
        actual = root;
        for (char ch : word) {
            if (!actual->children.count(ch)) {
                actual->children[ch] = new TrieNode();
            }
            actual = actual->children[ch];
        }
        actual->wordend = true;

        if (find(actual->movies.begin(), actual->movies.end(), movie) == actual->movies.end()) {
            actual->movies.push_back(movie);
        }
    }
}

vector<string> Trie::searchInTitles(const string& keyword) const {
    TrieNode* actual = root;

    string lowerKeyword = keyword;
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);

    for (char ch : lowerKeyword) {
        if (!actual->children.count(ch)) {
            return {};
        }
        actual = actual->children[ch];
    }

    vector<string> result;
    collectMovies(actual, result);
    return result;
}

void Trie::collectMovies(TrieNode* node, vector<string>& result) const {
    if (node->wordend) {
        result.insert(result.end(), node->movies.begin(), node->movies.end());
    }

    for (auto& p : node->children) {
        collectMovies(p.second, result);
    }

}

vector<string> Trie::searchPhrase(const string& phrase) const {
    string lowerPhrase = phrase;
    transform(lowerPhrase.begin(), lowerPhrase.end(), lowerPhrase.begin(), ::tolower);

    stringstream ss(lowerPhrase);
    string word;
    vector<string> commonResults;

    if (ss >> word) {
        commonResults = searchInTitles(word);
    }

    while (ss >> word && !commonResults.empty()) {
        vector<string> currentResults = searchInTitles(word);
        vector<string> intersection;

        set_intersection(
                commonResults.begin(), commonResults.end(),
                currentResults.begin(), currentResults.end(),
                back_inserter(intersection)
        );

        commonResults = intersection;
    }

    return commonResults;
}
