//
// Created by USER on 03/12/2024.
//

#include "Historial.h"

void Historial::agregarBusqueda(const std::string& busqueda) {
    historial.push_back(busqueda);
}

void Historial::agregarLike(const std::string& pelicula) {
    likes.insert(pelicula); // Solo se guarda si no existe
}

const std::vector<std::string>& Historial::obtenerHistorial() const {
    return historial;
}

const std::unordered_set<std::string>& Historial::obtenerLikes() const {
    return likes;
}

