#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

void printSea(int sea[][SIZE]);
void initiateSea(int sea[][SIZE]);
int fire(int sea[][SIZE]);

int main()
{
    int sea[SIZE][SIZE]={{0}};   //0-sea, 1-boat
    int nrOfHits=0;
    srand(time(NULL));
    initiateSea(sea);
    printSea(sea);
    for (int i = 0; i < 6; i++)
    {
        if(fire(sea))
        {
            nrOfHits++;
            if(nrOfHits==3) break;
            printf("traff\n");
        }
        else
        {
            printf("MISS\n");
        }
    }
    
    // playgame();
    if(nrOfHits==3)
    {
        printf("TRAFF och SANKT!\n");
    }
    else
    {
        printf("MISSLYCKATS\n");
    }
    return 0;
}

void initiateSea(int sea[][SIZE])
{
    int row, col;
    row = rand ()%5+1;
    col = rand ()%3+1;
    sea[row][col] = sea[row][col+1] = sea[row][col+2]=1;
}

void printSea(int sea[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) printf("%d ",sea[i][j]);
        printf("\n");
    }
    
}
int fire(int sea[][SIZE])
{
    int row, col;
    printf("vilken position vill du beskuta? ");
    scanf("%d%d",&row,&col);
    if(row<1||row>5||col<1||col>5) return 0;
    if (sea[row][col]==1)
    {
        sea[row][col]=0;
        return 1;
    }
    return 0;
}