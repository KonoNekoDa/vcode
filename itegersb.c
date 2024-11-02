#include <stdio.h>

int main()
{
    int big=0, small=0, nummer=0, hur=0, tmp;

    printf("hur många nummer vill du skriva in?: ");
    scanf("%d",&hur);

    for (int i = 0; i < hur; i++)
    {
        printf("skriv in ett nummer: ");
        scanf("%d",&nummer);
        if(i==0)
        {
            small=nummer;
        }
        else if(nummer<small)
        {
            small=nummer;
        }
        else if(nummer>big)
        {
            big=nummer;
        }
        else if(small>big)
        {
            tmp=small;
            small=big;
            big=tmp;
        }
    }
    printf("big: %d \nsmall: %d",big,small);
    return 0;
}