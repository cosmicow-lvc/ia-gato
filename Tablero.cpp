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

int Tablero::mini(int alpha, int beta){
    if (fin_partida()){
        if (ganar_partida() != -1){
            return 1;
        } else {
            return 0;
        }
    }
    int minEval = INT_MAX;
    int eval;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == -1){
                tablero[i][j] = 0;
                eval = imax(alpha, beta);

                if (eval < minEval){
                    minEval = eval;
                }

                if (beta > eval){
                    beta = eval;
                }    
                
                tablero[i][j] = -1;
            }
            if (beta <= alpha){
                break;
            }
        }
        if (beta <= alpha){
            break;
        }
    }   
    return minEval;
}

int Tablero::imax(int alpha, int beta){
    if (fin_partida()){
        if (ganar_partida() != -1){
            return -1;
        } else {
            return 0;
        }
    }
    int maxEval = INT_MIN;
    int eval;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] == -1){
                tablero[i][j] = 1;
                eval = mini(alpha, beta);

                if (eval > maxEval){
                    maxEval = eval;
                }

                if (alpha < eval){
                    alpha = eval;
                }
                tablero[i][j] = -1;
            }
            if (beta <= alpha){
                break;
            }
        }
        if (beta <= alpha){
            break;
        }
    }   
    return maxEval;
}


void Tablero::poner_ficha_ia(){
    if (!fin_partida()){
        int f = 0;
        int c = 0;
        int maxEval = INT_MIN;
        int eval;
        int alpha = INT_MIN;
        int beta = INT_MAX;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (tablero[i][j] == -1){
                    tablero[i][j] = 1;
                    eval = mini(alpha, beta);

                    if (eval > maxEval){
                        maxEval = eval;
                        f = i;
                        c = j;
                    }

                    if (alpha < eval){
                        alpha = eval;
                    }
                    tablero[i][j] = -1;
                }
                if (beta <= alpha){
                    break;
                }
            }
            if (beta <= alpha){
                break;
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