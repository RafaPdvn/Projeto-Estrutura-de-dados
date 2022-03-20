#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct sOpc{
    int cmd,vez;    
}Opc;

typedef struct sNof{
    Opc info;
    struct sNof *prox;
}NOf;

typedef struct sFila{
        NOf *inicio;
        NOf *fim;
}Fila;

void inic(Fila *ptr){
    ptr->inicio = NULL;
    ptr->fim = NULL;
}

int vazio(Fila *ptr){
    if(ptr->inicio == NULL)
        return 1;
    return 0;
}

NOf* aloc(){
    return (NOf*)malloc(sizeof(NOf));
}

void des(NOf *q){
    free(q);
}

void enfileirar(Fila *ptr, Opc elem){
    NOf* novo;
    novo = aloc();
    if(novo != NULL){
        novo->info = elem;
        novo->prox = NULL;

        if(vazio(ptr)){
            ptr->inicio = novo;
            ptr->fim = novo;
        }else{
            (ptr->fim)->prox = novo;
             ptr->fim = novo;
        }
    }else{
        printf("Erro: problema ao alocar\n\n");
    }

}

void desenfileirar(Fila *ptr){
    NOf *aux;
    aux = ptr->inicio;
    if(!vazio(ptr)){
        if(ptr->fim == ptr->inicio){
            ptr->fim = NULL;
            ptr->inicio = NULL;
            printf("Elemento desalocado com sucesso\n\n");
        }else{
            ptr->inicio = aux->prox;
            des(aux);
            printf("Elemento desalocado com sucesso\n\n");
        }
    }else{
        printf("Erro: fila vazia\n\n");
    }

}




