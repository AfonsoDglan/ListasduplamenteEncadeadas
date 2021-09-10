#include<stdio.h>
#include "LDouble.h"
/**
 * Template criado por Rafael Lima <rafael.lima@uft.edu.br> em 10/04/2021 as 19:16, atualizado em 03/07/2021 as 20:57.
 * Disciplina: Estrutura de Dados.
 * Problema: representacao de inteiros gigantes usando lista duplamente encadeada.
 * Para compilar: gcc main.c LDouble.c
 * Para testar (win): a.exe <input.txt
 * Para testar (unix/linux): ./a.out <input.txt
/*
Nome: Afonso Dglan Cirqueira Rodrigues
Matricula: 2020214947
*/

int main(){
  int ncases;
  char buffer[4097];
  scanf("%d\n", &ncases);
  while(ncases-- > 0){
    fgets(buffer, 4096, stdin);
    TDList* num1 = TDList_generate(buffer);
    fgets(buffer, 4096, stdin);
    TDList* num2 = TDList_generate(buffer);
    TDList* sum = TDList_sum(num1, num2);
    TDList_print(sum);
    TDList_destroy(num1);
    TDList_destroy(num2);
    TDList_destroy(sum); 
  }
  return 0;
}

