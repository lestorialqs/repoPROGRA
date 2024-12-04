//
// Created by Asus on 3/12/2024.
//

#ifndef SEARCHSTRATEGY_H
#define SEARCHSTRATEGY_H
#include "Trie.h"


class SearchStrategy {
public:
    virtual vector<string> search(const Trie& trie, const string& query) = 0;
    virtual ~SearchStrategy() = default;
};


class ExactMatchStrategy : public SearchStrategy {
public:
    vector<pair<string, string>> search(const Trie& trie, const string& query) override {
        return trie.searchByTitle(query);
    }
};

class SynopsisSearchStrategy : public SearchStrategy {
public:
    vector<pair<string, string>> search(const Trie& trie, const string& query) override {
        return trie.searchByPhrase(query);

    }
};

#endif //SEARCHSTRATEGY_H
