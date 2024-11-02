#include <stdio.h>

int main()
{
    int sida=0;
    printf("ange sida (2-30): ");
    scanf("%d",&sida);

    if(sida<2||sida>30)
    {
        printf("felaktigt val");
    }

    
    for (int i = 0; i < sida; i++)
    {
        printf("*");
        
        for (int f = 0; i < f; i++)
        {
            printf("*");
        }
        printf("*\n");   
    }
    
    
    

}