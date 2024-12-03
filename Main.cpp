#include <iostream>
#include "Tablero.h"
using namespace std;

void input_tablero(int n, int m, Tablero* tabl){
    if (n >= 0 && n < 3 && m < 3 && m >= 0 && tabl -> tablero[n][m] == -1){
        if (tabl -> winner == -1){
            tabl -> tablero[n][m] = 0;
            tabl -> winner = tabl -> ganar_partida();
            tabl -> poner_ficha_ia();
        }
    } else {
        cout << "input invalidos" << endl;
    }
}

int main(){
    Tablero* a = new Tablero();
    while (a -> winner == -1){
        a -> mostrar_tablero();
        int x, y;
        cin >> x;
        cin >> y;
        input_tablero(x,y,a);
    }
    if (a -> winner == 0){
        cout << "Gano el jugador" << endl;
    } else {
        cout << "Gano la IA" << endl;
    }
    a -> mostrar_tablero();

    
    return 0;
}
