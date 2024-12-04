#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Trie.h"
#include "Pelicula.h"
using namespace std;

// Función para insertar palabras clave, títulos completos y sinopsis en el Trie
void insertWords(Trie& trie, const string& text, const Pelicula& movie) {
    stringstream ss(text);
    string word;
    while (ss >> word) {
        trie.insert(word, movie.getTitulo(), movie.getSinopsis()); // Insertar palabra clave
    }

    // Insertar el título completo como frase exacta
    trie.insert(text, movie.getTitulo(), movie.getSinopsis());
}

// Función para cargar películas desde un archivo CSV
void loadMovies(Trie& trie) {
    ifstream file("../limpio2.csv");
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de la base de datos.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string imdb_id, title, plot_synopsis, tags, split, synopsis_source;

        // Asumir separador '|'
        getline(ss, imdb_id, '|');
        getline(ss, title, '|');
        getline(ss, plot_synopsis, '|');
        getline(ss, tags, '|');
        getline(ss, split, '|');
        getline(ss, synopsis_source, '|');

        Pelicula movie(imdb_id, title, plot_synopsis, tags, split, synopsis_source);
        // Insertar en el Trie
        insertWords(trie, title, movie);
    }

    file.close();
    cout << "Base de datos cargada con éxito.\n";
}

int main() {
    Trie trie;

    // Cargar las películas desde el archivo
    loadMovies(trie);

    int choice;
    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Buscar por prefijo\n";
        cout << "2. Buscar por palabra clave\n";
        cout << "3. Buscar por frase exacta\n";
        cout << "4. Buscar en sinopsis\n";
        cout << "5. Salir\n";
        cout << "Elija una opción: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string prefix;
            cout << "Ingrese un prefijo para buscar películas: ";
            getline(cin, prefix);

            vector<string> results = trie.searchByPrefix(prefix);
            if (!results.empty()) {
                cout << "Películas encontradas:\n";
                for (const string& movie : results) {
                    cout << "- " << movie << "\n";
                }
            } else {
                cout << "No se encontraron películas para el prefijo ingresado.\n";
            }
        } else if (choice == 2) {
            string keyword;
            cout << "Ingrese una palabra clave para buscar películas: ";
            getline(cin, keyword);

            vector<string> results = trie.searchByWord(keyword);
            if (!results.empty()) {
                cout << "Películas encontradas:\n";
                for (const string& movie : results) {
                    cout << "- " << movie << "\n";
                }
            } else {
                cout << "No se encontraron películas para la palabra clave ingresada.\n";
            }
        } else if (choice == 3) {
            string phrase;
            cout << "Ingrese una frase exacta para buscar películas: ";
            getline(cin, phrase);

            vector<pair<string, string>> results = trie.searchByPhrase(phrase);
            if (!results.empty()) {
                cout << "Películas encontradas:\n";
                for (const auto& [title, synopsis] : results) {
                    cout << "- Título: " << title << endl;
                }
            } else {
                cout << "No se encontraron películas para la frase exacta ingresada.\n";
            }
        } else if (choice == 4) {
            string phrase;
            cout << "Ingrese una frase para buscar en las sinopsis: ";
            getline(cin, phrase);

            vector<pair<string, string>> results = trie.searchByPhrase(phrase);
            if (!results.empty()) {
                cout << "Películas encontradas en las sinopsis:\n";
                for (const auto& [title, synopsis] : results) {
                    if (synopsis.find(phrase) != string::npos) { // Verificar coincidencia en sinopsis
                        cout << "- Título: " << title << endl;
                    }
                }
            } else {
                cout << "No se encontraron coincidencias en las sinopsis para la frase ingresada.\n";
            }
        } else if (choice != 5) {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (choice != 5);

    cout << "¡Gracias por usar el sistema de búsqueda de películas!\n";
    return 0;
}