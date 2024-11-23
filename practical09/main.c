#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magicsquare.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){  

    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter your file name: ");
    scanf("%s", filename);
    
    int n = getlines(filename);

    f = fopen(filename, "r");

    int i;

    int **msquare = (int **)malloc(n * sizeof(int *));
    for ( i = 0; i < n; i++)
    {
        msquare[i] = (int *)malloc(n*sizeof(int));
    }
    int j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            fscanf(f, "%d", &msquare[i][j]);
        }
        
    }

    int magicSquare = isMagicSquare(msquare, n);

    if(magicSquare == 0){
        printf("This is not magic square\n");
    }else{
        printf("This is magic square!\n");
    }
    
    for ( i = 0; i < n; i++)
    {
        free(msquare[i]);
    }
    free(msquare);

    fclose(f);

    return 0;
}  

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No: of lines = %d\n", count);
    fclose(fp); 
    return count;
}