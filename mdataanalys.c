#include <stdio.h>
#include <math.h>

int getvalues(int v[], int *n);
void printArray(int v[], int n);
void compute(int v[], int n);
int min(int v[], int n);
int max(int v[], int n);
float average(int v[], int n);
void normalised(int v[], int n, float avg, int result[]);
void normalisedprint(int v[],int n);

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
            case 'r': list[10]=0, counter = 0;
                break;
            case 'q':
                printf("Exit Measurement tool\n");
                return 0; 
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

void printArray(int v[], int n)
{
    if (n == 0) 
    {
        printf("No measurements\n");
        return;
    }
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int getvalues(int list[], int *counter)
{   
    int i = (*counter);
    int oneMeasurement;
    int readInteger;

    while (1)
    {
        printf("Enter measurement #%d (or q to quit): ", i + 1);
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
    (*counter) = i;
}

void compute(int list[], int counter)
{
    if (counter == 0) {
        printf("No measurements\n");
        return;
    }

    int minValue = min(list, counter);
    int maxValue = max(list, counter);
    float avrValue = average(list, counter);
    
    printf("Min value: %d\n", minValue);
    printf("Max value: %d\n", maxValue);
    printf("Average value: %.2f\n", avrValue);
    
    int normalisedValues[10];
    normalised(list, counter, avrValue, normalisedValues);
    normalisedprint(normalisedValues,counter);   
}

int min(int v[], int n)
{
    int minValue = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] < minValue)
        {
            minValue = v[i];
        }
    }
    return minValue;
}

int max(int v[], int n)
{
    int maxValue = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maxValue)
        {
            maxValue = v[i];
        }
    }
    return maxValue;
}

float average(int v[], int n)
{
    float avr = 0;
    for (int i = 0; i < n; i++)
    {
        avr += v[i];
    }
    return avr / n;
}

void normalised(int v[], int n, float avg, int result[])
{
    for (int f = 0; f < n; f++)
    {
        result[f] = v[f] - round(avg);
    }
}

void normalisedprint(int normalisedValues[], int n)
{
    printf("[ ");
    for (int i = 0; i < n ; i++) 
    {
        printf("%d ", normalisedValues[i]);
    }
    printf("]\n");
}
