#include <iostream>
#include "Tablero.h"
#include "Tablerosinpoda.h"
using namespace std;

void input_tablero_vs_ia(int n, int m, Tablero* tabl){
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

void input_tablero_vs_jugador(int n, int m, Tablero* tabl, int jugador){
    if (tabl -> tablero[n][m] == -1){
        if (tabl -> winner == -1){
            tabl -> tablero[n][m] = jugador-1;
            tabl -> winner = tabl -> ganar_partida();
        }
    } else {
        cout << "Posicion ocupada" << endl;
    }
    
}

void partida_vs_jugador(){
    Tablero* tablero = new Tablero();
    int jugador = 1;
    cout << "Estos valores tienen los siguientes significados:" << endl;
    cout << " 0 = primera fila o columna del tablero" << endl;
    cout << " 1 = segunda fila o columna del tablero" << endl;
    cout << " 2 = tercera fila o columna del tablero" << endl;
    cout << "Espacio en blanco entre fichas significa una casilla vacia" << endl;
    cout << "La ficha del jugador 1 es X, del jugador 2 es O" << endl;
    while (tablero -> winner == -1){
        tablero -> mostrar_tablero();
        string x, y;
        cout << "Turno del jugador " << jugador << endl;
        cout << "Ingrese una fila entre [0,1,2]" << endl;
        cin >> x;
        if (x == "2" || x == "1" || x == "0"){
            cout << "Ingrese una columna entre [0,1,2]" << endl;
            cin >> y;
            if (y == "2" || y == "1" || y == "0"){
                input_tablero_vs_jugador(stoi(x),stoi(y),tablero, jugador);
                jugador = jugador == 1 ? 2 : 1;
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
    tablero -> mostrar_tablero();
    if (tablero -> winner == 0){
        cout << "Gano el jugador 1" << endl;
    } else if (tablero -> winner == 1){
        cout << "Gano el jugador 2" << endl;
    } else {
        cout << "Empate" << endl;
    }
    delete tablero;
}

void partida_vs_ia(){
    Tablero* tablero = new Tablero();
    cout << "Estos valores tienen los siguientes significados:" << endl;
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
                input_tablero_vs_ia(stoi(x),stoi(y),tablero);
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
    tablero -> mostrar_tablero();
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
    string opcion = "-1";
    while (opcion != "3"){
        cout << "Menu" << endl;
        cout << "1. Jugar contra la IA" << endl;
        cout << "2. Jugar contra otro jugador" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion" << endl;
        cin >> opcion;
        if (opcion == "1"){
            partida_vs_ia();
        } else if (opcion == "2"){
            partida_vs_jugador();
        } else if (opcion == "3"){
            cout << "Saliendo..." << endl;
        } else {
            cout << "Opcion invalida" << endl;
        }
    }
    return 0;
}
