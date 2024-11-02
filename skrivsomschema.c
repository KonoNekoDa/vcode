#include <stdio.h>

int main()
{
    int a=100, b=1;

    while(a>b)
    {
        printf("a= %d, b= %d\n",a,b);

        if(a/b>20)
        {
            a/=2;
        }
        else
        {
            while(b < a / 2)
            {
                b++;
                printf("a= %d, b= %d\n",a,b);

            }
            b++;
        }
        
    }

    printf("Bombaclat det ar a= %d, b= %d\n",a,b);
}