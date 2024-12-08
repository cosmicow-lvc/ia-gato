#pragma once

class Tablero {
    public:
    int tablero[3][3];
    int winner = -1;
    int cont = 0;
    int ultimo_movimiento[2];
    Tablero();
    void mostrar_tablero();
    int ganar_partida();
    bool tablero_lleno();
    bool fin_partida();
    int mini(int alpha, int beta);
    int imax(int alpha, int beta);
    void poner_ficha_ia();
    ~Tablero();
};