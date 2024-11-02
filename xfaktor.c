#include <stdio.h>

int main(void)
{
    int storlek=0, i=0, k=0;
    printf("hur stort ska krysset vara?: ");
    scanf("%d",&storlek);

    for (i = 0; i < (storlek); i++)
    {
        for(k = 0; k < (storlek); k++)
        {
            if(k==i || i==storlek-(k+1))
            {
                printf("*");
            }
            else 
            {
                printf("+");
            }
        }
        printf("\n");

    }
    return 0;

}