#include <stdio.h>

int main()
{
    char weekday;
    printf("Mata in veckodagnummer 1-7: ");
    scanf("%d", &weekday);
    switch(weekday)
    {
        case 1: printf("Monday\n");
        break;
        case 2: printf("Tuesday\n");
        break;
        case 3: printf("Wednesday\n");
        break;
        case 4: printf("Thursday\n");
        break;
        case 5: printf("Friday\n");
        break;
        default: printf("Weekend!\n");
    }
    
}
