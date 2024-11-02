

int main()
{
     int guess=0,correct=42;

     while(guess != correct)
     { 

        printf("Gissa ett tal: ");
        scanf("%d",&guess);

        if(guess==correct)
        {
            printf("correct! \n");
        }
        else if(guess<correct)
        {
            printf("To low!\n");
        }
        else
        {
            printf("To high!\n");
        }

     }

     printf("grattis\n");
     return 0;
}