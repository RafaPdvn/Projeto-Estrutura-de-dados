#include "bbt_projeto.h"
#include "bbt_filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int fase = 1, ctrl;
    Opc elem;
    Fila *fila;
    fila = (Fila*)malloc(sizeof(Fila));
    inic(fila);
    
    char tab[8][8] = {'P','X','X',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ','O',};

    char plr[3][3] = {' ',' ',' ',
                      ' ','P','>',
                      ' ',' ',' '};

    do{ 
        //Impimir tabuleiro
        printf("\n|------------FASE %d-------------|\n\n", fase);   
        imprime_tab(tab);
        //Imprimir Sentido do Jogador 
        imprime_player(plr);
        //Imprimir Lista de comandos
        printf("Insira a sequência de comando para o Player 'P' chegar ao objetivo 'O'\n");     
        imprime_comando(fase);
        //Solicitar comando do usuario
        do{
            printf("Digite o comando: ");
            scanf("%d", &elem.cmd);
            printf("Digite o número de vezes que este comando será executado: ");
            scanf("%d", &elem.vez);
            enfileirar(fila, elem);
            printf("\nDeseja inserir outro comando? 1 p/ sim, 0 p/ não: ");
            scanf("%d", &ctrl);
        }while(ctrl!=0);
        //Mover P
        do{
            switch (fase){
            case 1:
                switch ((fila->inicio))
                {
                case /* constant-expression */:
                    /* code */
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            if(tab[7][7] == 'P'){
                printf("Parabens!!! Você concluiu a %d° fase\n\n",fase);
                fase++;
                tab[7][7] = 'O';
                tab[0][0] = 'P';
            }
        }while(tab[0][0]!='P'); 
    }while(fase != 1); //fase != 3 


    // printf("|------------FASE %d------------|\n\n", fase);
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("| p |   |   |   |   |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   | X | X | X |   |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   |   |   |   |   |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   |   |   |   | X |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   |   |   |   | X |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   | X |   |   |   |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   | X |   |   |   |   |   |   |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // printf("|   |   |   |   |   |   |   | O |\n");
    // printf("|---|---|---|---|---|---|---|---|\n");
    // testeteste
    return 0;
}

