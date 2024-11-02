#include <stdio.h>

#define MAXTECKEN 21
#define SIZE 8


struct patientuppgifter
{
    char firstname[MAXTECKEN];
    char lastname[MAXTECKEN];
    float temperatur[SIZE];
    int nrOftemp;
}; 
typedef struct patientuppgifter Patientuppgifter;

void printpatient(Patientuppgifter p);
void addtemp(Patientuppgifter *pp1, float newtemp);

int main()
{
    Patientuppgifter p1 = {"Fredrik", "Eber", {38.1, 39.2, 37.9, 37.2},4};

    printpatient(p1);
    addtemp(&p1,36.4);
    printpatient(p1);
}

void printpatient(Patientuppgifter p)
{
    float sum=0, mean=0;

    for (int i = 0; i < p.nrOftemp; i++)
    {
        sum+=p.temperatur[i];
    }

    mean = sum/p.nrOftemp;
    

    printf("%c. %s ",p.firstname[0],p.lastname);

    for (int i = 0; i < p.nrOftemp ; i++)
    {
        printf("%.1f, ",p.temperatur[i]);
    }
    printf("medelvarde %.2f",mean);
    printf("\n");
}

void addtemp(Patientuppgifter *pp1, float newtemp)
{
    if(pp1->nrOftemp<=SIZE)
    {
        pp1->temperatur[pp1->nrOftemp]=newtemp;
        (pp1->nrOftemp)++;
        return;
    }

}