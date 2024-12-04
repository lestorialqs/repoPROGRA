//
// Created by Asus on 3/12/2024.
//

#ifndef MENU_H
#define MENU_H


class Menu {
private:
  vector<Pelicula> movies;  // Lista de todas las películas
  vector<Pelicula> laterList;  // Películas marcadas como "Ver más tarde"
  vector<Pelicula> likedMovies;  // Películas marcadas como "Like"

public:
  void showMainMenu();  // Mostrar el menú principal
  void showSearchMenu();  // Menú para buscar películas
  void showMovieDetails(int movieIndex);  // Mostrar detalles de una película
  void showLaterList();  // Mostrar películas en "Ver más tarde"
  void showLikedMovies();  // Mostrar películas con "Like"
  void showSearchResults(const vector<Pelicula>& searchResults);  // Mostrar resultados de búsqueda
  void addToLaterList(int movieIndex);  // Agregar a "Ver más tarde"
  void addToLikedMovies(int movieIndex);  // Agregar a "Like"
  void showSimilarMovies(int movieIndex);  // Mostrar películas similares
};

#endif //MENU_H
