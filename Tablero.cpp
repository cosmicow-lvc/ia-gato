#include <iostream>
#include "Tablero.h"

Tablero::Tablero(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->tablero[i][j] = -1;
        }
    }
    this->winner = -1; 
}

void Tablero::mostrar_tablero(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == 0) {
                std::cout << "x";
            } else if (tablero[i][j] == 1) {
                std::cout << "o";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }        
}

int Tablero::ganar_partida(){
    if (tablero[0][0] != -1 && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]){
        return tablero[0][0];
    }
    if (tablero[0][2] != -1 && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]){
        return tablero[0][2];
    }
    for (int n = 0; n < 3; n++){
        if (tablero[n][0] != -1 && tablero[n][0] == tablero[n][1] && tablero[n][0] == tablero[n][2]){
            return tablero[n][0];
        }
        if (tablero[0][n] != -1 && tablero[0][n] == tablero[1][n] && tablero[0][n] == tablero[2][n]){
            return tablero[0][n];
        }
    }
    return -1;
}

bool Tablero::tablero_lleno() {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == -1){
                return false;
            }
        }
    }
    return true;
}

bool Tablero::fin_partida(){
    return tablero_lleno() or ganar_partida() != -1;
}

int Tablero::mini(){
    if (fin_partida()){
        if (ganar_partida() != -1){
            return 1;
        } else {
            return 0;
        }
    }
    int v = INT_MAX;
    int aux;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == -1){
                tablero[i][j] = 0;
                aux = imax();
                if (aux < v){
                    v = aux;
                }
                tablero[i][j] = -1;
            }
        }
    }   
    return v;
}

int Tablero::imax(){
    if (fin_partida()){
        if (ganar_partida() != -1){
            return -1;
        } else {
            return 0;
        }
    }
    int v = INT_MIN;
    int aux;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == -1){
                tablero[i][j] = 1;
                aux = mini();
                if (aux > v){
                    v = aux;
                }
                tablero[i][j] = -1;
            }
        }
    }   
    return v;
}


void Tablero::poner_ficha_ia(){
    if (!fin_partida()){
        int f = 0;
        int c = 0;
        int v = INT_MIN;
        int aux;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[i][j] == -1){
                    tablero[i][j] = 1;
                    aux = mini();
                    if (aux > v){
                        v = aux;
                        f = i;
                        c = j;
                    }
                    tablero[i][j] = -1;
                }
            }
        }
        tablero[f][c] = 1;
        ultimo_movimiento[0] = f;
        ultimo_movimiento[1] = c;
    }
}

Tablero::~Tablero(){
    std::cout << "Eliminando tablero" << std::endl;
}