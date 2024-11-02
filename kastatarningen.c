#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAXTARNING 100
#define MAXKAST 1000

void tarningsspel(int tarningskast,int tarning);
void kastatarning(int tarningskast,int tarning, int tarningsres[]);
void printresultat(int tarning, int tarningsres[], int tarningskast);
void sortera(int sorterad [], int tarningsres[], int tarningskast);

int main()
{
    srand(time(NULL));
    int tarningskast=1,tarning=1;
    tarningsspel(tarningskast,tarning);
}

void tarningsspel(int tarningskast,int tarning)
{

    printf("Ange antal tarningar som skall kastas: ");
    scanf("%d",&tarning);

    printf("Ange antal ganger de skall kastas(max 1000):");
    scanf("%d",&tarningskast);
   

    int tarningsres[tarningskast];

    kastatarning(tarningskast, tarning, tarningsres);

    printresultat(tarning, tarningsres, tarningskast);
    
}

void kastatarning(int tarningskast,int tarning, int tarningsres[])
{   
    for (int i = 0; i < tarningskast; i++)
    {
        int temp=0;
        for (int j = 0; j < tarning; j++)
        {
            temp += rand()% 6+1;
        }
        tarningsres[i]=temp;
    }
}


void printresultat(int tarning, int tarningsres[], int tarningskast)
{
    int sorterad[tarningskast];
    sortera(sorterad,tarningsres,tarningskast);
    if(tarningskast<=20)
    {
        printf("Resultaten blev: ");
        for (int i = 0; i < tarningskast; i++)
        {
            printf("%d, ",tarningsres[i]);
        }
        printf("\n");

        printf("Resultaten blev: ");
        for (int i = 0; i < tarningskast; i++)
        {
            printf("%d, ",sorterad[i]);
        }
        printf("\n");
    }
    float medel=0;
   if (tarningskast % 2 == 0)
    {
        medel = (sorterad[tarningskast / 2] + sorterad[(tarningskast / 2) - 1]) / 2.0;
    }
    else
    {
        medel = sorterad[tarningskast / 2];
    }


    printf("medeianen: %1.f",medel);
}

void sortera(int sorterad[], int tarningsres[], int tarningskast)
{
    for (int i = 0; i < tarningskast; i++)
    {
        sorterad[i] = tarningsres[i];
    }

    int temp;
    bool byte;
    
    for (int i = 0; i < tarningskast - 1; i++)
    {
        byte = false;
        for (int j = 0; j < tarningskast - 1 - i; j++)
        {
            if (sorterad[j] > sorterad[j + 1])
            {
                temp = sorterad[j];
                sorterad[j] = sorterad[j + 1];
                sorterad[j + 1] = temp;
                byte = true;
            }
        }
        
        if (!byte)
        {
            break;
        }
    }
}
