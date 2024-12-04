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
    cout << "Base de datos cargada con exito.\n";
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
        cout << "\n--- Menu ---\n";
        cout << "1. Buscar por frase exacta\n";
        cout << "2. Buscar en sinopsis\n";
        cout << "3. Salir\n";
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                buscarPorFraseExacta();
                break;
            case 2:
                buscarEnSinopsis();
                break;
            case 3:
                cout << "¡Gracias por usar el sistema de busqueda de peliculas!\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (choice != 3);
}
