#ifndef DUPLAMENTE_LISTA
#define DUPLAMENTE_LISTA

//apaguei seus comentarios para ficar mais limpo pq aqui é só tem as definição.
typedef struct double_linked TDList;
typedef struct no TNo;

TDList* TDList_create();
void TDList_destroy(TDList*);

void TDList_insert(TDList* lista, int info);

void TDList_insert_inicio(TDList* lista, int info);

TDList* TDList_generate(char*);

TDList* TDList_sum(TDList*, TDList*);

void TDList_print(TDList*);

#endif