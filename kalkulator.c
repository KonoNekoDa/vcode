#include <stdio.h>

int main()
{
    float number1, number2, result;
    char operator;
    printf("kalkylator\n");

    printf("ange tal 1: ");
    scanf("%f",&number1);
    printf("ange +, -, * eller /: ");
    scanf("%c",&operator);
    printf("ange tal 2: ");
    scanf("%f",&number2);

    if(operator=="+")
    {
        result= number1 + number2; 
    }
    else if(operator)

    printf("%.4f\n",result);
    return 0;
}