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

    
    printf("digits:         0   1   2   3   4   5   6   7   8   9\n");
    int found_repeated = 0;  

    printf("ocurrences:     ");
    for (int i = 0; i < 10; i++) 
    {
        if (digit_seen[i]) 
        {
            printf("%d   ",digit_seen[i]);
            found_repeated = 1;
        }
        else
        {
            printf("0   ");
        }
    }

    if (!found_repeated) 
    {
        printf("None");
    }
    printf("\n");

    return 0;
}