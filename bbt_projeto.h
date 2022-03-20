#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct sOpc{
    int cmd;
    int vez;
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
                break;
            case 2:
                printf("1) |F| |F| \n");
                printf("2) |F| |E| |F|\n");
                printf("3) |D| |F| |F|\n");
                break;
            case 3:
                printf("1) |F| |F| \n");
                printf("2) |F| |E| |F|\n");
                printf("3) |D| |F| |F|\n");
                break;

            default:
                break;
        }
}


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
        }else{
            printf("Impossivel mover nesta dire��o!\n\n");
        }
    }else if(plr[0][1] != ' '){ //Movimenta para Cima
        if((l-1 > 0)&&(tab[l-1][c]!='X')){
            tab[l][c] = ' ';
            tab[l-1][c] = 'P';
        }else{
            printf("Impossivel mover nesta dire��o!\n\n");
        }
    }else if(plr[1][0] != ' '){ //Movimenta a Esquerda
        if((c-1 > 0)&&(tab[l][c-1]!='X')){
            tab[l][c] = ' ';
            tab[l][c-1] = 'P';
        }else{
            printf("Impossivel mover nesta dire��o!\n\n");
        }
    }else if(plr[2][1] != ' '){ //Movimenta para Baixo
        if((l+1 < 8)&&(tab[l+1][c]!='X')){
            tab[l][c] = ' ';
            tab[l+1][c]= 'P';
        }else{
            printf("Impossivel mover nesta dire��o!\n\n");
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


void executar_comandos(Fila *fila, int fase, char tab[8][8], char plr[3][3]){
    switch (fase){
        //Comandos fase 1
        case 1:
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
            break;
        //Comandos fase 2
        case 2:
            switch ((fila->inicio)->info.cmd){
                case 1:
                    for(int i = (fila->inicio)->info.vez ; i > 0; i--){      
                        D(plr);
                        F(tab,plr);
                        F(tab,plr);
                        E(plr);
                    }
                    desenfileirar(fila);
                    break;
                case 2:
                    for(int i = (fila->inicio)->info.vez ; i > 0; i--){      
                        D(plr);
                        F(tab,plr);
                        E(plr);
                        F(tab,plr);
                    }
                    desenfileirar(fila);
                    break;
                case 3:
                    for(int i = (fila->inicio)->info.vez ; i > 0; i--){      
                        F(tab,plr);
                        F(tab,plr);
                        F(tab,plr);
                    }
                    desenfileirar(fila);
                    break;

                default:
                    break;
            }
            break;
        //Comandos fase 3
        case 3:
            switch ((fila->inicio)->info.cmd){
                case 1:
                    for(int i = (fila->inicio)->info.vez ; i > 0; i--){      
                        F(tab,plr);
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
                        F(tab,plr);
                        E(plr);
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
            break;

            default:
                break;
    }
}





