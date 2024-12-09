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

---Ejemplos practicos---

Este algoritmo se utiliza bajo determinadas situaciones y factores, por ejemplo se aplica en escenarios donde dos jugadores compiten y las ganancias de un jugador son las pérdidas del otro, como en el caso del ajedrez, damas y el gato, además la información debe ser perfecta, con esto nos referimos a que ambos jugadores tienen acceso completo al estado del juego y a los posibles movimientos, es decir no existe la aleatoriedad, también cada jugada tiene solo un resultado posible y se puede asignar un valor numérico a cada estado del juego que refleje ganar, empatar o perder, finalmente el juego debe ser por turnos, los jugadores se alternan para tomar decisiones en un formato secuencial, lo cual permite el funcionamiento del algoritmo.

Como ejemplos practicos tenemos:

1.- El juego del gato
    
    Analisis de caso simple:
    
  Escenario

 X | O | X
  ---------
 O | X |  
  ---------
   |   | O

   Para que x gane.

  Opciones de "X":
  
   Mover a la posición (3,1) (gana el juego).
   Mover a cualquier otra posición (no garantiza ganar en este turno).

  Evaluación del Árbol:

   Si "X" elige (3,1), asegura la victoria (valor de utilidad = +1).
   Si "X" elige cualquier otra posición, "O" podría ganar en el siguiente turno.

  Decisión Óptima:

   El algoritmo Minimax evalúa todas las posibilidades y selecciona (3,1) para maximizar las posibilidades de ganar.

2.- Juego de Cartas Simplificado

    Escenario
     Dos jugadores compiten para tener la suma más cercana a 21, utilizando números entre 1 y 10. El jugador 1 comienza con 15 y el jugador 2 tiene 18.

    Análisis:
      Opciones del Jugador 1:

      Tomar una carta adicional.
      No tomar una carta (mantener 15).

    Opciones del Jugador 2:

      Si el Jugador 1 toma una carta y excede 21, el Jugador 2 gana automáticamente.
      Si el Jugador 1 no toma una carta, el Jugador 2 puede detenerse en 18.
    
    Decisión Óptima:

      El algoritmo evalúa las posibilidades y concluye que el Jugador 1 debe tomar una carta solo si no excede 21. Esto maximiza las probabilidades de acercarse a 21.

---Explicación de la búsqueda en el árbol de juego y su evaluación---

### Optimización del algoritmo con poda Alfa-Beta:

El algoritmo Minimax recorre el árbol de decisiones para encontrar la mejor jugada para el jugador actual, pero en árboles muy grandes (debido a la gran cantidad de movimientos posibles), el tiempo de ejecución puede ser muy largo. Por eso, utilizamos el algoritmo con poda Alfa-Beta para "podar" las ramas que no necesitamos explorar, ya que se ha determinado que no afectarán el resultado final.

### Algoritmo sin poda v/s Algoritmo con poda Alfa-Beta:

Considerando una partida donde el jugador hace la primera jugada y luego la computadora, se realizan los mismos movimientos 3 veces y se promedia el tiempo de ejecución.

| Movimiento | Sin poda | Con poda | Diferencia | Porcentaje de reduccion |
| ---------- | -------- | -------- | ---------- | ----------------------- |
| 1°         | ~4000ms  | ~220ms   | 3780ms     | 94.5%                   |
| 2°         | ~105ms   | ~33ms    | 72ms       | 68.6%                   |
| 3°         | ~8ms     | ~3ms     | 5ms        | 62.5%                   |
| 4°         | ~1ms     | ~1ms     | 0ms        | 0%                      |
