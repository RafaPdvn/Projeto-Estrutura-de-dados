#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct sOpc{
    int cmd;
    int vez;
}Opc;


//Funções Fila
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
        }else{
            ptr->inicio = aux->prox;
            des(aux);
        }
    }
}



//Funções Pilha
typedef struct sNOp{
    Opc info;
    struct sNOp *prox;
}NOp;

void iniciar(NOp** topo){
    topo = NULL;
}

NOp* alocarNo(){
    return(NOp*)malloc(sizeof(NOp));
}

void desalocarNo(NOp *topo){
    free(topo);
}

int vazia(NOp *topo)
{
    if(topo == NULL)
        return 1;
    return 0;
}

void empilhar(NOp** topo, Opc elem){
    NOp *novo;
    novo = alocarNo();
    if(novo != NULL){    
        novo->info.cmd = elem.cmd;
        novo->info.vez = elem.vez;
        novo->prox = *topo;
        *topo = novo;

    }else{
        printf("Problema na alocacao!\n");
    }

}

void desempilhar(NOp** topo){
    if(!vazia(topo)){
        NOp* aux;
        aux = *topo;
        *topo = aux -> prox;
        desalocarNo(aux);
    }else{
        printf("Pilha vazia!\n");
    }
}



//Funções de impressão
void imprime_tab(char tab[8][8]){
    printf("|---|---|---|---|---|---|---|---|\n");
    for(int i = 0; i < 8; i++){
        printf("|");
        for(int j = 0; j < 8; j++){
            printf(" %c |", tab[i][j]);
        }
        printf("\n");
        printf("|---|---|---|---|---|---|---|---|\n");
    }
    printf("\n\n");
}

void imprime_player(char plr[3][3]){
    printf("Sentido do Player:\n");
    for(int i = 0; i < 3; i++){
        printf("|");
        for(int j = 0; j < 3; j++){
            printf(" %c ", plr[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void imprime_comando(int fase){
    printf("\nLista de comandos:\n");
    switch (fase){
            case 1:
                printf("1) |F| |F| \n");
                printf("2) |F| |E| |F|\n");
                printf("3) |D| |F| |F|\n");
                printf("4) |F| |D| \n");
                break;
            case 2:
                printf("1) |D| |F| |F| |E|\n");
                printf("2) |D| |F| |E| |F|\n");
                printf("3) |F| |F| |F|\n");
                printf("4) |E| |D| |E|\n");
                break;
            case 3:
                printf("1) |F| |F| \n");
                printf("2) |D| |F| |F| |F|\n");
                printf("3) |E| |F| \n");
                printf("4) |E| |E| |F| |F|\n");
                break;

            default:
                break;
        }
}



//Funções de comandos de movimentação
void F(char tab[8][8], char plr[3][3]){
    int c, l;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(tab[i][j] == 'P'){
                l = i;
                c = j;
            }
        }
    }

    if(plr[1][2] != ' '){ //Movimenta a Direita
        if((c+1 < 8)&&(tab[l][c+1]!='X')){
            tab[l][c] = ' ';
            tab[l][c+1] = 'P';
        }
    }else if(plr[0][1] != ' '){ //Movimenta para Cima
        if((l-1 > 0)&&(tab[l-1][c]!='X')){
            tab[l][c] = ' ';
            tab[l-1][c] = 'P';
        }
    }else if(plr[1][0] != ' '){ //Movimenta a Esquerda
        if((c-1 > 0)&&(tab[l][c-1]!='X')){
            tab[l][c] = ' ';
            tab[l][c-1] = 'P';
        }
    }else if(plr[2][1] != ' '){ //Movimenta para Baixo
        if((l+1 < 8)&&(tab[l+1][c]!='X')){
            tab[l][c] = ' ';
            tab[l+1][c]= 'P';
        }
    }
}

void E(char plr[3][3]){
    if(plr[1][2] != ' '){
        plr[1][2] = ' ';
        plr[0][1] = '^';
    }else if(plr[0][1] != ' '){
        plr[0][1] = ' ';
        plr[1][0] = '<';
    }else if(plr[1][0] != ' '){
        plr[1][0] = ' ';
        plr[2][1] = 'v';
    }else if(plr[2][1] != ' '){
        plr[2][1] = ' ';
        plr[1][2] = '>';
    }
}

void D(char plr[3][3]){
    if(plr[1][2] != ' '){
        plr[1][2] = ' ';
        plr[2][1] = 'v';
    }else if(plr[2][1] != ' '){
        plr[2][1] = ' ';
        plr[1][0] = '<';
    }else if(plr[1][0] != ' '){
        plr[1][0] = ' ';
        plr[0][1] = '^';
    }else if(plr[0][1] != ' '){
        plr[0][1] = ' ';
        plr[1][2] = '>';
    }
}

void executar_comando1(Fila *fila, char tab[8][8], char plr[3][3]){
    switch ((fila->inicio)->info.cmd){
        case 1:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                F(tab,plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        case 2:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                F(tab,plr);
                E(plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        case 3:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                D(plr);
                F(tab,plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        case 4:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                F(tab,plr);
                D(plr);
            }
            desenfileirar(fila);
            break;
        default:
            break;
    }
}

void executar_comando2(NOp *pilha, char tab[8][8], char plr[3][3]){
    switch (pilha->info.cmd){
        case 1:
            for(int i = pilha->info.vez; i > 0; i--){
                D(plr);
                F(tab,plr);
                F(tab,plr);
                E(plr);
            }
            break;
        case 2:
            for(int i = pilha->info.vez ; i > 0; i--){
                D(plr);
                F(tab,plr);
                E(plr);
                F(tab,plr);
            }
            break;
        case 3:
            for(int i = pilha->info.vez ; i > 0; i--){
                F(tab,plr);
                F(tab,plr);
                F(tab,plr);
            }
            break;
        case 4:
            for(int i = pilha->info.vez ; i > 0; i--){
                E(plr);
                D(plr);
                E(plr);
            }
            break;
        default:
            break;
    }
}

void executar_comando3(Fila *fila, NOp *pilha, int fase, char tab[8][8], char plr[3][3]){
    if(fase = 2){
        switch ((fila->inicio)->info.cmd){
        case 1:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                F(tab,plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        case 2:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                D(plr);
                F(tab,plr);
                F(tab,plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        case 3:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                E(plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        case 4:
            for(int i = (fila->inicio)->info.vez ; i > 0; i--){
                E(plr);
                E(plr);
                F(tab,plr);
                F(tab,plr);
            }
            desenfileirar(fila);
            break;
        default:
            break;
        }   
    }else{
        switch (pilha->info.cmd){
        case 1:
            for(int i = pilha->info.vez; i > 0; i--){
                F(tab,plr);
                F(tab,plr); 
            }
            break;
        case 2:
            for(int i = pilha->info.vez ; i > 0; i--){
                D(plr);
                F(tab,plr);
                F(tab,plr);
                F(tab,plr);
            }
            break;
        case 3:
            for(int i = pilha->info.vez ; i > 0; i--){
                E(plr);
                F(tab,plr);
            }
            break;
        case 4:
            for(int i = pilha->info.vez ; i > 0; i--){
                E(plr);
                E(plr);
                F(tab,plr);
                F(tab,plr);
            }
            break;
        default:
            break;
        }
    }
    
}



