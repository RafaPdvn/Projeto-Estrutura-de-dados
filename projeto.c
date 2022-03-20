#include "bbt_projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    int fase = 1;
    
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
        imprime_comando(fase);
        //Solicitar comando do usuario

        
        //Mover P
        do{

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

