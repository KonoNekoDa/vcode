#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  NUMBERS 22


void dicethrow(int dicenumbers[]);
void printnumbers(int numbers[NUMBERS]);
void dicegame(int numbers[NUMBERS],int *ppoang);
int switchcontroll(char operator, int dicenumber1, int dicenumber2 ,int *presult);

int main()
{
    srand(time(NULL));
    int poang=0;
    int numbers[NUMBERS];
    for (int i = 0; i < NUMBERS; i++)
    {
        numbers[i]= i;
    }
    
    dicegame(numbers,&poang);

    int check=0;
    for (int i = 0; i < NUMBERS; i++)
    {
        if(numbers[i]=0)
        {
            check++;
        }
    }

    if(check==22)
    {
        printf("du van!!");
    }
    else
    {
        printf("du har forlorat. du fick %d poang",poang);
    }
}

void printnumbers(int numbers[NUMBERS])
{
    printf("Du har foljande siffror kvar\n");
    for (int i = 0; i < NUMBERS ; i++)
    {
        if(numbers[i]!=0)
        {
            printf("%d,",numbers[i]);
        }
    }
    printf("\n");
    
}

void dicegame(int numbers[NUMBERS], int *ppoang)
{
    char operator1, operator2;
    while(1)
    {
        int dicenumbers[3],result=0;
        
        printnumbers(numbers);
        printf("valj raknesatt: ");
        scanf(" %1c%1c",&operator1, &operator2);

        dicethrow(dicenumbers);

        for (int i = 0; i < 3; i++)
        {
            printf("%d ",dicenumbers[i]);
        }
        printf("\n");

        switchcontroll(operator1,dicenumbers[0],dicenumbers[1],&result);
        switchcontroll(operator2,result,dicenumbers[2],&result);

        printf("%d\n",result);

        if(numbers[result]==0||result>21||result<0)
        {
            break;
        }
        else 
        {
            numbers[result]=0;
        }
        (*ppoang)++;
    }

    
}

int switchcontroll(char operator, int dicenumber1, int dicenumber2 ,int *presult)
{

    switch (operator)
        {
            case '+':  *presult=dicenumber1+dicenumber2;
                break; 

            case '-': *presult=dicenumber1-dicenumber2;
                break;

            case '*': *presult=dicenumber1*dicenumber2;
                break;

            case '/': *presult=dicenumber1/dicenumber2;
                break;
        }
}

void dicethrow(int dicenumbers[])
{
    for (int i = 0; i < 3; i++)
    {
       dicenumbers[i]= rand()% 6+1;
    }
}