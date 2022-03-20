#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct sOpc{
    int cmd,vez;    
}Opc;

typedef struct sNof{
    int info;
    struct sNof *prox;
}NOf;

typedef struct sFila{
        NO *inicio;
        NO *fim;
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

void enfileirar(Fila *ptr, int elem){
    NO* novo;
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
    NO *aux;
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

void impressaC(Fila *ptr){
    if(!vazio(ptr)){
        NO* aux;
        printf("Numeros:\t");
        while(ptr->inicio != NULL){
            aux = ptr->inicio;
            ptr->inicio = aux->prox;
            printf("%d\t", aux->info);
            des(aux);
        }
        ptr->fim = NULL;
        printf("\n\n");
    }else{
        printf("Erro: fila vazia\n\n");
    }
}



