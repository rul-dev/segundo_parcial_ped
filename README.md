# Analisis de complejidad:

Ejercicio 4.1

Responda:

1. ¿Cuál es la complejidad temporal Big-O?

R// O(n), ya que el bucle interno tiene 3 iteraciones, por lo que no depende de n. La complejidad total es lineal con respecto a n.
2. Si `n` se duplica, ¿cómo cambia aproximadamente el número de comparaciones?

R// Se duplica, ya que el bucle externo se ejecuta n veces y el interno 3 veces, el total es 3n.

Ejercicio 4.2

Responda:

1. ¿Cuál es la complejidad temporal Big-O?

R// O(n^2), ya que el bucle externo se ejecuta n veces y el bucle interno se ejecuta n/2 veces (j incrementa de 2 en 2).

2. Si `n` se duplica, ¿cómo cambia aproximadamente el número de comparaciones?

R// Se cuadruplica, ambas variables en los bucles dependen de n, y el bucle interno se ejecuta n/2 veces. El número total de comparaciones es proporcional a n^2. 