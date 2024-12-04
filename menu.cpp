
#include <fstream>
#include <sstream>
#include <iostream>
#include "Historial.h"

#include "Menu.h"

#include "SearchStrategy.h"


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
    cout << "Ingrese una frase exacta para buscar peliculas por titulo: ";
    getline(cin, phrase);
    ExactMatchStrategy *exactMatchStrategy= new ExactMatchStrategy;


    vector <pair<string, string>> results = exactMatchStrategy->search(this->trie,phrase);
    if (!results.empty()) {
        cout << "Peliculas encontradas en las sinopsis:\n";
        for (const auto &[title, synopsis]: results) {
            cout << "- Título: " << title << endl;
        }
    } else {
        cout << "No se encontraron peliculas para la frase exacta ingresada en los titulos.\n";
    }

    string titleBuscado;
    cout << "Ingrese el titulo de la pelicula que desea ver info: ";
    getline(cin, titleBuscado);
    for (const auto &[title, synopsis]: results) {
        if (title.find(titleBuscado) != string::npos) {
            cout << "- Titulo: " << title << endl;
            cout << "- Sinopsis: " << synopsis << endl;
            break;
        }
    }
    string decision;
    cout << "- Ver mas tarde              - Like" << endl;
    cout << "- Retroceder" << endl;
    cout << "Ingresa la opcion: ";
    getline(cin, decision);
    if (decision == "Retroceder")
        iniciar();
}

void Menu::buscarEnSinopsis() {
    string phrase;
    cout << "Ingrese una frase para buscar en las sinopsis: ";
    getline(cin, phrase);
    SynopsisSearchStrategy *synopsis_search_strategy = new SynopsisSearchStrategy;

    vector<pair<string, string>> results = synopsis_search_strategy->search(this->trie,phrase);
    if (!results.empty()) {
        cout << "Peliculas encontradas en las sinopsis:\n";
        for (const auto& [title, synopsis] : results) {
            cout << "- Titulo: " << title << endl;
        }

        string titleBuscado;
        cout << "Ingrese el titulo de la pelicula que desea ver info: ";
        getline(cin, titleBuscado);
        for (const auto& [title, synopsis] : results) {
            if (title.find(titleBuscado) != string::npos) {
                cout << "- Titulo: " << title << endl;
                cout << "- Sinopsis: " << synopsis << endl;

                string decision;
                cout << "- Ver mas tarde              - Like" << endl;
                cout << "- Retroceder" << endl;
                cout << "Ingresa la opcion: ";
                getline(cin, decision);

                if (decision == "Ver mas tarde") {
                    Historial::getInstance().agregarBusqueda(title);
                    cout << "Pelicula agregada a Ver mas tarde.\n";
                } else if (decision == "Like") {
                    Historial::getInstance().agregarLike(title);
                    cout << "¡Pelicula agregada a favoritos!\n";
                } else if (decision == "Retroceder") {
                    iniciar();
                }
                break;
            }
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
        cout << "3. Ver agregadas a Ver mas tarde\n";
        cout << "4. Ver likes\n";
        cout << "5. Salir\n";
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
            case 3: {
                const auto& historial = Historial::getInstance().obtenerHistorial();
                cout << "Peliculas agregadas a Ver mas tarde:\n";
                for (const auto& busqueda : historial) {
                    cout << "- " << busqueda << endl;
                }
                break;
            }
            case 4: {
                const auto& likes = Historial::getInstance().obtenerLikes();
                cout << "Peliculas marcadas como favoritas:\n";
                for (const auto& pelicula : likes) {
                    cout << "- " << pelicula << endl;
                }
                break;
            }
            case 5:
                cout << "¡Gracias por usar el sistema de busqueda de peliculas!\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (choice != 5);
}
