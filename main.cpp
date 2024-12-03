#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string obtenerTitulo(const string &linea) {
    stringstream ss(linea);
    string id, titulo;
    getline(ss, id, '|');
    getline(ss, titulo, '|');
    return titulo;
}

void buscarPeliculasPorFrase(const string &fraseClave, const string &archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    bool seEncontraron = false;

    while (getline(file, linea)) {
        string lineaMin = linea;
        string fraseMin = fraseClave;
        transform(lineaMin.begin(), lineaMin.end(), lineaMin.begin(), ::tolower);
        transform(fraseMin.begin(), fraseMin.end(), fraseMin.begin(), ::tolower);

        if (lineaMin.find(fraseMin) != string::npos) {
            string titulo = obtenerTitulo(linea);
            cout << "Titulo encontrado: " << titulo << endl;
            seEncontraron = true;
        }
    }

    if (!seEncontraron) {
        cout << "No se encontraron peliculas con la frase proporcionada." << endl;
    }

    file.close();
}

// Función principal
int main() {
    string archivo = "limpio2.csv";

    cout << "Ingrese una frase exacta para buscar peliculas: ";
    string fraseClave;
    getline(cin, fraseClave);

    cout << "Buscando peliculas con la frase: \"" << fraseClave << "\"" << endl;

    buscarPeliculasPorFrase(fraseClave, archivo);

    return 0;
}

