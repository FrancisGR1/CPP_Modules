# Passos
 1. Dividir o conjunto em pares
 2. Por cada par, colocar o elemento maior no grupo de "vencedores"
 2. Compara cada par
    Identificar os elementos com os seguintes rótulos: maior, mais pequeno, sem pares (no caso de ser um conjunto ímpar)
 3. Ordenar os maiores elementos recursivamente
 4. Inserir o par correspondente ao menor elemento do conjunto ordenado
 5. Inserir o resto dos pares

# Recursos
Implementar o do medium
 - https://medium.com/@mohammad.ali.ibrahim.525/ford-johnson-algorithm-merge-insertion-4b024f0c3d42
 - https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
 - github.com/leske42/CPP09
 - https://github.com/alx-sch/CPP_Glossary?tab=readme-ov-file#ford-johnson-algorithm
 - Números de Lucas: https://www.youtube.com/watch?v=PeUbRXnbmms

# Paper: A Tournament Problem, Author(s): Lester R. Ford, Jr. and Selmer M. Johnson
## https://sci-hub.se/10.2307/2308750
### We shall now give a table of values of M(n), U(n), and L(n) for some selected values of n, there after making some empirical observations.
  n  | 1 | 2 | 3 | 4 | 5 | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13
M(n) | 0 | 1 | 3 | 5 | 8 | 11 | 14 | 17 | 21 | 25 | 29 | 33 | 37
U(n) | 0 | 1 | 3 | 5 | 7 | 10 | 13 | 16 | 19 | 22 | 26 | 30 | 34
L(n) | 0 | 1*| 3 | 5 | 7 | 10 | 13 | 16 | 19 | 22 | 26 | 29 | 33 

Com brute force:
11 elements -> 35 comparações
Com binary search:
11 elements -> 35 comparações
Com binary search + jacobsthall indexes:
11 elements -> 35 comparações
