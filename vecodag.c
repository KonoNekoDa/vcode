#include <stdio.h>

int main()
{
    int dag, dagar, vilken;
    char array[][7] = {"mondag", "tisdag", "onsdag", "torsdag", "fredag", "lordag", "sondag"};

    printf(" vilken veckodag ar det(1-man, 2-tis,....): ");
    scanf("%d",&dag);

    if (dag<1||dag>7)
    {
        printf("veckodagarna gar fran 1-7 skriv ett nummer inom intervallet!!\n");
        return 0;

    }

    printf("ange antal dagar: ");
    scanf("%d",&dagar);

    if (dagar<0)
    {
        printf("ange bara posetiva dagar framover!!");
        return 0;
    }

   for( int i=0;i<dagar; i++)
    {
        dag++;
        if(dag>7)
        {
            dag=1;
        }
    }

    printf("Det om %d kommer det vara en %s \n", dagar , &array[dag-1]);
}