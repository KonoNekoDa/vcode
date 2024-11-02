#include <stdio.h>
#include <string.h>
#define MAXTECKEN 31

void playguess(char secretword[MAXTECKEN]);
void printsecret(char secretword[MAXTECKEN],char guess, int check[], int nrOfletters);


int main()
{
    char secretword[MAXTECKEN];

    printf("Enter The Seacret Word: ");
    scanf("%s",&secretword);
    
    playguess(secretword);
    
    

}

void playguess(char secretword[MAXTECKEN])
{
    char guess;
    int nrOfletters = strlen(secretword);
    int check[nrOfletters];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            printf("-");
        }
        printf("\n");
    }
    printsecret(secretword, guess, check, nrOfletters);
    while(1)
    {
        printf("guess a letter: ");
        scanf(" %c",&guess);
        printsecret(secretword, guess, check, nrOfletters);

        int wincon=0;
        for (int i = 0; i <= nrOfletters; i++)
        {
            if(check[i]==1)
            {
                wincon++;
            }
        }

        if(wincon==nrOfletters)
        {
            printf("Congratulation you guessed the whole word\n");
            break;;
        }
    }
}

void printsecret(char secretword[MAXTECKEN], char guess, int check[], int nrOfletters)
{
    for (int  i = 0; i < nrOfletters; i++)
    {
        if(secretword[i]==guess||check[i]==1)
        {
            printf("%c",secretword[i]);
            check[i]=1;
        }
        else
        {
            printf("*");
        }
    }
    printf("\n");
}