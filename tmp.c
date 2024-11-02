#include <stdio.h>
#include <math.h>
#include <string.h>

int getvalues(int v[], int *n);
void printArray(int v[], int n);
int compute(int v[], int n);
int min(int v[], int n);
int max(int v[], int n);
int average(int v[], int n);
int normalised(int v[], int n);

int main()
{
    int list[10] = {0};
    char choice;
    int counter = 0;
    printf("Measurement Tool 2.0\n");
    
    while (1)
    {
        printf("VECRQ? ");
        scanf(" %c", &choice);
        
        switch (choice)
        {
            case 'v':
                printArray(list, counter);
                break;
            case 'e':
                getvalues(list, &counter);
                break;
            case 'c':
                compute(list, counter);
                break;
            case 'r': list[10]=0,counter=0;
                break;
            case 'q':
                printf("Exit Measurement Tool!\n");
                return 0; 
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

void printArray(int v[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int getvalues(int list[], int *counter)
{   
    int i = *counter;
    int oneMeasurement;
    int readInteger;

    while (1)
    {
        printf("Enter measurement #%d (or any letter to quit): ", i + 1);
        readInteger = scanf("%d", &oneMeasurement);
        
        if (readInteger)
        {
            if (i < 10) 
            {
                list[i] = oneMeasurement;
                i++;
            }
            else
            {
                printf("List is full. Maximum 10 measurements allowed.\n");
                break; 
            }
        }
        else
        {
            char tmp;
            scanf(" %c", &tmp);
            break; 
        }
    }
    *counter = i;
}

int compute(int list[], int counter)
{
    min(list, counter);
    max(list, counter);
    average(list, counter);
    normalised(list, counter);
    
    
}

int min(int v[], int n)
{
    int min = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    printf("Min value: %d\n", min);
}

int max(int v[], int n)
{
    int max = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    printf("Max value: %d\n", max);
}

int average(int v[], int n)
{
    float avr = 0;
    for (int i = 0; i < n; i++)
    {
        avr += v[i];
    }
    printf("Avr value: %.2f\n", avr / n);
    return avr;
}

int normalised(int v[], int n)
{
    float avr = 0;
    for (int i = 0; i < n; i++)
    {
        avr += v[i];
    }
    avr /= n;
    printf("[ ");
    for (int f = 0; f < n; f++)
    {
        printf("%.0f ", v[f] - round(avr));
    }
    printf("]\n");
}
