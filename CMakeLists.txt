cmake_minimum_required(VERSION 3.27)
project(repoPROGRA)

set(CMAKE_CXX_STANDARD 14)

add_executable(repoPROGRA
        main.cpp
        Arbol.h
        Pelicula.h
        trie.cpp
        trie.h
)
