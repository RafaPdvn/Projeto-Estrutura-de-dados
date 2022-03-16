
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
}

