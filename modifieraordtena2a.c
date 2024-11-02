#include <stdio.h>
#include <string.h>
#define MAXWORD 15

void modword(char word[], int wordlong);
void printword(char word[], int wordlong);
void wordincert(char word[], int wordlong, int wordpost);
void worddelete(char word[], int wordlong, int wordpost);

int main()
{
    int wordlong=10;

    char word[]={'b','e','r','g','s','k','r','e','v','a'};

    modword(word,wordlong);
}

void printword(char word[], int wordlong)
{
    for (int i = 0; i < wordlong; i++)
    {
        printf("%c",word[i]);
    }
    printf(": ");
    
}

void modword(char word[], int wordlong)
{
    int wordpost;
    char choice, wordchange;

    while(choice != 'e')
    {
        printword(word,wordlong);

        scanf(" %c %d %c",&choice,&wordpost,&wordchange);

        switch (choice)
        {
            case 'i':   

                if(wordlong == MAXWORD)
                {
                    printf("FULL!\n");
                    break;
                }
                else
                {
                    wordlong++;
                    wordincert(word,wordlong, wordpost);
                    word[wordpost]=wordchange;
                    break;
                }

            case 'd':

                if(wordlong == MAXWORD)
                {
                    printf("FULL!\n");
                    break;
                }
                else
                {
                    worddelete(word,wordlong, wordpost);
                    word[wordpost]=wordchange;
                    break;
                }

            case 'c':
                break;

            case 'e': printf("END");
                break;
        }
    }
}

void wordincert(char word[], int wordlong, int wordpost)
{
    if(wordpost > wordlong)
    {
        wordpost=wordlong;
    }
    if(wordpost<0)
    {
        wordpost=0;
    }
    for (int i = wordlong; i > wordpost; i--)
    {
        word[i] = word[i - 1];
    }
}


void worddelete(char word[], int wordlong, int wordpost)
{
    if(wordpost > wordlong)
    {
        wordpost=wordlong;
    }
    if(wordpost<0)
    {
        wordpost=0;
    }
    for (int i = wordpost; i < wordlong - 1; i++)
    {
        word[i] = word[i + 1]; 
    }
    word[wordlong - 1] = '\0';
}
