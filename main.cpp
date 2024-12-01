#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <thread> // Incluir para trabajar con hilos
#include <vector>
#include <mutex> // Para manejo de recursos compartidos (en caso de ser necesario)
using namespace std;

class Pelicula {
public:
    string id, titulo, sinopsis, tag, split, source_sinopsis;
    Pelicula(string id, string titulo, string sinopsis, string tag, string split, string source_sinopsis) :
            id(id), titulo(titulo), sinopsis(sinopsis), tag(tag), split(split), source_sinopsis(source_sinopsis) {}

    string getId() { return id; }
    string getTitulo() { return titulo; }
    string getSinopsis() { return sinopsis; }
};

// Definir la estructura Nodo
struct Nodo {
    Pelicula* pelicula;
    Nodo* left;
    Nodo* right;

    Nodo(Pelicula* p) : pelicula(p), left(nullptr), right(nullptr) {}
};

class Arbol {
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo* nodo, Pelicula* p);
    void buscadorPalabraAux(Nodo* nodo, string palabra);
    void liberarMemoria(Nodo* nodo); // Liberar memoria del árbol

public:
    Arbol() : raiz(nullptr) {}
    ~Arbol() { liberarMemoria(raiz); }

    void insertarNodo(Pelicula* p) {
        raiz = insertarNodoAux(raiz, p);
    }

    void buscadorPalabra(string palabra) {
        buscadorPalabraAux(raiz, palabra);
    }
};

// Inserta nodos en el árbol
Nodo* Arbol::insertarNodoAux(Nodo* nodo, Pelicula* p) {
    if (p == nullptr) {
        cerr << "Error: intento de insertar una película nula" << endl;
        return nodo;
    }
    if (nodo == nullptr) {
        return new Nodo(p);
    }
    if (nodo->pelicula->getId() < p->getId()) {
        nodo->right = insertarNodoAux(nodo->right, p);
    } else {
        nodo->left = insertarNodoAux(nodo->left, p);
    }
    return nodo;
}


// Busca una palabra en el árbol
void Arbol::buscadorPalabraAux(Nodo* nodo, string palabra) {
    if (nodo == nullptr) return;
    if (nodo->pelicula->getTitulo().find(palabra) != string::npos ||
        nodo->pelicula->getSinopsis().find(palabra) != string::npos) {
        cout << "Titulo: " << nodo->pelicula->getTitulo() << " ";
        cout << "Sinopsis: " << nodo->pelicula->getSinopsis() << endl;
    }
    buscadorPalabraAux(nodo->left, palabra);
    buscadorPalabraAux(nodo->right, palabra);
}

// Liberar la memoria del árbol
void Arbol::liberarMemoria(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarMemoria(nodo->left);
    liberarMemoria(nodo->right);
    delete nodo->pelicula;
    delete nodo;
}

// Función para cargar las películas al árbol de manera concurrente
void cargarPeliculasAlArbol(Arbol* arbol, const string& filename) {
    ifstream archivo(filename);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo '" << filename << "'." << endl;
        return; // Salir de la función si no se puede abrir el archivo
    }

    string linea;
    vector<thread> hilos;  // Vector para almacenar los hilos

    // Dividir la carga de películas en 4 hilos (esto depende de cuántas líneas tenga el archivo)
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, titulo, sinopsis, tag, split, source_sinopsis;

        getline(ss, id, '|');
        getline(ss, titulo, '|');
        getline(ss, sinopsis, '|');
        getline(ss, tag, '|');
        getline(ss, split, '|');
        getline(ss, source_sinopsis, '|');

        Pelicula* pelicula = new Pelicula(id, titulo, sinopsis, tag, split, source_sinopsis);

        // Crear un hilo para insertar la película en el árbol
        hilos.push_back(thread([arbol, pelicula](){
            arbol->insertarNodo(pelicula);
        }));
    }

    // Esperar que todos los hilos terminen
    for (auto& t : hilos) {
        t.join();
    }
}

int main() {
    Arbol* arbol = new Arbol();
    if (!arbol) {
        cerr << "Error al crear el árbol" << endl;
        return -1;
    }
    cargarPeliculasAlArbol(arbol, "limpio2.csv");

    cout << "Buscando 'barco':" << endl;
    arbol->buscadorPalabra("barco");

    delete arbol;
    return 0;
}

