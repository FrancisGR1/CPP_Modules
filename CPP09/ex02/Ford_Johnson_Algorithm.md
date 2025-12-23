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

































# Exemplo
30, 49, 60, 1, 31, 29, 42, 46, 13, 8, 5

Pares:
49 60 31 46 13
30  1 29 42  8 

Pend:
5

Fase de recursão:
-1.
60 46 
49 31 13

-2.
60
46

Nova main:
46 60

Reordenação da pend:
-1.
46 60 
31 49 13

-2.
49 46 31 60 13
30 42 29  1  8 

Inserção:
Original:
46 60 
31 49 13

-1.
31 46 60
   49 13
-2.
13 31 46 60
       49 
-3.
13 31 46 49 60

Nota: como o 13 não tem parceiro, procura a partir do início (binary search)


-4. Voltar ao nível original
Pares:
49 60 31 46 13
30  1 29 42  8 

Pend:
5


Substituição pela nova main:
13 31 46 49 60
8  29 42 30 1  5

ordem de inserção jacob: 3, 2, 5, 4, 6

1º elemento (8)  - 8 13 31 46 49 60
3º elemento (42) - 8 13 31 42 46 49 60
2º elemento (29) - 8 13 29 31 42 46 49 60
5º elemento (1)  - 1  8 13 29 31 42 46 49 60
4º elemento (30) - 1  8 13 29 30 31 42 46 49 60
6º elemento (5) -  1  5  8 13 29 30 31 42 46 49 60
FIM!

