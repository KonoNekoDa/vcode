#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NROFSIDES 6
int getNrOfThrows();
void throwDice(int frequencyTable[], int nrOfThrows);
void printArray(int v[], int n);
int throwDie();
void fillWithZeros(int v[],int n);
void printTable(int frequencyTable[]);

int main()
{
    int frequencyTable[NROFSIDES+1];
    int nrOfThrows;
    srand(time(NULL));
    nrOfThrows = getNrOfThrows();
    throwDice(frequencyTable,nrOfThrows);
    printTable(frequencyTable);
    return 0;
}

void printTable(int frequencyTable[])
{
    printArray(frequencyTable,NROFSIDES+1);
}

void throwDice(int frequencyTable[], int nrOfThrows)
{
fillWithZeros(frequencyTable,NROFSIDES+1);
    for(int i=0;i<nrOfThrows;i++)
    {
        int dieResult=throwDie();
        frequencyTable[dieResult]++;
    }
}

void fillWithZeros(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        v[i]=0;
    }
}

int throwDie()
{
    return rand()%NROFSIDES+1;
}

void printArray(int v[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d, ",v[i]);
    }
    printf("\n");
}

int getNrOfThrows()
{
    int nrOfThrows;
    printf("Hur manga tarningskast vill du gora? ");
    scanf("%d",&nrOfThrows);
    return nrOfThrows;
}