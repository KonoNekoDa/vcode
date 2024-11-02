#include <stdio.h>

int main()
{
    int max=0,i=1;
    
    printf("Ange tal: ");
    scanf("%d",&max);

    if (max<0)
    {
        printf("ojiltigt tall");
        return 0;
    }

    // while (i<max)
    // {
    //     printf("%d,",i);
    //     i++;
    // }
    // printf("%d",max);

    for (i=0; i<max; i++)
    {
        printf("%d,",i);
    }
    printf("%d",max);

}