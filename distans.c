#include <stdio.h>

int main()
{
    int tid=0 , hastighet=0 , strecka= 0;
    
    printf("Hur lang tid?: ");
    scanf("%d",&tid);
    printf("hur hog hastighet: ");
    scanf("%d",&hastighet);

    strecka=tid*hastighet;

    printf("streckan som du kommer fardas ar: %d km %d (km/h) \n",strecka,hastighet);
    printf("lycka till pa farden!");
    return 0;
}