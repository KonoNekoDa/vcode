#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LONG 10

void kortspel(char kort[LONG]);
void blanda_kort(char kort[LONG]);

int main() 
{
    srand(time(NULL));
    char kort[LONG] = {'A', 'B', 'C', 'E', 'D', 'A', 'D', 'C', 'E', 'B'};

    blanda_kort(kort);
    kortspel(kort);

    return 0;
}

void kortspel(char kort[LONG]) 
{
    int val1, val2;
    int kvar[LONG] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int attempts = 0;
    int foundPairs = 0;

    while (foundPairs < LONG / 2) 
    {
        printf("Kort: ");
        for (int i = 0; i < LONG; i++) 
        {
            if (kvar[i] != 0) 
            {
                printf("%d ", kvar[i]);
            }
        }
        printf("\n");

        int controll = 1;
        while (controll) 
        {
            printf("Vilka kort vill du valja? ");
            scanf("%d %d", &val1, &val2);

            
            if (val1 < 1 || val1 > LONG || val2 < 1 || val2 > LONG || val1 == val2 || kvar[val1 - 1] == 0 || kvar[val2 - 1] == 0) 
            {
                printf("Felaktigt val\n");
                continue;
            }

            attempts++;

            printf("Du fick %c och %c\n", kort[val1 - 1], kort[val2 - 1]);

            if (kort[val1 - 1] == kort[val2 - 1]) {
                printf("Du fick paret %c\n", kort[val1 - 1]);
                kvar[val1 - 1] = 0; 
                kvar[val2 - 1] = 0; 
                foundPairs++;
            }
            controll = 0; 
        }
    }

    printf("Du anvande %d turer\n", attempts);
}

void blanda_kort(char kort[LONG]) 
{
    int bomba;
    char temp;
    for (int i = LONG - 1; i > 0; i--) 
    {
        bomba = rand() % (i + 1);
        temp = kort[i];
        kort[i] = kort[bomba];
        kort[bomba] = temp;
    }
}