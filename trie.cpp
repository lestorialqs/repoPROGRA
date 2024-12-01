#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool wordend;
    vector<string> movies;

    TrieNode() : wordend(false) {}
};

class Trie {
private:
    TrieNode* root;

    void deleteTrie(TrieNode* node);

public:
    Trie();
    ~Trie();

    void insert(const string& keyword, const string& movie);
    vector<string> searchInTitles(const string& keyword) const;
};

#endif // TRIE_H