#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "Trie.h"
#include "Pelicula.h"

class Menu {
private:
  Trie trie;

  // Métodos privados para encapsular las funcionalidades
  void cargarPeliculas();
  void buscarPorFraseExacta();
  void buscarEnSinopsis();

public:
  // Constructor por defecto
  Menu() = default;

  // Método principal para iniciar el menú
  void iniciar();
};

#endif // MENU_H
