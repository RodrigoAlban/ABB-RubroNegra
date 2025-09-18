#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvoreRubroNegra();
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
    }

    return arvore;
}


int main(){

   int ex1[]   = {5, 10, 3, 2};          // caso 1
   int ex1_1[] = {5, 3, 2};              // caso 2.1
   int ex1_2[] = {5, 10, 12};            // caso 2.2
   int ex1_3[] = {5, 3, 4};              // caso 2.3
   int ex2[]   = {5, 10, 3, 2, 12, 11};  // caso 1 e caso 2.3
   int ex3[]   = {5, 10, 3, 2, 7, 8};    // caso 2.2
   int ex4[]   = {5, 10, 3, 2, 14, 12};  // caso 2.4
   int ex5[]   = {8, 3, 21, 16, 27, 9, 18, 29, 10}; // vários casos juntos


    printf("Construindo Arvore 1\n");
    pDArvore a1 = constroiArvore(ex1, 4);
    printf("Construindo Arvore 2\n");
    pDArvore a2 = constroiArvore(ex1, 4);
    printf("Construindo Arvore 3\n");
    pDArvore a3 = constroiArvore(ex1_1, 3);

    int eq12 = iguais(a1, a2, comparaInt); // equivalente 1 e 2
    int eq13 = iguais(a1, a3, comparaInt); // equivalente 1 e 3

    printf("\na1 == a2? %s\n", eq12 ? "SIM" : "NAO");
    printf("a1 == a3? %s\n", eq13 ? "SIM" : "NAO");

   //constroiArvore(ex1, 4);
   //constroiArvore(ex1_1, 3);
   //constroiArvore(ex1_2, 3);
   //constroiArvore(ex1_3, 3);
   //constroiArvore(ex2, 6);
   //constroiArvore(ex3, 6);
   //constroiArvore(ex4, 6);
   pDArvore arvoreExemplo = constroiArvore(ex5, 9);

   if (estritamenteBinaria(arvoreExemplo) == 1)
    printf("\nA árvore é estritamente binária");
    else
    printf("\nA árvore não é estritamente binária");
 }


