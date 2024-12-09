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

### Explicación de la búsqueda en el árbol de juego y su evaluación

El árbol de juego es una estructura jerárquica que representa todos los posibles estados de un juego desde una posición inicial hasta todas las configuraciones terminales, considerando los movimientos disponibles para los jugadores. El algoritmo Minimax recorre este árbol para determinar la mejor estrategia de juego.

Construcción del Árbol de Juego
    
    Nodo raíz: Representa el estado actual del juego.
    Niveles alternados: Cada nivel corresponde a las posibles decisiones de un jugador:
    Maximización (Max): Representa al jugador que intenta maximizar su ganancia.
    Minimización (Min): Representa al oponente que intenta minimizar la ganancia del otro jugador.

    Hojas: Los nodos terminales del árbol representan los resultados finales del juego (victoria, derrota, empate) con valores numéricos asociados, como:
      
      Victoria = +1
      Derrota = -1
      Empate = 0

Proceso de Búsqueda
  
  El algoritmo evalúa cada nodo del árbol siguiendo un enfoque recursivo:

      Comienza desde la raíz y recorre el árbol en profundidad.

  En cada nivel del árbol:

      Si es el turno de Max, selecciona el valor máximo de los hijos.
      Si es el turno de Min, selecciona el valor mínimo de los hijos.
      En los nodos terminales, el valor se calcula directamente con base en la puntuación asignada al estado del juego.

Evaluación de los Estados del Juego

  Los nodos hoja se evalúan directamente según las reglas del juego.
  Para los nodos intermedios, el algoritmo asigna un valor basándose en las mejores decisiones disponibles para los jugadores. Este valor es propagado hacia arriba en el árbol para influir en las decisiones de los niveles superiores.

  Por ejemplo:

    Si un jugador tiene tres posibles jugadas con resultados -1, 0, +1, el jugador Max elegirá la jugada con el resultado +1, mientras que el jugador Min optará por la jugada con el resultado -1.

### Elección de casilla a colocar   

    En el siguiente fragmento de codigo: "if (eval > maxEval) { maxEval = eval; f = i; c = j; }" se compara los puntajes de cada casilla y se queda con la jugada que tenga el puntaje máximo. Cuando encuentre una jugada con un puntaje mayor que el valor actual de maxEval, actualizará este puntaje y guardará las coordenadas de la casilla correspondiente. Al finalizar el análisis de todas las casillas, la máquina colocará su ficha en la casilla con las coordenadas guardadas, es decir, en la que dio el puntaje más alto. Si hay más de una casilla con el mismo puntaje máximo, elegirá la primera que obtenga ese puntaje

### Optimización del algoritmo con poda Alfa-Beta:

El algoritmo Minimax recorre el árbol de decisiones para encontrar la mejor jugada para el jugador actual, pero en árboles muy grandes (debido a la gran cantidad de movimientos posibles), el tiempo de ejecución puede ser muy largo. Por eso, utilizamos el algoritmo con poda Alfa-Beta para "podar" las ramas que no necesitamos explorar, ya que se ha determinado que no afectarán el resultado final.

La poda alfa-beta agrega dos variables, alfa y beta, para descartar ramas del árbol que no influirán en la decisión final:

    Alfa: El valor máximo garantizado para el jugador MAX hasta el momento.
    Beta: El valor mínimo garantizado para el jugador MIN hasta el momento.

Principio de la Poda

  La poda ocurre bajo las siguientes condiciones:

    Mientras se explora un nodo, si el valor actual ya es peor que una decisión previamente encontrada (en términos de alfa o beta), no se evalúan las ramas restantes del nodo porque no cambiarán el resultado.

  Esto se traduce en:

    Corte alfa: Si un nodo MIN encuentra un valor menor o igual a alfa (ya es peor para MAX), no se evalúan más hijos.
    Corte beta: Si un nodo MAX encuentra un valor mayor o igual a beta (ya es peor para MIN), no se evalúan más hijos.

Funcionamiento del Algoritmo

  El algoritmo recorre el árbol de decisión de forma recursiva, aplicando la lógica de minimax con los límites dados por alfa y beta. A continuación, se describe el flujo:

    Inicialmente, alfa = −∞ y beta = +∞

    A medida que se evalúan nodos:

      Para un nodo MAX:
        
        Se actualiza alfa: 
          𝛼=max(𝛼,valor del nodo)
          Si alfa ≥ beta, se interrumpe la evaluación de los hijos (corte beta).

        Para un nodo MIN:
          
          Se actualiza beta: 
            β=min(β,valor del nodo).
            Si beta ≤ alfa, se interrumpe la evaluación de los hijos (corte alfa).

La poda reduce significativamente la cantidad de nodos explorados al detener la evaluación de ramas inútiles.

### Algoritmo sin poda v/s Algoritmo con poda Alfa-Beta:

Considerando una partida donde el jugador hace la primera jugada y luego la computadora, se realizan los mismos movimientos 3 veces y se promedia el tiempo de ejecución.

| Movimiento | Sin poda | Con poda | Diferencia | Porcentaje de reduccion |
| ---------- | -------- | -------- | ---------- | ----------------------- |
| 1°         | ~4000ms  | ~220ms   | 3780ms     | 94.5%                   |
| 2°         | ~105ms   | ~33ms    | 72ms       | 68.6%                   |
| 3°         | ~8ms     | ~3ms     | 5ms        | 62.5%                   |
| 4°         | ~1ms     | ~1ms     | 0ms        | 0%                      |

### Análisis de complejidad temporal de Minimax, antes y despues de aplicar la poda
