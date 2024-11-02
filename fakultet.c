#include <stdio.h>

int main()
{
    int tal=1, fakultet=1;
    

    while(tal!=0)
    {

        printf("Ange tall att fakultera: ");
        scanf("%d",&tal);


        if(tal < 0)
        {
            printf("mata in posetiva tal \n");
            return 0;
        }

        if(tal==0)
        {
            printf("avslutar");
            return 0;
        }

        for(int i=1; i<=tal; i++)
        {
            (fakultet=fakultet*i);
        }

        printf("!%d=%d\n",tal,fakultet);

        fakultet=1;
        
    }
}