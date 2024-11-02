#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void stickprint(int antal_stickor)
{
    for ( int i = 0; i < antal_stickor; i++)
    {
        printf("|");
    }
    printf("\n");
}


int main() 
{
    int spelare_val, dator_val, antal_stickor = 15;
    

    srand(time(NULL));

    printf("Valkommen till tandsticksspelet.\n");

    while (antal_stickor > 0) 
    {

        stickprint(antal_stickor);

        // Spelarens tur
        printf("Hur manga stickor vill du ta? (1-3) ");
        scanf("%d", &spelare_val);

        
        if (spelare_val < 1 || spelare_val > 3 || spelare_val > antal_stickor) {
            printf("Ogiltigt val! Forsok igen.\n");
            continue;
        }

        antal_stickor -= spelare_val;
        printf("Stickor kvar: %d\n", antal_stickor);

        stickprint(antal_stickor);

       
        if (antal_stickor == 0) {
            printf("Du vann!\n");
            break;
        }

        // Datorns tur

        dator_val= (rand() % 3) +1 ;

        if( dator_val > (antal_stickor))
        {
            dator_val = (antal_stickor);
        }
        printf("Datorn tar %d stickor.\n", dator_val);
        antal_stickor -= dator_val;
        printf("Stickor kvar: %d\n", antal_stickor);

        
        if (antal_stickor == 0) {
            printf("Datorn vann!\n");
            break;
        }
    }

    return 0;
}