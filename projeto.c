#include "bbt_projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    int fase = 1;
    char tab[8][8] = {'P',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ','O',};
    
    do(fase ){    
        imprime_tab(tab);
        //Mostrar lista de comandos
        //Solicitar comando do usuario
        //Mover P
        //If(Se P for igual a 7x7){
        // fase + 1
        // P volta para 0x0
        //} 
    }while(fase == 1); //fase != 3 


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
}

