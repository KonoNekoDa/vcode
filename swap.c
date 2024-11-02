#include <stdio.h>

int main()
{
    int a, b, tmp;
    printf("Ange a: ");
    scanf("%d",&a);
    printf("Ange b: ");
    scanf("%d",&b);
    tmp=a;
    a=b;
    b=tmp;
    printf("a: %d, b: %d",a,b);
}

