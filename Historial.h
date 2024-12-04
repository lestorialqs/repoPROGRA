//
// Created by USER on 03/12/2024.
//

#ifndef PROYECTO2_HISTORIAL_H
#define PROYECTO2_HISTORIAL_H



#include <string>
#include <vector>
#include <unordered_set>

class Historial {
private:
    std::vector<std::string> historial; // Historial de búsquedas
    std::unordered_set<std::string> likes; // Conjunto para evitar duplicados en "likes"

    // Constructor privado
    Historial() = default;

public:
    // Evitar copias
    Historial(const Historial&) = delete;
    Historial& operator=(const Historial&) = delete;

    // Obtener la única instancia
    static Historial& getInstance() {
        static Historial instance;
        return instance;
    }

    // Métodos para gestionar el historial
    void agregarBusqueda(const std::string& busqueda);
    void agregarLike(const std::string& pelicula);
    const std::vector<std::string>& obtenerHistorial() const;
    const std::unordered_set<std::string>& obtenerLikes() const;
};




#endif //PROYECTO2_HISTORIAL_H
