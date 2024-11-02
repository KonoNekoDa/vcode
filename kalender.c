#include <stdio.h>

int main()
{
    int nrofdays, firstday;
    printf("Mur manga dagar ar det i manaden? ");
    scanf("%d",&nrofdays);

    do
    {
        printf(" vilken veckodag ar det den forstadagen i monaden(1-man, 2-tis,....): ");
        scanf("%d",&firstday);
    } while (firstday<1||firstday>7);

    printf("   m   ti   o   to   f   l   s\n");
   
   for( int i=1;i<firstday; i++)
    {
        printf("   ");
    }
    int currentpostion=0;
    for(int currentday=1;currentday<=nrofdays;currentday++)
    {
        printf("%3d",currentday);
        currentpostion++;
        if(currentpostion>7)
        {
            currentpostion=1;
            printf("\n");
        }
    }
    
    

    return 0;
    
}