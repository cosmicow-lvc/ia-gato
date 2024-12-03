#include <iostream>
#include "Tablero.h"
using namespace std;

void input_tablero(int n, int m, Tablero* tabl){
    if (n >= 0 && n < 3 && m < 3 && m >= 0 && tabl -> tablero[n][m] == -1){
        if (tabl -> winner == -1){
            tabl -> tablero[n][m] = 0;
            tabl -> winner = tabl -> ganar_partida();
            tabl -> poner_ficha_ia();
            tabl -> winner = tabl -> ganar_partida();
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
        if (a -> tablero_lleno()){
            break;
        }
    }
    if (a -> winner == 0){
        cout << "Gano el jugador" << endl;
    } else if (a -> winner == 1){
        cout << "Gano la IA" << endl;
    } else {
        cout << "Empate" << endl;
    }
    
    return 0;
}
