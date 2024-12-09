# Taller 2 ia-gato
Integrantes:

Maximo Jofre Letelier ; 21675371-2 ; maximo.jofre@alumnos.ucn.cl ; C-2

Antonio Tabilo Cortes ; 21668377-3 ; antonio.tabilo@alumnos.ucn.cl ; C-2

Víctor Jopia Santander ; 21.719.697.3 ; victor.jopia01@alumnos.ucn.cl ; C-2

* Para compilar:
  ```sh
  g++ Main.cpp Tablero.cpp -o Main.exe
  ```
* Para ejecutar:
  ```sh
  .\Main.exe
  ```

### Diagrama de arbol de los 3 primeros movimientos:

![diagramarbol](https://github.com/user-attachments/assets/447a14da-2ac4-43bf-a973-ae2db2234ae3)


### Introducción al Algoritmo Minimax:

El algoritmo se basa en estimar que jugada es la mejor para la maquina por medio de fuerza bruta, simulando todas las posibles jugadas y luego escoger la que le convenga más.

Ejemplos practicos

Explicación de la búsqueda en el árbol de juego y su evaluación

### Optimización del algoritmo con poda Alfa-Beta:

Explicar la tecnica para reducir el numero de nodos explorados

### Algoritmo sin poda v/s Algoritmo con poda Alfa-Beta:

Considerando una partida donde el jugador hace la primera jugada y luego la computadora, se realizan los mismos movimientos 3 veces y se promedia el tiempo de ejecución.

| Movimiento | Sin poda | Con poda | Diferencia | Porcentaje de reduccion |
| ---------- | -------- | -------- | ---------- | ----------------------- |
| 1°         | ~4000ms  | ~220ms   | 3780ms     | 94.5%                   |
| 2°         | ~105ms   | ~33ms    | 72ms       | 68.6%                   |
| 3°         | ~8ms     | ~3ms     | 5ms        | 62.5%                   |
| 4°         | ~1ms     | ~1ms     | 0ms        | 0%                      |
