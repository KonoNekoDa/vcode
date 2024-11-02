#include <stdio.h>
#define ROW 3
#define COLUMN 4

int main()
{
    int a[ROW][COLUMN];
    int i,j;
    int count=1;
    for(i=0;i< ROW;i++)
    {
        for(j=0;j< COLUMN;j++)
        {
            a[i][j]=count;
            count++;
        }

    }

    // exempel på print i en matris
    // for(i = 0; i < ROW; i++)
    // {
    //     for (j = 0; j < COLUMN; j++)
    //     {
    //         printf("%d, ",a[i][j]);
    //     }
    // printf("\n");
    // }

}
