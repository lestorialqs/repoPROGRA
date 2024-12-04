#include "Menu.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Función auxiliar para insertar palabras clave en el Trie
void insertWords(Trie& trie, const string& text, const Pelicula& movie) {
    stringstream ss(text);
    string word;
    while (ss >> word) {
        trie.insert(word, movie.getTitulo(), movie.getSinopsis());
    }
    trie.insert(text, movie.getTitulo(), movie.getSinopsis());
}

void Menu::cargarPeliculas() {
    ifstream file("../limpio2.csv");
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de la base de datos.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string imdb_id, title, plot_synopsis, tags, split, synopsis_source;

        getline(ss, imdb_id, '|');
        getline(ss, title, '|');
        getline(ss, plot_synopsis, '|');
        getline(ss, tags, '|');
        getline(ss, split, '|');
        getline(ss, synopsis_source, '|');

        Pelicula movie(imdb_id, title, plot_synopsis, tags, split, synopsis_source);
        insertWords(trie, title, movie);
    }

    file.close();
    cout << "Base de datos cargada con éxito.\n";
}

// Métodos de búsqueda
void Menu::buscarPorPrefijo() {
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
}

void Menu::buscarPorPalabraClave() {
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
}

void Menu::buscarPorFraseExacta() {
    string phrase;
    cout << "Ingrese una frase exacta para buscar películas por título: ";
    getline(cin, phrase);

    vector<string> results = trie.searchByTitle(phrase);
    if (!results.empty()) {
        cout << "Películas encontradas:\n";
        for (const string& title : results) {
            cout << "- Título: " << title << "\n";
        }
    } else {
        cout << "No se encontraron películas para la frase exacta ingresada en los títulos.\n";
    }
}

void Menu::buscarEnSinopsis() {
    string phrase;
    cout << "Ingrese una frase para buscar en las sinopsis: ";
    getline(cin, phrase);

    vector<pair<string, string>> results = trie.searchByPhrase(phrase);
    if (!results.empty()) {
        cout << "Películas encontradas en las sinopsis:\n";
        for (const auto& [title, synopsis] : results) {
            cout << "- Título: " << title << endl;
        }
    } else {
        cout << "No se encontraron coincidencias en las sinopsis para la frase ingresada.\n";
    }
}

// Método para iniciar el menú
void Menu::iniciar() {
    cargarPeliculas();

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

        switch (choice) {
            case 1:
                buscarPorPrefijo();
                break;
            case 2:
                buscarPorPalabraClave();
                break;
            case 3:
                buscarPorFraseExacta();
                break;
            case 4:
                buscarEnSinopsis();
                break;
            case 5:
                cout << "¡Gracias por usar el sistema de búsqueda de películas!\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (choice != 5);
}
