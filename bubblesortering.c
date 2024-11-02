#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10
int main()
{
    int v[LENGTH];
    srand(1);
    int i;
    for(i=0;i<LENGTH;i++)
    {
        v[i]=rand()%20;
    }
    for(i=0;i<LENGTH;i++) printf("%d,",v[i]);
    {
        printf("\n");
    }
    int j,tmp;
    for(i=0;i<LENGTH -1;i++)
    {
        for(j=0;j<LENGTH -1-i;j++)
        {
            if(v[j]>v[j+1])
            {
                tmp=v[j];
                v[j]=v[j+1];
                v[j+1]=tmp;
            }
        }
    }
    for(i=0;i< LENGTH;i++) printf("%d,",v[i]);
    {
        printf("\n");
    }
}



// #define NULL=0
// int main()
// {
//     int tmp,length,i,j,v;
//     for(i=0;i<length-1;i++)
//     {
//         for(j=0;j<length-1-i;j++)
//         {
//             if(v[j]>v[j+1])
//             {
//                 tmp=v[j];
//                 v[j]=v[j+1];
//                 v[j+1]=tmp;
//             }
//         }
//     }
// }