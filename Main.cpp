#include <iostream>
#include "Tablero.h"
#include "Tablerosinpoda.h"
using namespace std;

void input_tablero(int n, int m, Tablero* tabl){
    if (tabl -> tablero[n][m] == -1){
        if (tabl -> winner == -1){
            tabl -> tablero[n][m] = 0;
            tabl -> winner = tabl -> ganar_partida();
            tabl -> poner_ficha_ia();
            tabl -> winner = tabl -> ganar_partida();
        }
    } else {
        cout << "Posicion ocupada" << endl;
    }
    
}

void partida_normal(){
    Tablero* tablero = new Tablero();
    cout << "Bienvenido al juego de Gato!" << endl;
    cout << "estos valores tienen los siguientes significados:" << endl;
    cout << " 0 = primera fila o columna del tablero" << endl;
    cout << " 1 = segunda fila o columna del tablero" << endl;
    cout << " 2 = tercera fila o columna del tablero" << endl;
    cout << "Espacio en blanco entre fichas significa una casilla vacia" << endl;
    cout << "Su ficha es X, usted empieza" << endl;
    while (tablero -> winner == -1){
        tablero -> mostrar_tablero();
        string x, y;
        cout << "Ingrese una fila entre [0,1,2]" << endl;
        cin >> x;
        if (x == "2" || x == "0" || x == "1"){
            cout << "Ingrese una columna entre [0,1,2]" << endl;
            cin >> y;
            if (y == "2" || y == "0" || y == "1"){
                input_tablero(stoi(x),stoi(y),tablero);
            } else {
                cout << "Input invalido" << endl;
                continue;
            }
        } else {
            cout << "Input invalido" << endl;
            continue;   
        }
        if (tablero -> tablero_lleno()){
            break;
        }
    }
    if (tablero -> winner == 0){
        cout << "Gano el jugador" << endl;
    } else if (tablero -> winner == 1){
        cout << "Gano la IA" << endl;
    } else {
        cout << "Empate" << endl;
    }
    delete tablero;
}

int main(){
    partida_normal();
    
    return 0;
}
