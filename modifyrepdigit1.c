#include <stdio.h>

int main(void) 
{
    int digit_seen[10] = {0};  
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) 
    {
        digit = n % 10;
        digit_seen[digit]++; 
        n /= 10;
    }

    
    printf("Repeated digit(s): ");
    int found_repeated = 0;  

    for (int i = 0; i < 10; i++) 
    {
        if (digit_seen[i] > 1) 
        {
            printf("%d ", i);
            found_repeated = 1;
        }
    }

    if (!found_repeated) 
    {
        printf("None");
    }
    printf("\n");

    return 0;
}