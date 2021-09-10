#include "LDouble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct no{
  int info;
  struct no *prox, *ant;
};//estrutura do meu nó

struct no* TNo_createnfill(int info){
  struct no* novo = (struct no*) malloc(sizeof(struct no));
  if(novo){
    novo->info = info;
    novo->prox = NULL;
    novo->ant = NULL;
  }
  return novo;
}//retorna nó preenchido

struct double_linked{
  struct no *inicio;
  struct no *fim;
};//estrutura da lista

TDList* TDList_create(){
  TDList* nova = (TDList*) malloc(sizeof(TDList));
  if(nova){
    nova->inicio = NULL;
    nova->fim = NULL;
  }
  return nova;
}//criar a lista que inicialmente estára vazia


void TDList_destroy(TDList* list){
  for(;list->inicio != NULL;){
    TNo* aux = list->inicio;
    list->inicio = list->inicio->prox;
    free(aux);
  }free(list->inicio);
}//aqui está indo nó a nó dando free
  

void TDList_insert(TDList* lista, int info){
  TNo* novo = TNo_createnfill(info);
  if(lista->inicio == NULL){
      lista->inicio = novo;
      lista->fim = novo;
  }else{
    novo->ant = lista->fim;
    lista->fim->prox = novo;
    lista->fim = novo;
  }
}//uma função criada por mim para add um nó no final da lista

void TDList_insert_inicio(TDList* lista, int info){
  TNo* novo = TNo_createnfill(info);
  if(lista->inicio == NULL){
      lista->inicio = novo;
      lista->fim = novo;
  }else{
    novo->ant = NULL;
    novo->prox = lista->inicio;
    lista->inicio->ant = novo;
    lista->inicio = novo;
  }
}//uma função criada por mim para add um nó no inicio da lista
void TDList_print(TDList* list){
  if(list){
    struct no* aux = list->inicio;
    while(aux){
      printf("%d", aux->info);
      aux = aux->prox;
    }
    puts("");
  }
}//função para imprimir a lista
TDList* TDList_generate(char* charNum){
  TDList* ListaEncadiada = TDList_create();//criando uma lista vazia
  int tam = strlen(charNum);//pego o tamanho da string recebida
  for(int i = 0; i < tam-1;i++){
    //tamanho -1 pq tem um espaço em branco no final da string e eu add um espaço na ultima linha do input.txt para ficar igual aos outros.
    TDList_insert(ListaEncadiada, (int)*(charNum+i)-'0');//aqui eu forço uma converção de char para int e passo para a função que vai criar um nó e add na lista
  }
  return ListaEncadiada;//reorno uma lista duplamente encadeada com valores inteiros representados pela string recebida
}
TDList* TDList_sum(TDList* l1, TDList* l2){
  TDList* ListSum = TDList_create();//crio uma lista vazia
  struct no* aux1 = l1->fim;//crio um nó auxiliar para apontar para o final da minha primeira lista
  struct no* aux2 = l2->fim;//crio um nó auxiliar para apontar para o final da minha segunda lista
  int sair = 1,carry = 0, n1,n2,soma,resto;//declaro e inicializo minhas variaveis locais
  while (sair == 1){
    n1 = aux1 -> info;//guarda o ultimo valor da lista 1 mas será alterado conforme o laço de repetição
    n2 = aux2 -> info;//guarda o ultimo valor da lista 2 mas será alterado conforme o laço de repetição
    soma = n1 + n2;//faço a soma dos dois ultimos valores
    if(soma+carry <= 9){
      //se a soma de n1 e n2 mais a carry for menor que 9 será add no inicio da lista e não vou passar carry para o proximo
      TDList_insert_inicio(ListSum,soma+carry);
      carry = 0;
    }else{
      resto = soma+carry - 10;//como foi maior que 9 subtrio 10 add no inicio da lista e vou passar 1 de carry pro proximo
      TDList_insert_inicio(ListSum,resto);
      carry = 1;
    }
    if(aux1->ant == NULL || aux2 ->ant == NULL){
      //aqui se uma das lista chegar ao fim saio do laço de repetição
      sair = 0;
    }else{
      //vou andar para o anteriores das minhas listas
      aux1 = aux1 -> ant;
      aux2 = aux2 -> ant;
    }
  }
  //se saiu do laço uma das lista chegou ao fim isso não significa que as duas chegaram ao fim vou verificar se só uma chegou ao fim
  if(aux1->ant != NULL){
     //se entrar aqui a minha lista 1 não chegou ao fim assim vou terminar de somar o resto da minha lista 1
    aux1 = aux1->ant;//pq parou o laço antes de voltar para o anterior
    TDList_insert_inicio(ListSum,aux1->info+carry);//o primeiro após o fim da lista pode ter carry por isso essa linha
    for(;aux1->ant != NULL;){
      aux1 = aux1 -> ant;
      TDList_insert_inicio(ListSum,aux2->info);
    }//o laço vai até o inicio da minha lista 1
  }else if(aux2->ant != NULL){
    //fiz o mesmo processo anterior da linha 116 a 123
    aux2 = aux2->ant;
    TDList_insert_inicio(ListSum,aux2->info+carry);
    for(;aux2->ant != NULL;){
      aux2 = aux2 -> ant;
      TDList_insert_inicio(ListSum,aux2->info);
    }
  }
  //aque se as duas listas chegaram ao fim juntas e sobrou 1 na carry vou add no inicio da lista sum
  if(aux1->ant == NULL && aux2->ant == NULL){
    if(carry == 1){
      TDList_insert_inicio(ListSum,carry);
    }
  }
  return ListSum;//vou retorna a minha lista com a soma
}