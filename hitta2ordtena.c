#include <stdio.h>
#include <string.h>

#define MAXORD 20
#define MAXTECKEN 30

void printOrd(char ord[][MAXTECKEN],int nrOfOrd);
int angeord(char ord[][MAXTECKEN],int *pnrOfOrd);

int main()
{
    char ord[MAXORD][MAXTECKEN];
    int nrOfOrd=0;
    while(1)
    {
        if(!angeord(ord,&nrOfOrd))break;
        printOrd(ord,nrOfOrd);
    }
    printf("avslutar\n");
}


void printOrd(char ord[][MAXTECKEN],int nrOfOrd)
{
    while(1)
    {
        char bokstav;
        printf("Ange bokstav (* for nya ord): ");
        scanf(" %c",&bokstav);
        if(bokstav == '*')
        {
            break;
        }
        for (int i = 0; i < nrOfOrd; i++)
        {
            if(bokstav==ord[i][0])
            {
                printf("%s ",ord[i]);
            }
        }
        printf("\n");
    }
}

int angeord(char ord[][MAXTECKEN],int *pnrOfOrd)
{
    int quit=0;
    printf("Ange ord avsluta med *: ");
    while((*pnrOfOrd<MAXORD))
    {
        while((*pnrOfOrd)<MAXORD)
        {
            scanf(" %s",ord[*pnrOfOrd]);
            if(strcmp(ord[*pnrOfOrd],"*") == 0)
            { 
                break;
            }
            (*pnrOfOrd)++;
            quit = 1;
        }
        return quit;
    }
}
