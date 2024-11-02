#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define MAXTECKEN 21

void dicegame(int player1[], int player2[], char playername1[MAXTECKEN], char playername2[MAXTECKEN]);
void dicethrow(int player[], char playername[MAXTECKEN], int *pplaycounter);
void printScore(char playername1[MAXTECKEN], char playername2[MAXTECKEN], int truescore1, int truescore2);
int main() {
    int player1[20] = {0}, player2[20] = {0};
    char playername1[MAXTECKEN], playername2[MAXTECKEN];
    srand(time(NULL));

    printf("Ange spelare 1: ");
    scanf("%s", playername1);  // Corrected to read into playername1
    printf("Ange spelare 2: ");
    scanf("%s", playername2);  // Corrected to read into playername2

    dicegame(player1, player2, playername1, playername2);
}

void dicegame(int player1[], int player2[], char playername1[MAXTECKEN], char playername2[MAXTECKEN]) {
    int playcounter1 = 0, playcounter2 = 0, truescore1=0, truescore2=0;
    while(truescore1!=40||truescore2!=40)
    {
        printScore(playername1, playername2, truescore1, truescore2);
        while (1) 
        {
            dicethrow(player1, playername1, &playcounter1);
            int roundscore1 = 0;  
            for (int i = 0; i < playcounter1; i++) 
            {
                roundscore1 += player1[i];
            }

            if(player1[playcounter1 - 1]==1)
            {
                for (int i = 0; i < playcounter1; i++)
                {
                    player1[i]=0;
                }
                playcounter1=0;
                printf("%s for 1 och har denna omgong 0\n", playername1);
                break;
            }

            printf("%s for %d och har denna omgong %d. Kasta igen (j/n)? ", playername1, player1[playcounter1 - 1], roundscore1);

            char choice;
            scanf(" %c", &choice); 
            if (choice != 'j') 
            {
                truescore1+=roundscore1;
                break;  
            }

        }
        printScore(playername1, playername2, truescore1, truescore2);
        while (1) 
        {
            dicethrow(player2, playername2, &playcounter2);
            int roundscore2 = 0;  
            for (int i = 0; i < playcounter2; i++) 
            {
                roundscore2 += player2[i];
            }

            if(player2[playcounter2 - 1]==1)
            {
                for (int i = 0; i < playcounter2; i++)
                {
                    player1[i]=0;
                }
                playcounter2=0;
                printf("%s for 1 och har denna omgong 0\n", playername2);
                break;
            }

            printf("%s for %d och har denna omgong %d. Kasta igen (j/n)? ", playername2, player2[playcounter2 - 1], roundscore2);

            char choice;
            scanf(" %c", &choice); 
            if (choice != 'j') 
            {
                truescore2+=roundscore2;
                break;  
            }

        }
    }

    if(truescore1<=40)
    {
        printf("%s vinner partiet",playername1);
    }
    else
    {
        printf("%s vinner partiet",playername2);
    }
}

void dicethrow(int player[], char playername[MAXTECKEN], int *pplaycounter) {
    player[*pplaycounter] = rand() % SIDES + 1;
    (*pplaycounter)++;
    
}

void printScore(char playername1[MAXTECKEN], char playername2[MAXTECKEN], int truescore1,  int truescore2) 
{
    printf("%s %dp", playername1, truescore1);
    printf("   %s %dp\n", playername2, truescore2);
}
