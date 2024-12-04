cmake_minimum_required(VERSION 3.27)
project(proyecto2)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyecto2 main.cpp
        trie.cpp
        trie.h
        Pelicula.h
        menu.cpp
        Historial.cpp



        SearchStrategy.cpp
        SearchStrategy.h

        )
