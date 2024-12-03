#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dividirEnPalabras(const string &frase) {
    stringstream ss(frase);
    string palabra;
    vector<string> palabras;
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }
    return palabras;
}

string obtenerTitulo(const string &linea) {
    stringstream ss(linea);
    string id, titulo;
    getline(ss, id, '|');       // Leer el ID
    getline(ss, titulo, '|');   // Leer el título
    return titulo;
}

void buscarPeliculasPorPalabras(const vector<string> &palabrasClave, const string &archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    bool seEncontraron = false;

    while (getline(file, linea)) {
        string lineaMin = linea;
        transform(lineaMin.begin(), lineaMin.end(), lineaMin.begin(), ::tolower);

        bool coincidencia = false;
        for (const string &palabra : palabrasClave) {
            string palabraMin = palabra;
            transform(palabraMin.begin(), palabraMin.end(), palabraMin.begin(), ::tolower);
            if (lineaMin.find(palabraMin) != string::npos) {
                coincidencia = true;
                break;
            }
        }

        if (coincidencia) {
            string titulo = obtenerTitulo(linea);
            cout << "Titulo encontrado: " << titulo << endl;
            seEncontraron = true;
        }
    }

    if (!seEncontraron) {
        cout << "No se encontraron peliculas con las palabras clave proporcionadas." << endl;
    }

    file.close();
}

int main() {
    string archivo = "limpio2.csv";

    cout << "Ingrese palabras clave para buscar peliculas: ";
    string fraseClave;
    getline(cin, fraseClave);

    vector<string> palabrasClave = dividirEnPalabras(fraseClave);
    cout << "Buscando peliculas con las palabras: ";
    for (const string &palabra : palabrasClave) {
        cout << "\"" << palabra << "\" ";
    }
    cout << endl;

    buscarPeliculasPorPalabras(palabrasClave, archivo);

    return 0;
}
