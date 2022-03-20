#include "bbt_projeto.h"
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

    char tab[8][8] = {'P','X',' ',' ',' ','X',' ',' ',
                      ' ','X',' ',' ',' ','X',' ',' ',
                      ' ',' ',' ',' ',' ','X',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      'X','X','X',' ','X',' ',' ',' ',
                      ' ',' ',' ',' ','X',' ','X','X',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ','X','X','X',' ','O',};

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
        printf("\nInsira a sequencia de comando para o Player 'P' chegar ao objetivo 'O'\n");
        imprime_comando(fase);
        //Solicitar comando do usuario
        do{
             printf("\nDigite o comando: ");
             scanf("%d", &elem.cmd);
             printf("Digite o numero de vezes que este comando serao executado: ");
             scanf("%d", &elem.vez);
             enfileirar(fila, elem);
             printf("\nDeseja inserir outro comando? 1 p/ sim, 0 p/ nao: ");
             scanf("%d", &ctrl);
         }while(ctrl!=0);
        //Mover P
        do{
            printf("\n|------------------------------|\n\n");
            executar_comandos(fila, fase, tab, plr);
            imprime_tab(tab);
            imprime_player(plr);
            if(tab[7][7] == 'P'){
                printf("Parabens!!! Voc� concluiu a %d� fase\n\n",fase);
                fase++;
                tab[7][7] = 'O';
                tab[0][0] = 'P';
            }
            sleep(10);
        }while(tab[0][0]!='P');
    }while(fase != 1); //fase != 3

    return 0;
}


