#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

void kodslump(int kod[], int kodnr);
void spel(int kod[], int kodnr);
void printkod(int kod[], int kodnr, int avkodningsforsok[]);
int controll(int kod[],int kodnr,int avkodningsforsok[]);


int main()
{
    srand(time(NULL));
    int kod[MAX]={0};
    int kodnr=2;
    while(kodnr<=MAX)
    {
        spel(kod,kodnr);
        kodnr++;
    }
    
    
}

void spel(int kod[], int kodnr)
{
    
    
    kodslump(kod,kodnr);
    int inmat;
    int avkodningsforsok[MAX];
    for (int i = 0; i < kodnr; i++)
    {
        avkodningsforsok[i]=0;
    }

    for (int i = 0; i < kodnr; i++)
        {
            printf("%d",kod[i]);
        }

    printf("gissa koden\n");

    do{
        printkod(kod,kodnr,avkodningsforsok);

        for(int i=0; i<kodnr; i++)
        {
            scanf("%1d",&avkodningsforsok[i]);
        }

    }while(controll(kod,kodnr,avkodningsforsok)==1);

    
    printkod(kod,kodnr,avkodningsforsok);
    printf("korrekt!\n");

    
}

void kodslump(int kod[], int kodnr)
{

    for (int i = 0; i < kodnr; i++)
    {
        kod[i]=rand()% 9+1;
    }
    
}


void printkod(int kod[], int kodnr, int avkodningsforsok[])
{

    for (int i = 0; i < kodnr; i++)
    {
        if(kod[i]==avkodningsforsok[i])
        {
            printf("%d",kod[i]);
        }
        else 
        {
            printf("*");
        }
    }
    printf(": ");
}

int controll(int kod[],int kodnr,int avkodningsforsok[])
{
    int temp=0;
    for (int i = 0; i < kodnr; i++)
    {
        if(kod[i]==avkodningsforsok[i])
        {
            temp++;
        }
    }   

    if(temp==kodnr)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
