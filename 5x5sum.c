#include <stdio.h>

int main()
{
    int absorb[5]={0}, colum[5]={0},row[5]={0},sum1=0,sum2=0;

    for (int i = 0; i < 5; i++)
    {
        printf("enter 5 numbers: ");
        scanf("%d,%d,%d,%d,%d",&absorb[0],&absorb[1],&absorb[2],&absorb[3],&absorb[4]);
        sum1=absorb[0]+absorb[1]+absorb[2]+absorb[3]+absorb[4];
        row[i]=sum1;
        for(int f = 0; f < 5; f++)
        {
            colum[f]+= absorb[f];
        }
    }
    printf("\n");
    printf("rows totals: ");
    for (int i = 0; i < 4; i++)
    {
        printf(" %d,",row[i]);
    }
    printf(" %d\n",row[4]);

    printf("\n");
    printf("colums totals: ");
    for (int i = 0; i < 4; i++)
    {
        printf(" %d,",colum[i]);
    }
    printf(" %d\n",colum[4]);
}
