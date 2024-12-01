//
// Created by hanksvi on 30/11/2024.
//

#ifndef REPOPROGRA_LIMPADOR_DE_CSV_H
#define REPOPROGRA_LIMPADOR_DE_CSV_H
#include <iostream>
#include <fstream>
using namespace std;



int main(){

    ifstream archivo("mpst_full_data.csv");

    string linea;

    while(getline(archivo, linea)){
        string texto = "";
        int contador = 0;
        for(char c: linea){;
            if(c == '"'){
                contador += 1;
            }
            else {
                if (c == ',' and contador < 1)
                    texto += " |||||||||| ";
                else
                    texto += c;
            }
            if(contador == 2)
                contador = 0;
        }
        texto += "\n";
        texto += "\n";
        ofstream txt("limpio.txt", ios::app);
        txt << texto;

    }

}
#endif //REPOPROGRA_LIMPADOR_DE_CSV_H
