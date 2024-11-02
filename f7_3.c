#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    

void printArray(int array[], int length); 
void sortArray(int array[], int length); 
void fillArrayWithRandom(int array[], int length);
int main() 
{
    srand(time(NULL));

    const int length = 10;  
    int array[length];

    fillArrayWithRandom(array, length);

    printf("Array before sorting: ");
    printArray(array, length);

    sortArray(array, length);

    printf("Array after sorting: ");
    printArray(array, length);

    return 0;
}

void sortArray(int array[], int length) 
{
    for (int i = 0; i < length - 1; i++) 
    {
        for (int j = 0; j < length - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void fillArrayWithRandom(int array[], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        array[i] = rand() % 21 - 10;  
    }
}


void printArray(int array[], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
