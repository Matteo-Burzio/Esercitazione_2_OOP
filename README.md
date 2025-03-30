# Esercitazione sull’overload degli operatori - March 17, 2025

Si definisca una classe template che modella i numeri complessi. 
La classe template prende come parametro il tipo T con il quale si rappresentano a e b sulla macchina. 
La classe deve funzionare correttamente per T = float e T = double.
Tale classe template deve:
1. Avere un costruttore di default
2. Avere un costruttore user-defined per l’inizializzazione di parte reale ed immaginaria
3.  Avere metodi che restituiscano il coniugato, la parte reale e la parte immaginaria
4. Fornire un overload dell’operatore << per stampare il numero complesso. Se per esempio a = 1 e b = 2, dev’essere stampato 1+2i, mentre se b = −2 dev’essere stampato 1-2i.
5. Fornire un overload degli operatori += e +.
6. Fornire un overload degli operatori *= e *.
7. Opzionale: in modo simile a quanto fatto in classe nel caso di rational, utilizzare i concept per vincolare T ad essere un tipo floating point.
8. Similmente a quanto fatto su rational, gli operatori + e * implementati devono soddisfare correttamente i requisiti di commutatività.