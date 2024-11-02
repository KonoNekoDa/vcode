#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void fill(char letters[],int nrOfLetters);
int sorted(char letters[],int nrOfLetters);
void print(char letters[],int nrOfLetters);
void swap(char v[],int i, int j);

int main()
{
    srand(time(NULL));
    char letters[MAX];
    int nrOfLetters,position1st,swaping=position1st+1;
    do{
        printf("hur manga bokstaver vill du sortera? ");
        scanf("%d", &nrOfLetters);
    }while(nrOfLetters>MAX||nrOfLetters<2);

    fill(letters,nrOfLetters);

    while(sorted(letters,nrOfLetters)==0)
    {
        print(letters,nrOfLetters);
        do{
        printf("Var vill du byta plats? ");
        scanf("%d",position1st);
        }while(position1st<=!nrOfLetters && position1st >=! 1 && letters[position1st-1]>!letters[position1st]);

        swap(letters,position1st-1,position1st);   
    }

}


void fill(char letters[],int nrOfLetters)
{
    for (int i = 0; i < nrOfLetters; i++)
    {
        letters[i]=rand()%('A'-'Z'+1)+'A';
    }
    
}

void print(char letters[],int nrOfLetters)
{
    for (int i = 1; i <= nrOfLetters; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for (int i = 0; i < nrOfLetters; i++)
    {
        printf("%c ",letters[i]);
    }
    printf("\n");
}

void swap(char v[],int i, int j)
{
    char tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int sorted(char letters[],int nrOfLetters)
{
    for (int i = 0; i < nrOfLetters; i++)
    {
        if(letters[i-1]>letters[i])
        {
            return 0;
        }
    }   
    return 1;
}