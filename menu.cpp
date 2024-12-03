//
// Created by Asus on 3/12/2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "Pelicula.h"

using namespace std;

class Menu{
    private:
    unordered_map<string, Pelicula*> peliculasTarde;
    unordered_map<string, Pelicula*> likes;

public:
    void mostrar();
    void buscador();
    void getMasTarde();
    void getLikes();
    void agregarLike(Pelicula * pelicula);
    void agregarMasTarde(Pelicula *pelicula);
    void eliminarPeliculasMasTarde(string id);
    void eliminarPeliculaslike(string id);

};




void Menu::mostrar() {
    int option;

    while (true) {
        cout << "\n=== Menú Principal ===\n";
        cout << "1. Buscar Películas\n";
        cout << "2. Peliculas en Ver mas Tarde\n";
        cout << "3. Películas con Like\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cin.ignore();  // Ignorar el salto de línea después de la opción

        switch (option) {
            case 1: buscador(); break;
            case 2: getMasTarde(); break;
            case 3: getLikes(); break;
            case 4: cout << "¡Hasta luego!\n"; return;
            default: cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}

void Menu::buscador() {
    cout << "Buscando películas...\n";
    // Aquí puedes insertar la lógica de búsqueda
    // Por ahora solo regresamos al menú principal
}

void Menu::getMasTarde() {
    cout << "Mostrando películas en 'Ver más tarde'...\n";


}

void Menu::getLikes() {
    cout << "Mostrando películas con 'Like'...\n";
    // Aquí puedes insertar la lógica para mostrar las películas con 'Like'
    // Por ahora solo regresamos al menú principal

}
void Menu::agregarMasTarde(Pelicula *pelicula) {

    peliculasTarde[pelicula->getId()] = pelicula;
}
void Menu::agregarLike(Pelicula *pelicula) {

    peliculasTarde[pelicula->getId()] = pelicula;
}

void Menu::eliminarPeliculasMasTarde(string id) {
    bool eliminado = false;

    if (peliculasTarde.erase(id) > 0) {
        eliminado = true;
        cout << "Película eliminada de peliculasTarde con ID: " << id << endl;
    }

    if (!eliminado) {
        cout << "No se encontró ninguna película con ID: " << id << endl;
    }
}
void Menu::eliminarPeliculaslike(string id) {
    bool eliminado = false;

    if (likes.erase(id) > 0) {
        eliminado = true;
        cout << "Película eliminada de peliculasTarde con ID: " << id << endl;
    }

    if (!eliminado) {
        cout << "No se encontró ninguna película con ID: " << id << endl;
    }
}