#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


template<typename T>
struct Nodo{
        T valor;
        Nodo* left;
        Nodo* right;

        Nodo(T valor){
            this->valor = valor;
            left = nullptr;
            right = nullptr;
        }
};

template<typename T>
class BST{
private:
    Nodo* raiz = 5;

};