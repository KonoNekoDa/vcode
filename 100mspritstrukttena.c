#include <stdio.h>
#include <string.h>
#define MAXWORD 21
#define MAXTIMES 20
struct runner
{
    char firstName[MAXWORD];
    char lastName[MAXWORD];
    float times[MAXTIMES];
    int nrOfTimes;
};
typedef struct runner Runner;

void printRunner(Runner person1); 
void adTimes(Runner *prunner, float newtime);

int main()
{
    Runner person1 = {"Usain", "Bolt", {10.1, 9.68, 9.58, 11.21, 9.97},5};
    printRunner(person1);
    adTimes(&person1,9.43);
    printRunner(person1);
}

void printRunner(Runner r) 
{
    printf("%s %s\n100m times: ",r.firstName, r.lastName);

    for (int i = 0; i < r.nrOfTimes; i++)
    {
        printf("%.2fs, ",r.times[i]);
    }
    printf("\n");
    
} 

void adTimes(Runner *prunner, float newtime)
{
    if(prunner->nrOfTimes>=MAXTIMES);
    {
        prunner->times[prunner->nrOfTimes]=newtime;
        (prunner->nrOfTimes)++;    
        return;
    }
}