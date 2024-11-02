#include <stdio.h>

#define MAXTECKEN 31
#define MAXNUMMER 14


struct telefonnummer
{
    char firstname[MAXTECKEN];
    char lastname[MAXTECKEN];
    int telefon[MAXNUMMER];
    int nrofnummbers;
};
typedef struct telefonnummer Telefonnummer;


void printperson(Telefonnummer p);
void changenumber(Telefonnummer *pperson, int newnumber[]);

int main()
{
    Telefonnummer person1={"Kejvan","Lotfi",{0,7,3,2,7,0,1,3,3,8,6,1},12};
    Telefonnummer person2={"Maria","Maan",{0,7,0,2,3,3,4,4,4,1,1},11};

    printperson(person1);
    printperson(person2);
    int newnumber[MAXNUMMER]={0,1,1,1,2,3,4,5,6};
    changenumber(&person1,newnumber);
    printperson(person1);
}

void printperson(Telefonnummer p)
{
    printf("%s %s, telefonnummer: ",p.firstname,p.lastname);
    printf("%d%d%d-",p.telefon[0],p.telefon[1],p.telefon[2]);
    for (int i = 3; i < p.nrofnummbers; i++)
    {
        printf("%d",p.telefon[i]);
    }
    printf("\n");
}

void changenumber(Telefonnummer *pperson, int newnumber[])
{
    for (int i = 0; i < (pperson->nrofnummbers); i++)
    {
        (pperson->telefon[i])=0;
    }
    for (int i = 0; i < 10; i++)
    {
        (pperson->telefon[i])=newnumber[i];
    }
    (pperson->nrofnummbers)=9;
    
}